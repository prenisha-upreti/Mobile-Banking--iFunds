#include <iostream>
#include <string>
#include "login.h"

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;

extern const string server = "tcp://127.0.0.1:3306";
extern const string username = "sqluser";
extern const string password = "password";




int Login:: confirm_login() {
	 map<string, int> unsuccessfulAttempts;
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::ResultSet* res;
	Login l; 
	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("ifunds");

		
		string username, password;
		bool validLogin = false;
		while (!validLogin) {
			cout << "Enter your username: ";
			cin >> username;
			l.setId(username);
			if (unsuccessfulAttempts[username] >= 5) {
				cout << "Maximum login attempts exceeded for this user." << endl;
				return 0; // Exit the program
			}

			cout << "Enter your password: ";
			cin >> password;
			l.setPW(password);

			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * FROM info WHERE name='" + username + "'AND password='" + password + "'");

			if (res->next()) {
				cout << "Login successful. Welcome, " << res->getString("name") << "!" << endl;
				validLogin = true;
			}
			else {
				cout << "Invalid username or password." << endl;
				// Increment the unsuccessful attempts counter for this user
				unsuccessfulAttempts[username]++;
			}
			delete res;
			delete stmt;
		}
		delete con;
	}

	catch (sql::SQLException e)
	{
		cout << "Couldn't connect to server. Error message. " << e.what() << endl;
		system("pause");
		exit(1);
	}

	return 0;

}

