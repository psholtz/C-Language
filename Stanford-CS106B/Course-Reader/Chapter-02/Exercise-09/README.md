Exercise 9
----------

The combinations function C(n,k) described in this chapter determines the number of ways you can choose *k* values from a set of *n* elements, ignoring the order of the elements. If the order of the values matter -- so that, in the case of the coin example, choosing a quarter first an then a dime is seen as distinct from choosing a dime and then a quarter -- you need to use a different function, which computes the number of **permutations**. This function is denoted as *P(n,k)* and has the following mathematical formulation:

<pre>
P(n,k) = n! / (n-k)!
</pre>

Although this definition is mathematically correct, it is not well suited to implementation in practice because the factorials involved can get much too large to store in an integer varaible, even when the answer is small. For example, if you tried to use this formula to calculate the number of ways to select two cards from a standard 52-card deck, you would end up trying to evaluate the following fraction:

<pre>
52! / 50!
</pre>

even though the answer is the much more manageable 2625 (52 x 51).

Write a function **permutations(n,k)** that computes the *P(n,k)* function without calling the **fact** function. Part of your job in this problem is to figure out how to compute this value differently. To do so, you will probably find it useful to play around with some relatively small values to get a sense of how the factorials in the numerator and denominator of the formula behave.

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/