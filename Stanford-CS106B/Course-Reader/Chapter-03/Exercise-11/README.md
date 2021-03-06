Exercise 11
----------- 

The concept of a palindrome is often extended to full sentences by ignoring punctuation and differences in the case of letters. For example, the sentence 

<pre>
Madam, I'm Adam.
</pre>

is a sentence palindrome, because if you look only at the letters and ignore any distinction between uppercase and lowercase letters, it reads identically backward and forward.

Write a predicate function **isSentencePalindrome(str)** that returns **true** if the string **str** fits this definition of a sentence palindrome. For example, you should be able to use your function to write a main program capable of producing the following sample run:

<pre>
Enter a sentence: "Madam, I'm Adam." 
That sentence is a palindrome.

Enter a sentence: "A man, a plan, a canal -- Panama!!" 
That sentence is a palindrome.

Enter a sentence: "Not a palindrome" 
That sentence is NOT a palindrome.
</pre>

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/