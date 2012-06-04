Exercise 6
---------- 

Another useful function in **filelib.h** is:

<pre>
string defaultExtension(string filename, string ext);
</pre>

which adds **ext** to the end of **filename** if it doesn't already have an extension. For example, 

<pre>
defaultExtension("Shakespeare",".txt");
</pre>

would return "Shakespeare.txt". If **filename** already has an extension, that name is returned unchanged, so that

<pre>
defaultExtension("library.h",".cpp");
</pre>

would ignore the specified extension and return "library.h" unchanged. If, however, **ext** includes a star before the dot, **defaultExtension** removes any existing extension from **filename** and adds the new one (minus the star). Thus,

<pre>
defaultExtension("library.h", "*.cpp");
</pre>

would return "library.cpp". Write the code for **defaultExtension** so that it behaves as described in this exercise.