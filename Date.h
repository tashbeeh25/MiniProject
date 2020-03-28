#ifndef _DATE_H_
#define _DATE_H_

using namespace std;

#include <iostream>

class Date
{ public:
    // constructor to initialise private members to a default date
    Date();

    // constructor to initialise private members to values specified by the arguments
    // initialises to a default date if the arguments do not represent a valid date
    Date(int d, int m, int y);

    // sets the private members to be the values of the arguments
    // does nothing if the arguments do not represent a valid date
    void setDate(int d, int m , int y);


    // advance the date by 1 day
	Date& operator++();    // prefix version - should return new value
	Date operator++(int);  // postfix version - should return old value

    // decrement the date by 1 day
    Date& operator--();    // prefix version
    Date operator--(int);  // postfix version

    // new functions; a date d1 is less than a date d2 if d1 occurs before d2
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator<=(const Date&) const;

  private:
    int day, month, year;
    int arr[12] = {31, 28, 29, 31, 30, 30, 31, 31, 30, 31, 30, 31};


  // output date in format dd/mm/yyyy
  friend ostream& operator<<(ostream&, const Date&);

  // new functions
  friend bool operator>(const Date&, const Date&);
  friend bool operator>=(const Date&, const Date&);

};

#endif
