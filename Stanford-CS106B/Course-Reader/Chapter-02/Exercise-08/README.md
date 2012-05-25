Exercise 8
---------- 

Although Euclid's algorithm for calculating the greatest common divisor is one of the oldest to be dignified with that term, there are other algorithms that date back many centuries. In the Middle Ages, one of the problems that required sophisticated algorithmic thinking was determining the date of Easter, which falls on the first Sunday after the first full moon following the vernal equinox. Given this definition, the calculation involves interacting cycles of the day of the week, the orbit of the moon, and the passage of the sun through the zodiac. Early algorithms for solving the problem date back to the third century and are fully described in the writings of the eight-century scholar now know as the Venerable Bede.

In 1800, the German mathematician Carl Friedrich Gauss published an algorithm for determining the date of Easter that was purely computational in the sense that it relied on arithmetic rather than looking up values in tables. His algorithm appears at the link below:

Write a procedure:

<pre>
void findEaster(int year, string &month, int &day);
</pre>

that takes a year and returns the Easter date in the reference parameters **month** and **day**.

---

Notes: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/