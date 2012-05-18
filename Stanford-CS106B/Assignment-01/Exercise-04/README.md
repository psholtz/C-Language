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

* Your solution should operate recursively and should use no iterative constructs such as **for** or **while**. It is also inappropriate to call the provided **integerToString** function or any other library function that does numeric conversion.

* The value that you get when you compute n%10 is an integer, and not a character. To convert this integer to its character equivalent you have to add the ASCII code for the character '0' and then cast that value to a **char**. If you then need to convert that character to a one-character string, you can concatenate it with **string()**, as shown here:

<pre>
string() + ch
</pre>

If you are coming from Java, be aware that the Java trick of writing:

<pre>
"" + ch
</pre>

does **not** work in C++ and will result in very strange behavior -- it might return garbage, or just outright crash the program!

* You should think carefully about what the simple cases need to be. In particular, you should make sure that calling **intToString(0)** returns "0" and not the empty string. This fact may require you to add special code to handle this case.