Exercise 16
----------- 

Most people—at least those in English-speaking countries—have played the Pig Latin game  at  some  point  in  their  lives. There  are,  however,  other invented "languages" in which words are created using some simple transformation of English.  One such language is called *Obenglobish*, in which words are created by adding the letters *ob* before the  vowels  (*a*, *e*, *i*, *o*, and *u*) in an English word.  For example, under this rule, the word english  gets the letters *ob* added before the *e* and the *i* to form obenglobish, which is how the language gets its name.

In official Obenglobish,  the *ob* characters are added only before vowels that are pronounced, which means that a word like *game* would become *gobame* rather than *gobamobe* because the final *e* is silent.  While it is impossible to implement this rule perfectly, you can do a pretty good job by adopting the rule that the *ob* should be added before every vowel in the English word except

* Vowels that follow other vowels
* An *e* that occurs at the end of the word

Write a function *obenglobish* that takes an English word and returns its Obenglobish equivalent, using the transition rule given above. For example, if you used your function with the main program:

<pre>
int main()
{
  while (true) 
  {
    string word = getLine("Enter a word: ");
    if ( word == "" ) break;
    string trans = obenglobish(word);
    cout << word << " -> " << trans << endl;
  }
}
</pre>

you should be able to generate the following sample run:

<pre>
Enter a word: english
english -> obenglobish
Enter a word: hobnob
hobnob -> hobobnobob
Enter a word: gooiest
gooiest -> gobooiest
Enter a word: amaze
amaze -> obamobaze
Enter a word: rot
rot -> robot
</pre>

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/