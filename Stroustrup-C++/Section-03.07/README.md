3.7 - Containers
================ 

Demonstrates simple uses of STL containers.

It's interesting that a "vector" can be used in almost the identical manner that an "array" can be. For instance, give the method:

<pre>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Entry {
  string name;
  int number;
};

Entry phone_book[1000];

void print_entry(int i)
{
  cout << phone_book[i].name << " " << phone_book[i].number << endl;
}
</pre>

The method "print_entry" will work the same regardless of whether we deifne phone_book as a traditional array (as above), or whether we define phone_book as a vector of Entry structures:

<pre>
vector<Entry> phone_book(1000);
</pre>