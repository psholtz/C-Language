Exercise 1
---------- 

The &lt;iomanip&gt; library gives programmers more control over output format, which makes it easy, for example, to create formatted tables. Write a program that displays a table of trigonmetric sines and cosines that looks like this:

<pre>
+-------+------------+------------+
| theta | sin(theta) | cos(theta) |
+-------+------------+------------+
|  -90  | -1.0000000 |  0.0000000 |
|  -75  | -0.9659258 |  0.2588190 |
|  -60  | -0.8660254 |  0.5000000 |
|  -45  | -0.7071068 |  0.7071068 |
|  -30  | -0.5000000 |  0.8660254 |
|  -15  | -0.2588190 |  0.9659258 |
|    0  |  0.0000000 |  1.0000000 |
|   15  |  0.2588190 |  0.9659258 |
|   30  |  0.5000000 |  0.8660254 |
|   45  |  0.7071068 |  0.7071068 |
|   60  |  0.8660254 |  0.5000000 |
|   75  |  0.9659258 |  0.2588190 |
|   90  |  1.0000000 |  0.0000000 |
+-------+------------+------------+
</pre>

The numeric columns should all be aligned on the right, and the columns containing the trigonometric functions (which are listed here for angles in degrees at 15-degree intervals) should all have seven digits after the decimal point.