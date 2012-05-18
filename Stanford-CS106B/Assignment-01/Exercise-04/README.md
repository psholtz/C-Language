Execise 4 - Implementing Numeric Conversions
-------------------------------------------- 

The **stribl.h** interface exports the following methods for converting between integers and strings:

<pre>
string integerToString(int n);
int stringToInteger(string str);
</pre>

The first function converts an integer into its representation as a string of decimal digits, so that, for example, **integerToString(1729)** should return the string "1729". The second converts in the opposite direction so that calling **stringToInteger("-42")** should return the integer -42.