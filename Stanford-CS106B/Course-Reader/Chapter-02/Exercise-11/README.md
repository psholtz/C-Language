Exercise 11
----------- 

Using the **direction.h** interface as an example, design and implement a **calendar.h** interface that exports the **Month** type from Chapter 1, along with the functions **daysInMonth** and **isLeapYear**, which also appear in that chapter. Your interface should also export a **monthToString** funciton that returns the constant name for a value of type **Month**. Test your implementation by writing a main program that asks the user to enter a year and then writes out the number of days in each month of that year, as in the following sample run:

<pre>
Enter a year: 2012
January has 31 days.
February has 29 days.
March has 31 days.
April has 30 days.
May has 31 days.
June has 30 days.
July has 31 days.
August has 31 days.
September has 30 days.
October has 31 days.
November has 30 days.
December has 31 days.
</pre>

--- 

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/