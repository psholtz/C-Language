Exercise 3 - Combinations and Pascal's Triangle
----------------------------------------------- 

As you know from Chapter 2, the mathematical combinations function c(n,k) is usually defined in terms of factorials, as follows:

<pre>
c(n,k) = n! / (k! * (n-k)!)
</pre>

The values of c(n,k) can also be arranged geometrically to form a triangle in which *n* increases as you move down the triangle and *k* increases as you move from left to right. The resulting structure, which is called *Pascal's Triangle* after the French mathematician Blaise Pascal, is arranged like this:

<pre>
          c(0,0)
       c(1,0) c(1,1)
   c(2,0) c(2,1) c(2,2)
c(3,0) c(3,1) c(3,2) c(3,3)
</pre>

Pascal's Triangle has the interesting property that every entry is the sum of the two entries above it, except along the left and right edges, where the values are always 1. Consider, for example, the highlighted entry in the following display of Pascal's Triangle:

<pre>
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
   1 5 10 10 5 1
  1 6 |15| 20 15 6 1
1 7 21 35 35 21 7 1
</pre>

This entry, which corresopnds to c(6,2) is the sum of the two entries - 5 and 10 - that appear above it to either side. Using this fact, write a recursive implementation of the c(n,k) function that uses no loops, no multiplication, and no calls to **Fact**.

Write a simple test program to demonstrate that your combinations function works. If you want an additional challenge, write a program that uses c(n,k) to display the first ten rows of Pascal's Triangle.