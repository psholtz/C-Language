//
//  calendar.h
//

#ifndef calendar_h
#define calendar_h

#include <string>

enum MONTH {
    JANUARY = 1, 
    FEBRUARY, 
    MARCH, 
    APRIL, 
    MAY, 
    JUNE, 
    JULY, 
    AUGUST, 
    SEPTEMBER, 
    OCTOBER, 
    NOVEMBER, 
    DECEMBER
};

/*
 * Function: daysInMonth(int month, int year);
 * -------------------------------------------
 * Return the number of days in the month. Need
 * to supply the year since Feb will change 
 * depending on the year.
 */
int daysInMonth(int month,int year);

/*
 * Function: isLeapYear(int year);
 * -------------------------------
 * Return true if it's a leap year, otherwise no.
 */
bool isLeapYear(int year);

/*
 * Function: monthToString(int month);
 * -----------------------------------
 * Return string representation of the month.
 */
std::string monthToString(int month);

#endif // calendar_h
