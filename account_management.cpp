#include "account_management.h"
#include<iostream>
#include <string.h>
#include<conio.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


extern sql::Statement* stmt;
extern sql::ResultSet* res;
 sql::Connection* con;

void account_management::change_email()
{
   
     string username1;
     cout << "enter your username:\t";
     cin >> username1;
	cout << "please enter your current email:\t";
	cin >> temp_email;
    cout << "please enter new email:\t";
    cin >> temp_email1;
    string email1;
    
    // Select data
    
    res = stmt->executeQuery("select * from info where name ='" + username1 + "'"); 
   while (res->next())
    {
        email1 = res->getString("email");
        cout << email1;
    }
        if (email1.compare(temp_email) == 0)
        {
            // Delete data

            stmt->executeUpdate("update info set email  ='" + temp_email1 + "' where name ='" + username1 + "' ");

            delete res;
            delete stmt;
            delete con;

            cout << "\n\t\t\t----------email changed successfully.----------" << endl;

        }
        else {
            cout << "\n\t\t\t----------Invalid email ----------";
        }
    
}

void account_management::change_password()
{
    string username1, temp_pass2;
    cout << "enter your username:\t";
    cin >> username1;
    cout << "please enter your current pass:\t";
    cin >> temp_pass;
    cout << "please enter new pass:\t";
    cin >> temp_pass1;
re:
    cout << "please re-enter new password:\t";
    cin >> temp_pass2;
    if (temp_pass1 == temp_pass2)
    {
        goto change;
    }
    else
    {
        cout << "the re-entered password doesnot match\n";
        goto re;
    }
    

    // Select data
change:
    string pass1;
    res = stmt->executeQuery("select password from info where name ='" + username1 + "'");
    while (res->next())
    {
        pass1 = res->getString("password");
        cout << pass1;
    }
    if (pass1.compare(temp_pass) == 0)
    {
        // Delete data

        stmt->executeUpdate("update info set password  ='" + temp_pass1 + "' where name ='" + username1 + "' ");

        delete res;
        delete stmt;
        delete con;

        cout << "\n\t\t\t----------password changed successfully.----------" << endl;

    }
    else {
        cout << "\n\t\t\t----------Invalid password ----------";
    }

}

void account_management::change_mpin()
{
    string username1;
    int temp_mpin2;
    cout << "enter your username:\t";
    cin >> username1;
    cout << "please enter your current mpin:\t";
    cin >> temp_mpin;

    cout << "please enter new mpin:\t";
    cin >> temp_mpin1;
    re:
    cout << "please re-enter new mpin:\t";
    cin >> temp_mpin2;
    if (temp_mpin1 == temp_mpin2)
    {
        goto change;
    }
    else
    {
        cout << "the re-entered mpin doesnot match\n";
        goto re;
    }
    

    // Select data
change:
    int mpin1;
    res = stmt->executeQuery("select mpin from info where name ='" + username1 + "'");
    while (res->next())
    {
        mpin1 = res->getInt("mpin");
        
    }
   
    
    if (mpin1 == temp_mpin)
    {
        // Delete data
        string mpin2 = to_string(temp_mpin1);
        stmt->executeUpdate("update info set mpin  ='" + mpin2 + "' where name ='" + username1 + "' ");

        delete res;
        delete stmt;
        delete con;

        cout << "\n\t\t\t----------mpin changed successfully.----------" << endl;

    }
    else {
        cout << "\n\t\t\t----------Invalid mpin ----------";
    }
}

int account_management::confirm_emailchange()
{
    try
    {
        

        sql::mysql::MySQL_Driver* driver;
        

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://:3306", "sqluser", "password");
        stmt = con->createStatement();
        stmt->execute("CREATE DATABASE IF NOT EXISTS IFUNDs"); // CREATES DATABASE
        con->setSchema("IFUNDs"); // CALLS DATABASE



        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  change email\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        change_email();
        delete con;
    }
    catch (sql::SQLException& e)
    {
        cout << "Error changing email because of the following reasons:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
    }
}

int account_management::confirm_passchange()
{
    try
    {
       

        sql::mysql::MySQL_Driver* driver;


        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://:3306", "sqluser", "password");
        stmt = con->createStatement();
        stmt->execute("CREATE DATABASE IF NOT EXISTS IFUNDs"); // CREATES DATABASE
        con->setSchema("IFUNDs"); // CALLS DATABASE



        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  change password\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        change_password();
        delete con;
    }
    catch (sql::SQLException& e)
    {
        cout << "Error changing password because of the following reasons:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
    }
}

int account_management::confirm_pinchange()
{
    try
    {


        sql::mysql::MySQL_Driver* driver;


        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://:3306", "sqluser", "password");
        stmt = con->createStatement();
        stmt->execute("CREATE DATABASE IF NOT EXISTS IFUNDs"); // CREATES DATABASE
        con->setSchema("IFUNDs"); // CALLS DATABASE



        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  change transaction pin\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        change_mpin();
        delete con;
    }
    catch (sql::SQLException& e)
    {
        cout << "Error changing mpin because of the following reasons:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
    }
}