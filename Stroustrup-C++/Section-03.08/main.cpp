//
//  main.cpp
//  Chapter3.8
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// sorts in reverese
bool reverse_int_sort_function(int i, int j)
{
    return (i>j);
}

struct sort_operator {
    bool operator() (int i, int j) { return (j>i); }
} my_sort_operator;

void list_ints(vector<int> &t)
{
    vector<int>::iterator it;
    for ( it = t.begin(); it < t.end(); it++ ) {
        cout << (*it) << " ";
    }
    cout << endl;
}

void simple()
{
    // construct vector
    int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
    vector<int> myvector(myints, myints+8);
    list_ints(myvector);    
    
    // using default comparison (operator <)
    sort(myvector.begin(), myvector.end());
    list_ints(myvector);
    
    // using custom "reverse" operator on last 4 elements
    sort(myvector.begin() + 4, myvector.end(), reverse_int_sort_function);
    list_ints(myvector);
    
    // sort the entire array in the "correct" direction, using object:
    sort(myvector.begin(), myvector.end(), my_sort_operator);
    list_ints(myvector);
}

int main(int argc, const char * argv[])
{
    simple();       // simple example
    return 0;
}

