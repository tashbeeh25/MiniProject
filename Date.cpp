using namespace std;

#include <iostream>
#include <iomanip>
#include "Date.h"
#include <stdlib.h>


// constructor that initialises private members to a default date
Date::Date()
{
    day = month = year = 0;
}



// constructor that initialises private members to values specified by the arguments .
// initialises to a default date if the arguments do not represent a valid date
Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

// sets the private members to be the values of the arguments
// does nothing if the arguments do not represent a valid date
void Date::setDate(int d, int m, int y)
{
    day = (d>=0 && d<=31) ? d : 0;
    month = (m>=0 && m<=12) ? m : 0;
    year = (y>=0 && y<=2018) ? y : 0;
}

// boolean operator
// if the year, month and day is equals then returns true, else false
bool Date::operator==(const Date &d) const
{
    if (this->year == d.year)
    {
        if (this->month == d.month)
        {
            if(this->day == d.day)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}


//if day, month and year is not equals then returns true or else false
bool Date::operator!=(const Date &d) const
{
    if (this-> year != d.year)
    {
        if (this->month != d.month)
        {
            if (this->day != d.day)
            {
                return true;
            }
        }
    }else
    {
        return false;
    }
};

// if the day, month and year is less than then returns true else false
bool Date::operator<(const Date &d) const
{
    if (this->day < d.day)
    {
        return true;
    }else if(this->day > d.day)
    {
        return false;
    }
    else
    {
        if (this->month < d.month)
        {
            return true;
        }else if(this->month > d.month)
        {
            return false;
        }
        else
        {
            if(this-> year < d.year)
            {
                return true;
            }else if (this-> year > d.year)
            {
                return false;
            }
        }
    }
}


//if the day, month and year us less than or equals to then returns true else false
bool Date::operator<=(const Date &d) const
{
    if(this->day < d.day)
   {
       return true;
   }
   else if(this->day > d.day)
   {
       return false;
   }
   else
   {	if(this->month < d.month)
        {
            return true;
        }
		else if(this->month > d.month)
        {
            return false;
        }
		else
		{
		    if(this->year < d.year )
			{
			    return true;
			}
		else if(this->year == d.year )
		{
		    return true;
        }
		else
        {
            return false;
        }
		}

    }
}

//FRIEND FUNCTIONS

// if d1 is greater than d2 then return true else false
bool operator>(const Date &d1, const Date &d2)
{
    if(d1.day > d2.day)
    {
        return true;
    }
    else if(d1.day < d2.day)
    {
        return false;
    }
    else
    {	if(d1.month > d2.month)
        {
            return true;
        }
 		else if(d1.month < d2.month)
        {
            return false;
        }
 		else
 		{if(d1.year > d2.year)
 		{
 		    return true;
        }
        else
        {
            return false;
        }
 		}
     }
}

//if d1 is greater than or equal to d2 then returns true or else false
bool operator>=(const Date &d1, const Date &d2)
{
    if(d1.day >= d2.day)
    {
        return true;
    }
    else if(d1.day < d2.day)
    {
        return false;
    }
    else
    {	if(d1.month >= d2.month)
        {
            return true;
        }
 		else if(d1.month < d2.month)
        {
            return false;
        }
 		else
 		{
 		    if(d1.year >= d2.year)
 			{
 			    return true;
 			}
 			else
 			{
 			    return false;
 			}
 		}
     }
}


// increment and decrement operators were not attemped.
Date& Date::operator++()
{

    return *this;
}

Date Date::operator++(int)
{
    return *this;
}


Date& Date::operator--()
{
    return *this;
}

Date Date::operator--(int)
{
    return *this;
}


//prints out the date
ostream& operator<<(ostream &x, const Date &d)
{ x << setfill('0') << setw(2) <<  d.day << '/' << setw(2) << d.month << '/' << setw(2) << d.year;
  return x;
}
