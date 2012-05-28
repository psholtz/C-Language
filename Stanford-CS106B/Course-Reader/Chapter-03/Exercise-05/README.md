Exercise 5
---------- 

In most word games, each letter in a word is second according to its piont value, which is inversely proportional to its frequency in English words. In Scrabble(tm), the points are allocated as follows:

<pre>
 1 ==> A, E, I, L, N, O, R, S, T, U
 2 ==> D, G
 3 ==> B, C, M, P
 4 ==> F, H, V, W, Y
 5 ==> K
 8 ==> J, X
 10 ==> Q, z
</pre>

For example, the word **"FARM"** is worth 9 points in Scrabble: 4 for the F, 1 each for the A and the R, and 3 for the M. Write a program that reads in words and prints out their score in Scrabble, not counting any of the other bonuses that occur in the game. You should ignore any characters other than uppercase letters in computing the score. In particular, lowercase letters are assumed to represent blank titles, which can stand for any letter but have a score of 0.

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/