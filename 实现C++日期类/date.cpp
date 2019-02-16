#include "date.h"

Date::Date(int year, int month, int day)
	:_year(year), _month(month), _day(day)
{
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

int Date::GetMonth(int year, int month) {
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		++arr[2];
	}
	return arr[month];
}

void Date::Dateshow()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date& Date::operator=(Date d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

bool Date::operator==(const Date& d)
{
	if (this->_year == d._year && this->_month == d._month && this->_day == d._day)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator!=(const Date& d)
{
	return !(this == &d);
}

bool Date::operator>(const Date& d)
{
	if (this->_year > d._year || (this->_year == d._year && this->_month > d._month)
		|| (this->_year == d._year && this->_month == d._month && this->_day > d._day))
	{
		return true;
	}
	return false;
}

bool Date::operator>=(const Date& d)
{
	if ((this > &d) || (this == &d))
	{
		return true;
	}
	return false;
}

bool Date::operator<(const Date& d)
{
	if (!(this >= &d))
	{
		return true;
	}
	return false;
}

bool Date::operator<=(const Date& d)
{
	if (!(this > &d))
	{
		return true;
	}
	return false;
}

Date Date::operator+(int day)
{
	if (day < 0)
	{
		return *this - (-day);
	}

	int sum_day = this->_day + day;
	int sum_month = this->_month;
	while (sum_day > GetMonth(this->_year, sum_month))
	{
		sum_day = sum_day - GetMonth(this->_year, sum_month);
		sum_month += 1;
		if (sum_month > 12)
		{
			sum_month -= 12;
			this->_year += 1;
		}
	}
	this->_month = sum_month;
	this->_day = sum_day;
	return *this;
}

Date Date::operator-(int day)
{
	if (day < 0)
	{
		return *this + day;
	}

	int sub_day = this->_day;
	int sub_month = this->_month;
	while ((day - sub_day) > 0)
	{
		day = day - sub_day;
		sub_month -= 1;
		sub_day = GetMonth(this->_year, sub_month);
		if (sub_month == 0)
		{
			sub_month = 12;
			this->_year -= 1;
		}
	}
	this->_day = sub_day - day;
	this->_month = sub_month;
	return *this;
}

Date Date::operator+=(int day)
{
	*this = *this + day;
	return *this;
}

Date Date::operator-=(int day)
{
	*this = *this - day;
	return *this;
}

int Date::operator-(const Date& d)
{
	Date Max(*this);
	Date Min(d);
	int count = 0;
	if (Max < Min)
	{
		Date temp;
		temp = Max;
		Max = Min;
		Min = temp;
	}

	while (Max > Min) 
	{
		++count;
		Min += 1;
	}
	return count;
}

Date Date::operator++()
{
	*this = *this + 1;
	return *this;
}

Date Date::operator--()
{
	*this = *this - 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	tmp -= 1;
	return tmp;
}



Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}

int main()
{
	Date d1(2018, 9, 11);
	Date d2(d1);
	d1 = d1 + 40;
	d1 = d1 - 41;
	d1 += 40;
	d2 += 45;
	int s = d2 - d1;
	cout << s << endl;
	d1.Dateshow();
	return 0;
}












