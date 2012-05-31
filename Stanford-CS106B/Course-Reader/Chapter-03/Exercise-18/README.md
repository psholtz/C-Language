Exercise 18
----------- 

Although they are certainly simple, Caesar ciphers are also extremely easy to break. There are, after all, only 25 values for the number of characters to shift. If you want to break a Caesar cipher, all you have to do is try each of teh 25 possibilities and see which one translates the original message into something readable. A better scheme is to allow each letter in the original message to be represented by an arbitrary letter instead of one of a fixed distance from the original. In this case, the key for the encoding operation is a translation table that shows what each of the 26 letters becomes in the encrypted form. Such a coding scheme is called a *letter-substitution cipher*.

They key in a letter-substitution cipher is a 26-character string that indicates the translation for each character in the alphabet in order. For example, the key "QWERTYUIOPASDFGHJKLZXCVBNM" indicates that the encoding process should use the following translation rule:

<pre>
ABCDEFGHIJKLMNOPQRSTUVWXYZ

|||||||||||||||||||||||||| 

QWERTYUIOPASDFGHJKLZXCVBNM
</pre>

Write a program that implements encryption using a letter-substitution cipher. Your program should be able to duplicate the following sample run:

<pre>
Enter a 26-letter key: QWERTYUIOPASDFGHJKLZXCVBNM
Enter a message: WORKERS OF THE WORLD UNITE!
Encoded message: VGKATKL GY ZIT VGKSR XFOZT!
</pre>

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/