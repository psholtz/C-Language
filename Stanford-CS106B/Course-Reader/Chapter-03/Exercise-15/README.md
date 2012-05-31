Exercise 15
----------- 

As written, the **PigLatin** program in Figure 3-2 behaves oddly if you enter a string that includes words beginning with an uppercase. For example, if you were to capitalize the first word in the sentence and the name of the Pig Latin language, you would see the following output:

<pre>
Enter English text: This is Pig Latin.
Pig Latin output: isThay isway igPay atinLay.
</pre>

Rewrite the **wordToPigLatin** function so that any word that begins with a capital letter in the English line still begins with a capital letter in Pig Latin. Thus, after making your changes in the program, the output should look like this:

<pre>
Enter English text: This is Pig Latin.
Pig Latin output: Isthay isway IgPay Atinlay.
</pre>

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/