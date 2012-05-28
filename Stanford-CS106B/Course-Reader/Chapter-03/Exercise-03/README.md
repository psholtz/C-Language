Exercise 3
---------- 

Without uisng the built-in string method **substr**, implement a free function **substr(str, pos, n)** that returns the substring of **str** beginning at position **pos** and containing at most *n* characters. Make sure that your function correctly applies the following rules:

* If *n* is missing or greater than the length of the string, the substring should extend through the end of the original string.

* If *pos* is greater than the length of the string, **substr** should call **error** with an appropriate message.

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/