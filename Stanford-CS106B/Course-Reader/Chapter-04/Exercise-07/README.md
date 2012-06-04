Exercise 7
---------- 

On occasion, publishers find it useful to evaluate layouts and stylistic designs without being distracted by the actual words. To do so, they sometimes typeset sample pages in such a way that all of the original etters are replaced with random letters. The resulting text has the spacing and punctuation struture of the original, but no longer conveys any meaning that might get in the way of the design. The publishing term for text that has been replaced in this way is *greek*, presumably after the old saying "It's all Greek to me", which is itself adapter from a line from *Julius Ceasar*.

Write a program that reads characters from an input file and displays them on the console after making the appropriate random substitutions. Your program should replace every uppercase character in the input by a radom uppercase character and every lowercase character by a random lowercase one. Nonalphabetic characters should remain unchanged. For example, if the input file "Trolius.txt" contains the text from *Trolius and Cressida*, 

<pre>
Ay, Greek; and that shall be divulged well
In characters as red as Mars his heart
Inflamed with Venus:
</pre>

your program should generate output that looks something like this:

<pre>
Ud, Izpvr; szk eroj jymnc kt pagkftlt zxba
Lm havuvndtll eg dgz rt Otly bwk myvvj
Fogyzswt vrva Ciqgc:
</pre>

--- 

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/