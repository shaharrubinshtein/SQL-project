#include "stdafx.h"

#include <iostream>
#include "structures.h"


using namespace std;


void pointList::insertList(void* info)
{
	pointList* ptr = NULL;
	if (this != NULL)
	{
		if (info != NULL)
		{
			if (this->info == NULL)
			{
				this->info = info;
			}
			else
			{
				ptr = this;

				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = new pointList(info);
			}
		}
	}
}

int pointList::getSize()
{
	int count = 0;
	pointList* ptr = NULL;
	if (this != NULL)
	{

		if (this->info != NULL)
		{
			ptr = this;

			while (ptr->next != NULL)
			{
				ptr = ptr->next;
				count++;
			}

			count++;
		}



	}

	return count;

}

void* pointList::operator[](int index)
{
	int count;
	pointList* ptr = NULL;
	if (this != NULL)
	{
		if (this->info != NULL)
		{
			count = 0;
			ptr = this;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
				count++;
			}
			if (index > count)
			{
				cout << "not in arrange" << endl;
				return NULL;
			}
			else
			{
				ptr = this;
				for (int i = 0; i < index; i++)
					ptr = ptr->next;
				return ptr->info;
			}
		}
	}
	return NULL;
}



pointList::~pointList()
{
	pointList* ptr = NULL;
	pointList* ptr2 = NULL;

	if (this != NULL)
	{
		if (this->next != NULL)
		{
			ptr = this->next;
			delete this->info;

			while (ptr->next != NULL)
			{
				delete ptr->info;
				ptr2 = ptr->next;
				delete ptr;
				ptr = ptr2;
			}
			delete ptr->info;
			delete ptr;
		}
	}
}



void table::insertTable(pointList* info)
{
	table* ptr = NULL;
	if (this != NULL)
	{

		if (info != NULL)
		{
			if (this->info == NULL)
			{
				this->info = info;
			}
			else
			{
				ptr = this;

				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = new table(info);

			}

		}
	}
}


pointList* table::operator[](int index)
{
	table* ptr = NULL;
	if (this != NULL)
	{
		int count = 0;
		ptr = this;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			count++;
		}

		if (index > count)
		{
			cout << "out of range" << endl;
			return NULL;
		}
		else
		{
			ptr = this;
			for (int i = 0; i < index; i++)
				ptr = ptr->next;
			return ptr->info;
		}
	}
	return NULL;
}


int table::getSize()
{
	int count = 0;
	table* ptr = NULL;
	if (this != NULL)
	{
		ptr = this;
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
		count++;
	}
	return count;
}


void linkList::addToList(void* info)
{
	linkList* ptr = NULL;
	if (this != NULL)
	{
		if (info != NULL)
		{
			if (this->info == NULL)
				this->info = info;
			else if (this->info != NULL)
			{
				ptr = new linkList(this->info);
				this->info = info;
				ptr->next = this->next;
				this->next = ptr;
			}
		}
	}
}


int linkList::getSize()
{
	int count = 0;
	linkList* ptr = NULL;
	if (this != NULL)
	{
		ptr = this;
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
		count++;
	}
	return count;
}


void* linkList::operator[](int x)
{
	if (this != NULL)
	{
		linkList* ptr = this;
		int count = this->getSize();
		if (count == 0 || x + 1>count)
			return NULL;
		for (int i = 0; i < x; i++)
		{
			ptr = ptr->next;
		}
		return ptr->info;
	}
	return NULL;
}


linkList::~linkList()
{
	if (this != NULL)
	{
		cout << "here" << endl;

		linkList* ptr = NULL;
		if (this->info != NULL)
			delete this->info;
		if (this->next != NULL)
			delete this->next;
	}



}

