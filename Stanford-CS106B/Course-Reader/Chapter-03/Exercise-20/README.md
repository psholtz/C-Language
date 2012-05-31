Exercise 20
----------- 

*There is no gene for the human spirit.*
- Tagline for the 1997 film GATTACA

The genetic code for all living organisms is carried in its DNA - a molecule with the remarkable capacity to replicate its own structure. The DNA molecule itself consists of a long strand of chemical bases wound together with a similar strand in a double helix. DNA's ability to replicate comes from the fact that its four constiuent bases - adenosine, cytosine, guanine, and thymine - combine with each other only in the following ways:

* Cytosine on one strand links only with the guanine on the other, and vice versa.
* Adenosine links only with thymine, and vice versa.

Biologists abbreviate the names of the bases by writing only the initial letter: **A**, **C**, **G** or **T**.

Inside the cell, a DNA strand acts as a template to which other DNA strands can attach themselves. As an example, suppose that you have the following DNA strand, in which the position of each base has been numbered as it would be in a C++ string:

<pre>
T A A C G G T A C G T  C
------------------------- 
0 1 2 3 4 5 6 7 8 9 10 11
</pre>

Your mission in this exercise is to determine where a shorter DNA strand can attach itself to the longer one. If, for example, you were trying to find a match for the strand

<pre>
T T G C C
</pre>

the rules of DNA dictate that this strand can bind to the longer one only at position 1:

<pre>
  T T G C C 
----------------------- 
T A A C G G T A C G T C
</pre>

By contrast, the strand

<pre>
T G C
</pre>

matches at either position 2 or position 7.

Write a function

<pre>
int findDNAMatch(string s1, string s2, int start=0);
</pre>

that returns the first position at which the DNA strand **s1** can attach to the strand **s2**. As in the **find** method for the **string** class, the optional **start** parameter indicates the index position at which the search should start. If there is no match, **findDNAMatch** should return -1.

---

Note: This program requires linking with the Stanford C++ Libraries:

http://www.stanford.edu/class/cs106b/materials/cppdoc/