Execise 4 - Implementing Numeric Conversions
-------------------------------------------- 

The **stribl.h** interface exports the following methods for converting between integers and strings:

<pre>
string integerToString(int n);
int stringToInteger(string str);
</pre>

The first function converts an integer into its representation as a string of decimal digits, so that, for example, **integerToString(1729)** should return the string "1729". The second converts in the opposite direction so that calling **stringToInteger("-42")** should return the integer -42.

Your job in this problem is to write the functions **intToString** and **stringToInt** (the names have been shortened to avoid having your implementation conflict with the library version) that do the same thing as their **strlib.h** counterparts but use a recursive implementation. Fortunately, these functions have a natural recursive structure because it is easy to break an integer down into two components using division by 10. This decomposition is discussed on page 42 in the discussion of the **digitSum** function. The integer 137, for example, breaks down into two pieces, as follows:

<pre>
     137
    /   \
   13   7 
  n/10  n%10 
</pre>

In other words, you can peel off the last digit of the number **n** by using division and modulus by 10. If you use recursion to convert the first part to a string and then append the character value corresponding to the final digit, you will get the **string** representing the integer as a whole.

As you work through this problem, you should keep the following points in mind:

