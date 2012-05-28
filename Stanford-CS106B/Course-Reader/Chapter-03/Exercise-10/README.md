Exercise 10
----------- 

Write a function

<pre>
string replaceAll(string str, char c1, char c2);
</pre>

that returns a copy of **str** with every occurrence of **c1** replaced by **c2**. For example, calling

<pre>
replaceAll("nannies",'n','d');
</pre>

should return "daddies".

Once you have coded and tested this function, write an overloaded version

<pre>
string replaceAll(string str, string s1, string s2);
</pre>

that replaces all instances of the string **s1** with the replacement string **s2**.

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/