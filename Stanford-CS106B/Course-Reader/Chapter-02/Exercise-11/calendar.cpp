//
//  calendar.cpp
//

#include "calendar.h"

/*
 * Function: daysInMonth(int month, int year);
 * -------------------------------------------
 * Return the number of days in the month. Need
 * to supply the year since Feb will change 
 * depending on the year.
 */
int daysInMonth(int month,int year)
{
    switch (month){
        // 31-day months 
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:    
        case AUGUST:
        case OCTOBER: 
        case DECEMBER:           
            return 31;
        
        // 30-day months 
        case APRIL:
        case JUNE:     
        case SEPTEMBER:    
        case NOVEMBER:            
            return 30;
            
        // leap year calc
        case FEBRUARY:
            return isLeapYear(year) ? 29 : 28;
            
        default:
            return 0;
    }
}

/*
 * Function: isLeapYear(int year);
 * -------------------------------
 * Return true if it's a leap year, otherwise no.
 */
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0);
}

/*
 * Function: monthToString(int month);
 * -----------------------------------
 * Return string representation of the month.
 */
std::string monthToString(int month)
{
    switch ( month ) 
    {
        case JANUARY:
            return "January";
        case FEBRUARY:
            return "February";
        case MARCH:
            return "March";
        case APRIL:
            return "April";
        case MAY:
            return "May";
        case JUNE:
            return "June";
        case JULY:
            return "July";
        case AUGUST:
            return "August";
        case SEPTEMBER:
            return "September";
        case OCTOBER:
            return "October";
        case NOVEMBER:
            return "November";
        case DECEMBER:
            return "December";
        default:
            return "";
    }
}