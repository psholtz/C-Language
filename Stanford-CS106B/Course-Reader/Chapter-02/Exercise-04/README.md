Exercise 4
---------- 

If you are unfortunate enough to be outside in winter weather, you know that your perception of the cold is dependent on the wind speed as well as the temperature. The faster the wind blows, the colder you feel. To quantify how the wind affects temperature perception, the National Weather Service reports the **wind chill*, which is illustrated on their web site as shown in Figure 2-15. At the bottom of the figure, you can see that the formula for wind chill is:

<pre>

</pre>

where *t* is the Fahrenheit temperature and *v* is the wind speed in miles per hour.

Write a function **windChill** that takes the values of *t* and *v* and returns the wind chill. In doing so, your function should take account of two special cases:

* If there is no wind, **windChill** should return the original temperature *t*.
* If the temperature is greater than 40F, the wind chill is undefined, and your function should call **error** with an appropriate message.

Although it will be easier to do so once you learn how to format numeric data in Chapter 4, you already know enough to generate a table that presents the wind-chill data in columns as shown in Figure 2-15. If you're up for more of a challenge, write a main program that uses **windChill** to produce that table.