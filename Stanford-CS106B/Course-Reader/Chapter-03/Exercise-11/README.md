Exercise 11
----------- 

The concept of a palindrome is often extended to full sentences by ignoring punctuation and differences in the case of letters. For example, the sentence 

<pre>
Mada, I'm Adam.
</pre>

is a sentence palindrome, because if you look only at the letters and ignore any distinction between uppercase and lowercase letters, it reads identically backward and forward.

Write a predicate function **isSentencePalindrome(str)** that returns **true** if the string **str** fits this definition of a sentence palindrome. For example, you should be able to use your function to write a main program capable of producing the following sample run:

<pre>
"Madam, I'm Adam." --> yes
"A man, a plan, a canal -- Panama!!" --> yes
"Not a palindrome" --> no
</pre>

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/