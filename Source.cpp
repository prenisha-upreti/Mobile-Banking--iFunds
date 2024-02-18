#include <iostream>
#include <string.h>
#include<conio.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <chrono>
#include <thread>
#include "user.h"
#include "Registration.h"


using namespace std::this_thread;
using namespace std;
using namespace std::chrono;

int main()
{
	Registration registers;
	registers.confirm_registration();
	return 0;
}

