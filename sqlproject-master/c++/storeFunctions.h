#pragma once
#include "structures.h"

void showAllBooks(char *argv[]);


void showAllSupplierOpenOrder(char *argv[]);



void orderBookFromSupplier(char *argv[]);


int getBookId(char *argv[]);


void addBookOrder(char *argv[]);

pointList* selectSupplierOfBook(char* argv[], int bookId);


void showAllBooksOnStock(char *argv[]);


void showAllOpenOrders(char *argv[]);


void showAllCustomers(char *argv[]);

void showAllSuppliers(char *argv[]);


void showAllOrdersBetweenDates(char *argv[]);

void showAllGloablDiscountBooks(char *argv[]);

void checkStock(char *argv[]);

void showAllSuppliersOfBook(char *argv[]);

void showAllSalesForBookFromDate(char *argv[]);

void bookCountOfBooksFromDatecustomer(char *argv[]);

void showTopCustomerByQuantityFromDate(char *argv[]);

void showTopSupplierByBookCount(char *argv[]);

void showAllOrderOfBooksBetweenDates(char *argv[]);

void showAllSoldOrderOfBooksBetweenDates(char *argv[]);


void totalDiscountForCustomerFromDate(char *argv[]);

void totalDiscountForStoreInYear(char *argv[]);

void newCustomerFromDate(char *argv[]);


void purchaseAmountFromSupplierBetweenDates(char *argv[]);

void totalSellOfSalesmanBetweenDates(char *argv[]);

void topTenBooksBetweenDates(char *argv[]);



void orderBookFromSupplier(char *argv[]); 
