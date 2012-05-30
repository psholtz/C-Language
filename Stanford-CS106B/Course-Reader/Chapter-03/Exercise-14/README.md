Exercise 14
----------- 

When large numbers are written out on paper, it is traditional -- at least in the United States -- to use commas to separate the digits into groups of three. For example, the number one million is usually written in the following form:

<pre>
1,000,000
</pre>

To make it easier for programmers to display numbers in this fashion, implement a function:

<pre>
string addCommas(string digits);
</pre>

that takes a string of decimal digits representing a number and returns the string formed by inserting commas at every third position, starting on the right. For example, if you were to execute the main program

<pre>
int main()
{
  while ( true ) {
    string digits = getLine("Enter a number: ");
    if ( digits == "" ) break;
    cout &lt;&lt; addCommas(digits) &lt;&lt; endl;
  }
  return 0;
}
</pre>

your implementation of the **addCommas** function should be able to produce the following sample run:

<pre>
Enter a number: 17
17
Enter a number: 1001
1,001
Enter a number: 12345678
12,345,678
Enter a number: 999999999
999,999,999
</pre>

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/