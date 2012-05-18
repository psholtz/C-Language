Exercise 10
----------- 

[![](http://farm6.staticflickr.com/5319/7223746768_cedec95205.jpg)](http://farm6.staticflickr.com/5319/7223746768_cedec95205.jpg)

In 1979, Douglas Hofstadter, Professor of Cognitive Science at the University of Indiana, wrote *Goedel, Escher and Bach* which he described as "a metaphorical fugue on minds and machines in the spirit of Lewis Carroll." The book won the Pulitzer Prize for Literature and has over the years become one of the classics of computer science. Much of its charm comes from the mathematical oddities and puzzles it contains, many of which can be expressed in the form of compute programs. Of these, one of the most interesting concerns the sequence of numbers formed by repeatedly executing the following rules for some positive integer *n*:

* If *n* is equal to 1, you've reached the end of the sequence and can stop.

* If *n* is even, divide it by two.

* If *n* is odd, multiply it by three and add one.

Although it also goes by several other names, this sequence is often called the **hailstone sequence** because the values tend to go up and down before coming back to 1, much as hailstones do in the clouds in which they form.

Write a program that reads in a number from the user and then generates the hailstone sequence from that point, as in the following sample run:

<pre>
Enter a number: 15
15 is odd, so I multiply by 3 and add 1 to get 46
46 is even, so I divide it by 2 to get 23
23 is odd, so I multiply by 3 and add 1 to get 70
70 is even, so I divide it by 2 to get 35
35 is odd, so I multiply by 3 and add 1 to get 106
106 is even, so I divide it by 2 to get 53
53 is odd, so I multiply by 3 and add 1 to get 160
160 is even, so I divide it by 2 to get 80
80 is even, so I divide it by 2 to get 40
40 is even, so I divide it by 2 to get 20
20 is even, so I divide it by 2 to get 10
10 is even, so I divide it by 2 to get 5
5 is odd, so I multiply by 3 and add 1 to get 16
16 is even, so I divide it by 2 to get 8
8 is even, so I divide it by 2 to get 4
4 is even, so I divide it by 2 to get 2
2 is even, so I divide it by 2 to get 1
</pre>

As you can see, this program offers a narrative account of the process as it goes along, much as Hofstadter does in his book. 

One of the fascinating things about the hailstone seuqence is that no one has yet been able to prove that the process always stops. The number of steps in the the process can get very large, but somehow, it always seems to climb back down to one.