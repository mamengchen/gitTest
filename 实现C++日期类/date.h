#pragma once


#include <assert.h>
#include <iostream>
using namespace std;

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	void Dateshow();
	int GetMonth(int year, int month);
	Date& operator=(Date d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	Date operator+(int day);
	Date operator+=(int day);
	Date operator-(int day);
	Date operator-=(int day);
	int operator-(const Date& d);
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	~Date();
private:
	int _year;
	int _month;
	int _day;
};