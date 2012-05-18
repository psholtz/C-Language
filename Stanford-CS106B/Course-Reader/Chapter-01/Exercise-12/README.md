Exercise 12 
----------- 

You can also compute pi by approximating the area bounded by a circular arc. 

Consider a quarter circle which has a radius r equal to two inches. From the formula for the area of a circle, you can easily determine that the area of the quarter circle should be pi square inches. You can also approximate the area computationally by adding up the areas of a series of rectangles, where each rectangle has a fixed width and the height is chosen so that the circle passes through the midpoint of the top of the rectangle.

The sum of the areas of the rectangles approximates the area of the quarter circle. The more rectangles there are, the closer the approximation.

For each rectangle, the width *w* is a constant derived by dividing the radius by the number of rectangles. The height *h*, on the other hand, varies depending on the position of the rectangle. If the midpoint of the rectangle in the horizontal direction is given by *x*, the height of the rectangle can be computed using the **sqrt** function to express the distance formula:

<pre>
h = sqrt(r*r - x*x)
</pre>

The area of each rectangle is then simply *h x w*. 

Write a program to compute the area of the quarter circle by dividing it into 10,000 rectangles.

