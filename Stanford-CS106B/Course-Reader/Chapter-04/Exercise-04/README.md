Exercise 4
---------- 

Write a program that reads a file and reports how many lines, words and characters appear in it. For the purposes of this program, a word consists of a consecutive sequence of any characters except whitespace characters. As an example, suppose that the file **Lear.txt** contains the following passage from Shakespeare's *King Lear*, 

<pre>
Poor naked wretches, wheresoe'er you are,
That bide the pelting of this pitiless storm,
How shall your houseless heads and unfed sides,
Your loop'd and window'd raggedness, defend you
From seasons such as these?  O, I have ta'en
Too little care of this!
</pre>

your program should be able to generate the following sample run:

<pre>
Enter a filename: Lear.txt
Char count: 254
Word count:  43
Line count:   6
</pre>

The counts in the output should be displayed in a column that is aligned on the right, but which expands to fit the data. For example, if you have a file containing the full text of George Eliot's *Middlemarch*, the output of your program should look like this:

<pre>
Enter a filename: Middlemarch.txt
Char count: 1793405
Word count:  316134
Line count:   33203
</pre>
