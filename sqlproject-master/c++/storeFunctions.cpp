#include "stdafx.h"

#include "storeFunctions.h"

#include <iostream>

#include <ctime>


#include <stdlib.h>

#include <stdio.h>
#include "structures.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/tokenizer.hpp>
#include <string>





using namespace std;



string getBookName(char* argv[], int bookId);





void showAllBooks(char *argv[])
{


	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;


		connection_properties["password"] = argv[2];


		connection_properties["userName"] = argv[1];


		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");











		pstmt = con->prepareStatement("SELECT * FROM book WHERE bookStock>0");
		res = pstmt->executeQuery();

		/* Fetch in reverse = descending order! */
		res->afterLast();
		while (res->previous())
		{
			cout << res->getString("bookName") << endl;
		}
		delete res;

		delete pstmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}



int getBookId(char *argv[])
{
	int count = 1;
	table* head = new table;
	pointList* row = NULL;
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("SELECT * FROM book");
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			row = new pointList;

			row->insertList(new int(res->getInt("bookId")));
			row->insertList(new string(res->getString("bookName")));
			count++;
			head->insertTable(row);
		}
		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	for (int i = 0; i < count - 1; i++)
	{
		cout << i + 1 << ": " << *(string*)head->operator[](i)->operator[](1) << endl;

	}

	int y;
	cout << endl;
	cout << "select number:";
	cin >> y;





	return *(int*)head->operator[](y - 1)->operator[](0);
}




int getSupplier(char* argv[])
{
	int count = 1;
	table* head = new table;
	pointList* row = NULL;
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select * from supplier");
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			row = new pointList;

			row->insertList(new int(res->getInt("supplierId")));
			row->insertList(new string(res->getString("supplierName")));
			row->insertList(new string(res->getString("supplierAddress")));
			count++;
			head->insertTable(row);
		}
		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	for (int i = 0; i < count - 1; i++)
	{
		cout << i + 1 << ": " << *(int*)head->operator[](i)->operator[](0) << ", " << *(string*)head->operator[](i)->operator[](1) << ", " << *(string*)head->operator[](i)->operator[](2) << endl;

	}

	int y;
	cout << endl;
	cout << "select number:";
	cin >> y;
	return *(int*)head->operator[](y - 1)->operator[](0);
}



int salesman(char* argv[])
{
	int count = 1;
	table* head = new table;
	pointList* row = NULL;
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select pepole.id,pepole.fisrtName,pepole.lastName from salesman inner join pepole on pepole.id = salesman.id");
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			row = new pointList;

			row->insertList(new int(res->getInt("id")));
			row->insertList(new string(res->getString("fisrtName")));
			row->insertList(new string(res->getString("lastName")));
			count++;
			head->insertTable(row);
		}
		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	for (int i = 0; i < count - 1; i++)
	{
		cout << i + 1 << ": " << *(int*)head->operator[](i)->operator[](0) << ", " << *(string*)head->operator[](i)->operator[](1) << ", " << *(string*)head->operator[](i)->operator[](2) << endl;

	}

	int y;
	cout << endl;
	cout << "select number:";
	cin >> y;
	return *(int*)head->operator[](y - 1)->operator[](0);



}








int getCustomerId(char *argv[])
{

	int count = 1;
	table* head = new table;
	pointList* row = NULL;
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select * from customer inner join pepole on customer.customerId = pepole.id");
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			row = new pointList;

			row->insertList(new int(res->getInt("customerId")));
			row->insertList(new string(res->getString("fisrtName")));
			row->insertList(new string(res->getString("lastName")));
			count++;
			head->insertTable(row);
		}
		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	for (int i = 0; i < count - 1; i++)
	{
		cout << i + 1 << ": " << *(int*)head->operator[](i)->operator[](0) << ", " << *(string*)head->operator[](i)->operator[](1) << ", " << *(string*)head->operator[](i)->operator[](2) << endl;

	}

	int y;
	cout << endl;
	cout << "select number:";
	cin >> y;





	return *(int*)head->operator[](y - 1)->operator[](0);








}



void addBookOrder(char *argv[])
{
	int order;
	int quantity;
	pointList* info = NULL;

	cout << "select:" << endl;
	cout << "1-add book" << endl;
	cout << "2-order" << endl;

	table* head = new table;
	pointList* row = NULL;

	cin >> order;

	while (order != 2)
	{

		switch (order)
		{
		case 1:
			quantity = 0;
			row = new pointList;
			row->insertList(new int(getBookId(argv)));
			cout << "you select book name: " << getBookName(argv, *(int*)row->operator[](0)) << endl;
			row->insertList(new string(getBookName(argv, *(int*)row->operator[](0))));
			info = selectSupplierOfBook(argv, *(int*)row->operator[](0));
			row->insertList(new string((*(string*)info->operator[](0)).data()));

			row->insertList(new double(*(double*)info->operator[](1)));

			row->insertList(new int(*(int*)info->operator[](2)));

			cout << "Enter quantity:";
			cin >> quantity;
			row->insertList(new int(quantity));
			head->insertTable(row);






			break;
		case 2:
			cout << "order" << endl;
			break;


		}



		cout << "select:" << endl;
		cout << "1-add book" << endl;
		cout << "2-order" << endl;

		cin >> order;


	}





	for (int i = 0; i < head->getSize(); i++)
	{
		cout << "book id:" << *(int*)head->operator[](i)->operator[](0) << "," << *(string*)head->operator[](i)->operator[](1) << ", " << *(string*)head->operator[](i)->operator[](2) << ", " << *(double*)head->operator[](i)->operator[](3) << ", " << *(int*)head->operator[](i)->operator[](4) << ", " << *(int*)head->operator[](i)->operator[](5) << endl;
	}

	string orderLine;
	orderLine.clear();

	int orderId;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");



		struct tm s;
		time_t val;

		time(&val);

		gmtime_s(&s, &val);




		orderLine.append("insert into bookorder(orderDate, orderStatus) values('");
		orderLine.append(to_string(s.tm_year + 1900));
		orderLine.append("-");
		orderLine.append(to_string(s.tm_mon + 1));
		orderLine.append("-");
		orderLine.append(to_string(s.tm_mday));
		orderLine.append("',0)");

		stmt->execute(orderLine.data());

		pstmt = con->prepareStatement("SELECT *FROM    bookOrder	WHERE   orderId = (SELECT MAX(orderId)  FROM bookOrder)");
		res = pstmt->executeQuery();

		/* Fetch in reverse = descending order! */
		res->afterLast();
		while (res->previous())
		{
			orderId = res->getInt("orderId");
		}




		for (int i = 0; i < head->getSize(); i++)
		{
			orderLine.clear();

			orderLine.append("INSERT INTO bookorderline VALUES(");
			orderLine.append(to_string(orderId));
			orderLine.append(",");
			orderLine.append(to_string(*(int*)head->operator[](i)->operator[](0)));
			orderLine.append(",");
			orderLine.append(to_string(*(int*)head->operator[](i)->operator[](4)));
			orderLine.append(",");
			orderLine.append(to_string(*(int*)head->operator[](i)->operator[](5)));
			orderLine.append(",0)");
			stmt->execute(orderLine.data());


		}






		delete res;

		delete pstmt;
		delete con;







	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}














}



string getBookName(char* argv[], int bookId)
{
	string bookName;
	bookName.clear();
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;


		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");

		string order;

		order.clear();

		order.append("SELECT * FROM book WHERE bookId=");
		order.append(to_string(bookId));

		pstmt = con->prepareStatement(order.data());
		res = pstmt->executeQuery();

		/* Fetch in reverse = descending order! */
		res->afterLast();
		while (res->previous())
		{
			bookName.append(res->getString("bookName"));
		}
		delete res;

		delete pstmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}




	return bookName;

}


pointList* selectSupplierOfBook(char* argv[], int bookId)
{
	int count = 1;

	string order;

	order.clear();

	pointList* info = NULL;
	table* head = new table;
	pointList* row = NULL;
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";


		/* Create a connection */
		driver = get_driver_instance();
		//con = driver->connect("tcp://127.0.0.1:3306", user, pw);
		con = driver->connect(connection_properties);
		/* Connect to the MySQL test database */

		stmt = con->createStatement();
		stmt->execute("USE project");

		order.append("SELECT s.supplierName, suppliercatalog.bookPrice, s.supplierId FROM suppliercatalog NATURAL JOIN supplier as s where suppliercatalog.bookId =");
		order.append(to_string(bookId));

		pstmt = con->prepareStatement(order.data());
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			row = new pointList;


			row->insertList(new string(res->getString("supplierName")));
			row->insertList(new double(res->getDouble("bookPrice")));
			row->insertList(new int(res->getInt("supplierId")));
			row->insertList(new int(count));
			count++;
			head->insertTable(row);
		}
		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	for (int i = 0; i < count - 1; i++)
	{
		cout << i + 1 << ": " << *(string*)head->operator[](i)->operator[](0) << " book stock: " << *(double*)head->operator[](i)->operator[](1) << endl;

	}

	int y;
	cout << endl;
	cout << "select supplier:";
	cin >> y;


	cout << endl;

	return (pointList*)head->operator[](y - 1);

}




void showAllBooksOnStock(char *argv[]) {

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");



		pstmt = con->prepareStatement("select b.bookName, bol.bookId  from book as b inner join bookorderline as bol on bol.bookId = b.bookId where bol.currentStock>0 and bol.orderLineStatus = 1 group by bol.bookId");
		res = pstmt->executeQuery();


		res->afterLast();
		while (res->previous())
		{
			cout << res->getString("bookName") << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

}


void showAllOpenOrders(char *argv[])
{
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");



		pstmt = con->prepareStatement("select customerorderline.orderLineId ,pepole.fisrtName, pepole.lastName , customerorderline.lineStatus , customerorder.orderDate from customerorder inner join customerorderline on 	customerorder.orderId = customerorderline.orderId inner join pepole on customerorder.customerId = pepole.id where customerorderline.lineStatus != 1");
		res = pstmt->executeQuery();


		res->afterLast();
		while (res->previous())
		{
			cout << res->getInt("orderLineId") << ", " << res->getString("fisrtName") << ", " << res->getString("lastName") << ", " << res->getInt("lineStatus") << ", " << res->getString("orderDate") << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}




}


void showAllCustomers(char *argv[])
{
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");



		pstmt = con->prepareStatement("select pepole.fisrtName,pepole.lastName,pepole.city,pepole.id from customer inner join pepole on customer.customerId = pepole.id");
		res = pstmt->executeQuery();


		res->afterLast();
		while (res->previous())
		{
			cout << res->getString("fisrtName") << ", " << res->getString("lastName") << ", " << res->getString("city") << ", " << res->getInt("id") << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}




}


void showAllSuppliers(char *argv[])
{
	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");



		pstmt = con->prepareStatement("select * from supplier");
		res = pstmt->executeQuery();


		res->afterLast();
		while (res->previous())
		{
			cout << res->getInt("supplierId") << ", " << res->getString("supplierName") << ", " << res->getString("supplierAddress") << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}



}



void showAllOrdersBetweenDates(char *argv[])
{
	string startDate;
	string endDate;

	startDate.clear();
	endDate.clear();

	cout << "Enter start date" << endl;
	cin >> startDate;
	cout << "Enter end date" << endl;
	cin >> endDate;


	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");



		pstmt = con->prepareStatement("select customerorder.orderId,customerorder.orderDate , sum(customerorderline.price*customerorderline.quantity) as price  from customerorder inner join customerorderline on customerorderline.orderId = customerorder.orderId where customerorder.orderStatus = 1 and customerorder.orderDate >(?) and customerorder.orderDate < (?) group by customerorderline.orderId");

		pstmt->setString(1, startDate.data());
		pstmt->setString(2, endDate.data());

		res = pstmt->executeQuery();


		res->afterLast();
		while (res->previous())
		{
			cout << res->getInt("orderId") << ", " << res->getString("orderDate") << ", " << res->getDouble("price") << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}



}



void showAllGloablDiscountBooks(char *argv[])
{
	string date;
	date.clear();
	cout << "Enter  date" << endl;
	cin >> date;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select pepole.fisrtName,pepole.lastName,gloabldiscount.discountId,gloabldiscount.startDate,gloabldiscount.endDate,book.bookName,gloabldiscount.discountPercentage from gloabldiscount inner join book on book.bookId = gloabldiscount.bookId inner join bookauthor on book.bookId = bookauthor.bookId inner join pepole on pepole.id = bookauthor.authorId where gloabldiscount.startDate < (?) and gloabldiscount.endDate > (?)");
		pstmt->setString(1, date.data());
		pstmt->setString(2, date.data());
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			cout << res->getString("fisrtName") << ", " << res->getString("lastName") << ", " << res->getInt("discountId") << ", " << res->getString("startDate") << ", " << res->getString("endDate") << ", " << res->getString("bookName") << ", " << res->getString("discountPercentage") << endl;
		}
		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}


void checkStock(char *argv[])
{
	int bookId = -1;
	int flag = 0;

	bookId = getBookId(argv);
	cout << "bookid is: " << bookId << endl;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select b.bookName, bol.bookId ,sum(bol.currentStock) as stock from book as b inner join bookorderline as bol on bol.bookId = b.bookId where bol.currentStock>0 and bol.orderLineStatus = 1 and b.bookId=(?)");
		pstmt->setInt(1, bookId);
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			if (res->getInt("bookId") == bookId)
			{
				cout << res->getString("bookName") << ", " << res->getInt("stock") << ", is in stock" << endl;
				flag = 1;
			}

		}

		if (flag == 0)
		{

			cout << "the book is out of stock in the store" << endl;

		}
		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}



}



void showAllSuppliersOfBook(char *argv[])
{
	int bookId = -1;
	int flag = 0;

	bookId = getBookId(argv);
	cout << "bookid is: " << bookId << endl;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select supplier.supplierName,suppliercatalog.bookPrice,book.bookName from suppliercatalog inner join book on suppliercatalog.bookId = book.bookId inner join supplier on suppliercatalog.supplierId = supplier.supplierId where book.bookId=(?)");
		pstmt->setInt(1, bookId);
		res = pstmt->executeQuery();

		res->afterLast();
		while (res->previous())
		{
			cout << res->getString("supplierName") << ", " << res->getDouble("bookPrice") << res->getString("bookName") << endl;
		}


		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}




}




void showAllSalesForBookFromDate(char *argv[])
{
	int bookId = -1;
	int flag = 0;

	bookId = getBookId(argv);
	cout << "bookid is: " << bookId << endl;


	string date;

	date.clear();

	cout << "Enter date" << endl;
	cin >> date;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select sum(customerorderline.quantity) as bookcount,book.bookName from customerorderline inner join bookorderline on customerorderline.bookOrderId = bookorderline.orderId inner join book on book.bookId = bookorderline.bookId where customerorderline.opDate > (?) and book.bookId = (?) group by book.bookId");
		pstmt->setString(1, date.data());
		pstmt->setInt(2, bookId);
		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << res->getString("bookName") << ", " << res->getInt("bookcount") << endl;
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "this book was not sold in the date" << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

}


void bookCountOfBooksFromDatecustomer(char *argv[])
{




	int customerId = -1;
	int flag = 0;

	customerId = getCustomerId(argv);
	cout << "customerId is: " << customerId << endl;


	string date;

	date.clear();

	cout << "Enter date" << endl;
	cin >> date;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select pepole.id,pepole.fisrtName,pepole.lastName, sum(customerorderline.quantity)  as total from customerorderline inner join customerorder on customerorderline.orderId = customerorder.orderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and pepole.id = (?) and customerorderline.opDate > (?) group by pepole.id");
		pstmt->setString(2, date.data());
		pstmt->setInt(1, customerId);
		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << res->getInt("id") << ", " << res->getString("fisrtName") << ", " << res->getString("lastName") << ", " << res->getInt("total") << endl;
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "this book was not sold in the date" << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}






}


void showTopCustomerByQuantityFromDate(char *argv[])
{

	int flag = 0;

	string date;

	date.clear();

	cout << "Enter date" << endl;
	cin >> date;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select pepole.id,pepole.fisrtName, pepole.lastName, sum(customerorderline.quantity) as total  from customerorder inner join customerorderline on customerorder.orderId = customerorderline.orderId inner join bookorderline on customerorderline.bookOrderId = bookorderline.orderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and customerorderline.opDate>(?) group by pepole.id order by total asc");
		pstmt->setString(1, date.data());

		res = pstmt->executeQuery();
		res->afterLast();

		if (res->previous())
		{
			cout << res->getInt("id") << ", " << res->getString("fisrtName") << ", " << res->getString("lastName") << ", " << res->getInt("total") << endl;
		}


		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

}



void showTopSupplierByBookCount(char *argv[])
{



	int flag = 0;

	string date;

	date.clear();

	cout << "Enter date" << endl;
	cin >> date;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select supplier.supplierName,sum(bookorderline.quantity) as total from bookorderline inner join supplier on bookorderline.supplierId = supplier.supplierId where bookorderline.orderLineStatus = 1 and bookorderline.inDate>(?) group by supplier.supplierId order by total asc ");
		pstmt->setString(1, date.data());

		res = pstmt->executeQuery();
		res->afterLast();

		if (res->previous())
		{
			cout << res->getString("supplierName") << ", " << res->getInt("total") << endl;
		}
		else
		{
			cout << "supplier not found" << endl;

		}


		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}



}



void showAllOrderOfBooksBetweenDates(char *argv[])
{

	int flag = 0;

	string startDate;
	string endDate;

	startDate.clear();
	endDate.clear();

	cout << "Enter start date" << endl;
	cin >> startDate;
	cout << "Enter end date" << endl;
	cin >> endDate;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select book.bookName,bookorderline.inDate,bookorderline.quantity,bookorderline.bookCost,bookorderline.orderLineStatus from bookorderline inner join book on book.bookId = bookorderline.bookId where  bookorderline.inDate >(?) and bookorderline.inDate <(?)");
		pstmt->setString(1, startDate.data());
		pstmt->setString(2, endDate.data());

		res = pstmt->executeQuery();
		res->afterLast();

		while (res->previous())
		{
			cout << res->getString("bookName") << ", " << res->getString("inDate") << ", " << res->getInt("quantity") << ", " << res->getDouble("bookCost") << ", order status:" << res->getInt("orderLineStatus") << endl;
		}



		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}





}


void showAllSoldOrderOfBooksBetweenDates(char *argv[])
{
	int flag = 0;

	string startDate;
	string endDate;

	startDate.clear();
	endDate.clear();

	cout << "Enter start date" << endl;
	cin >> startDate;
	cout << "Enter end date" << endl;
	cin >> endDate;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select bookorderline.orderId,book.bookName,bookorderline.inDate from bookorderline inner join book on book.bookId = bookorderline.bookId where bookorderline.orderLineStatus = 1 and bookorderline.quantity != bookorderline.currentStock and bookorderline.inDate >(?) and bookorderline.inDate <(?)");
		pstmt->setString(1, startDate.data());
		pstmt->setString(2, endDate.data());

		res = pstmt->executeQuery();
		res->afterLast();

		while (res->previous())
		{
			cout << res->getInt("orderId") << ", " << res->getString("bookName") << ", " << res->getInt("inDate") << endl;
		}



		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}



}



void totalDiscountForCustomerFromDate(char *argv[])
{
	int customerId = -1;
	int flag = 0;

	customerId = getCustomerId(argv);
	cout << "customerId is: " << customerId << endl;


	string date;

	date.clear();

	cout << "Enter date" << endl;
	cin >> date;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select pepole.id,pepole.fisrtName,pepole.lastName, sum(  (bookorderline.bookCost*1.5*customerorderline.quantity)-(customerorderline.price*customerorderline.quantity)  ) as discount from customerorder inner join customerorderline on customerorder.orderId = customerorderline.orderId inner join bookorderline on bookorderline.orderId = customerorderline.bookOrderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and customerorderline.opDate>(?) and pepole.id = (?) group by customerorder.customerId");
		pstmt->setString(1, date.data());
		pstmt->setInt(2, customerId);
		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << res->getInt("id") << ", " << res->getString("fisrtName") << ", " << res->getString("lastName") << ", " << res->getDouble("discount") << endl;
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "the customer did not get discount" << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}








}



void totalDiscountForStoreInYear(char *argv[])
{


	string date;
	string q1, q2, q3, q4, q5;


	date.clear();

	cout << "Enter year" << endl;
	cin >> date;

	q1.append(date.data());
	q1.append("-1-1");
	q2.append(date.data());
	q2.append("-3-1");
	q3.append(date.data());
	q3.append("-6-1");
	q4.append(date.data());
	q4.append("-9-1");
	q5.append(date.data());
	q5.append("-12-30");

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select  sum(  (bookorderline.bookCost*1.5*customerorderline.quantity)-(customerorderline.price*customerorderline.quantity)  ) as discount from customerorder inner join customerorderline on customerorder.orderId = customerorderline.orderId inner join bookorderline on bookorderline.orderId = customerorderline.bookOrderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and customerorderline.opDate>(?) and customerorderline.opDate<(?)");
		pstmt->setString(1, q1.data());
		pstmt->setString(2, q2.data());
		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << "q1: " << res->getDouble("discount") << endl;

		}
		pstmt = con->prepareStatement("select  sum(  (bookorderline.bookCost*1.5*customerorderline.quantity)-(customerorderline.price*customerorderline.quantity)  ) as discount from customerorder inner join customerorderline on customerorder.orderId = customerorderline.orderId inner join bookorderline on bookorderline.orderId = customerorderline.bookOrderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and customerorderline.opDate>(?) and customerorderline.opDate<(?)");
		pstmt->setString(1, q2.data());
		pstmt->setString(2, q3.data());
		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << "q2: " << res->getDouble("discount") << endl;

		}
		pstmt = con->prepareStatement("select  sum(  (bookorderline.bookCost*1.5*customerorderline.quantity)-(customerorderline.price*customerorderline.quantity)  ) as discount from customerorder inner join customerorderline on customerorder.orderId = customerorderline.orderId inner join bookorderline on bookorderline.orderId = customerorderline.bookOrderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and customerorderline.opDate>(?) and customerorderline.opDate<(?)");
		pstmt->setString(1, q3.data());
		pstmt->setString(2, q4.data());
		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << "q3: " << res->getDouble("discount") << endl;

		}
		pstmt = con->prepareStatement("select  sum(  (bookorderline.bookCost*1.5*customerorderline.quantity)-(customerorderline.price*customerorderline.quantity)  ) as discount from customerorder inner join customerorderline on customerorder.orderId = customerorderline.orderId inner join bookorderline on bookorderline.orderId = customerorderline.bookOrderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and customerorderline.opDate>(?) and customerorderline.opDate<(?)");
		pstmt->setString(1, q4.data());
		pstmt->setString(2, q5.data());
		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << "q4: " << res->getDouble("discount") << endl;
		}


		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

}


void newCustomerFromDate(char *argv[])
{

	string date;



	date.clear();

	cout << "Enter date" << endl;
	cin >> date;



	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select pepole.id,pepole.fisrtName,pepole.lastName,min(customerorderline.opDate) as startdate  from customerorderline inner join customerorder on customerorderline.orderId = customerorder.orderId inner join pepole on pepole.id = customerorder.customerId where customerorderline.lineStatus = 1 and customerorderline.opDate>(?) group by(pepole.id)");
		pstmt->setString(1, date.data());

		res = pstmt->executeQuery();
		res->afterLast();
		while (res->previous())
		{
			cout << res->getInt("id") << ", " << res->getString("fisrtName") << ", " << res->getString("lastName") << ", " << res->getString("startdate") << endl;

		}



		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}


}


void purchaseAmountFromSupplierBetweenDates(char *argv[])
{
	int supplierId = -1;


	supplierId = getSupplier(argv);

	int flag = 0;

	string startDate;
	string endDate;

	startDate.clear();
	endDate.clear();

	cout << "Enter start date" << endl;
	cin >> startDate;
	cout << "Enter end date" << endl;
	cin >> endDate;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select supplier.supplierId,supplier.supplierName , sum(bookorderline.bookCost*bookorderline.quantity) as totalsum from bookorderline inner join supplier on bookorderline.supplierId = supplier.supplierId where supplier.supplierId = (?) and bookorderline.inDate >= (?) and bookorderline.inDate <= (?) group by supplier.supplierId ");
		pstmt->setInt(1, supplierId);
		pstmt->setString(2, startDate.data());
		pstmt->setString(3, endDate.data());

		res = pstmt->executeQuery();
		res->afterLast();

		while (res->previous())
		{
			cout << res->getInt("supplierId") << ", " << res->getString("supplierName") << ", " << res->getInt("totalsum") << endl;
		}



		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}




}


void totalSellOfSalesmanBetweenDates(char *argv[])
{




	int salesmanId = -1;

	salesmanId = salesman(argv);

	int flag = 0;

	string startDate;
	string endDate;

	startDate.clear();
	endDate.clear();

	cout << "Enter start date" << endl;
	cin >> startDate;
	cout << "Enter end date" << endl;
	cin >> endDate;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select pepole.id,sum( customerorderline.price*customerorderline.quantity ) as totalsum from salesman inner join pepole on pepole.id = salesman.id inner join customerorder on customerorder.salesmanId = pepole.id inner join customerorderline on customerorder.orderId = customerorderline.orderId where customerorderline.lineStatus = 1 and pepole.id = (?) and customerorderline.opDate >= (?) and customerorderline.orderId <=(?) group by pepole.id");
		pstmt->setInt(1, salesmanId);
		pstmt->setString(2, startDate.data());
		pstmt->setString(3, endDate.data());

		res = pstmt->executeQuery();
		res->afterLast();

		while (res->previous())
		{
			cout << res->getInt("id") << ", " << res->getDouble("totalsum") << endl;
		}



		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}



}



void topTenBooksBetweenDates(char *argv[])
{



	string startDate;
	string endDate;

	startDate.clear();
	endDate.clear();

	cout << "Enter start date" << endl;
	cin >> startDate;
	cout << "Enter end date" << endl;
	cin >> endDate;

	try {
		sql::Driver *driver;
		sql::Connection *con;

		sql::ConnectOptionsMap connection_properties;

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;

		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		connection_properties["password"] = argv[2];
		connection_properties["userName"] = argv[1];
		connection_properties["userName"] = "root";

		driver = get_driver_instance();
		con = driver->connect(connection_properties);
		stmt = con->createStatement();
		stmt->execute("USE project");

		pstmt = con->prepareStatement("select  book.bookName,sum(customerorderline.quantity) as totalsum from customerorderline inner join bookorderline on customerorderline.bookOrderId = bookorderline.orderId inner join book on book.bookId = bookorderline.bookId where customerorderline.lineStatus = 1 and customerorderline.opDate >= (?) and customerorderline.opDate <= (?) group by book.bookId order by totalsum asc limit 10 ");
		pstmt->setString(1, startDate.data());
		pstmt->setString(2, endDate.data());

		res = pstmt->executeQuery();
		res->afterLast();

		while (res->previous())
		{
			cout << res->getString("bookName") << ", " << res->getDouble("totalsum") << endl;
		}

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}





}



void orderBookFromSupplier(char *argv[])
{

	cout << "hello";





}