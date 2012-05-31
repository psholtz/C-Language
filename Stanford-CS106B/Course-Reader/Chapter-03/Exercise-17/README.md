Exercise 17
----------- 

If you played around with codes and ciphers as a child, the odds are good that you at some point used a **cyclic cipher** -- which is often called a **Caesar cipher** because the Roman historian Seutonius records that Julius Caesar used this technique -- in which you replace each letter in the original message by the letter that appears a fixed distance ahead in the alphabet. As an example, suppose that you wanted to encode a message by shifting every letetr ahead three places. In this cipher, each *A* becomes a *D*, *B* becomes *E*, adn so on. If you reach the end of the alphabet, the process cycles to the beginning so that *X* becomes *A*, *Y* becomes *B*, and *Z* becomes *C*.

To implement a Caesar cipher, you should first define a function

<pre>
string encodeCaesarCipher(string msg, int shift);
</pre>

that returns a new string formed by shifting every letter in *str* forward the number of letters indicated by *shift*, cycling back to the beginning of the alphabet if necessary. After you have implemented **encodeCaesarCipher** write a program that generates the following sample run:

<pre>
Enter shift size: 13
Enter a message: This is a secret message.
Encoded message: Guvf vf n frperg zrffntr.
</pre>

Note that the transformation applies only to letters; any other characters are copied unchanged to the output. Moreover, the case of letters is unaffected: lowercase letters come out as lowercase, and uppercase letters come out as uppercase. You should also write your program so that a negative value of shift means that letters are shifted toward the beginning of the alphabet instead of toward the end, as illustrated by the following sample run:

<pre>
Enter shift size: -1
Enter a message: IBM 9000
Encoded message: HAL 9000 
</pre>

--- 

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/