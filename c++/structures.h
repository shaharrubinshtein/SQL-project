#pragma once

#include <iostream>

using namespace std;

class pointList
{
	void* info;
	pointList* next;
public:
	pointList(void* info) :info(info), next(NULL) {}
	pointList() :info(NULL), next(NULL) {}
	void insertList(void* info);
	void* operator[](int index);
	int getSize();
	~pointList();
};


class table
{
	pointList* info;
	table* next;

public:
	table(pointList* info) :info(info), next(NULL) {}
	table() :info(NULL), next(NULL) {}

	void insertTable(pointList* info);
	pointList* operator[](int index);
	int getSize();

};



class linkList
{
	void* info;
	linkList* next;
	int getSize();
public:
	linkList() :info(NULL), next(NULL) {}
	linkList(void *info) { if (info != NULL)this->info = info; else info = NULL; next = NULL; }
	void addToList(void* info);
	void* operator[](int x);
	~linkList();


};


class book
{
	int bookId;
	string bookName;
public:
	book(int id, char* bookName) :bookId(id), bookName(bookName) {}
	string getBookName() { return this->bookName; }
	int getBookId() { return this->bookId; }

};