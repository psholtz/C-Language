//
//  main.cpp
//  Chapter3
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <complex.h>

using namespace std;

struct Entry {
    string name;
    int number;
};

#pragma mark -
#pragma mark Prototypes
void display1(vector<int> &vc);
void display2(list<int> &vc);
void display3(vector<int> &vc);
int count1(const string& s, char c);
template<class C,class T>int count2(const C&v, T val);
void simple();

bool reverse_sort_function(int i, int j);

#pragma mark- 
#pragma mark Sorting Functions
bool reverse_sort_function(int i, int j)
{
    return (i>j);
}

struct sort_operator
{
    bool operator() (int i, int j) { return (j>i); }
} my_sort_operator;

#pragma mark - 
#pragma mark Definitions 
void display1(vector<int> &vc)
{
    int count = 1;
    vector<int>::iterator it;
    cout << "[Vector]" << endl;
    for ( it = vc.begin(); it < vc.end(); ++it ) {
        cout << count << " :: " << (*it) << endl;
        count++;
    }
}

void display2(list<int> &vc)
{
    int count = 1;
    list<int>::iterator it;
    cout << "[List]" << endl;
    for ( it=vc.begin(); it != vc.end(); ++it ) {
        cout << count << " :: " << (*it) << endl;
        count++;
    }
}

void display3(vector<int> &vc)
{
    cout << "Vector: "; 
    vector<int>::iterator it;
    for ( it=vc.begin(); it != vc.end(); ++it ) {
        cout << (*it) << ", ";
    }
    cout << endl;
}

// count occurrence of 'c' in string 's'
int count1(const string& s, char c)
{
    int n = 0;
    string::const_iterator i = find(s.begin(),s.end(),c);
    while ( i != s.end() ) 
    {
        ++n;
        i = find(i+1,s.end(),c);
    }
    return n;
}

// (highly) generalized version of count algorithm
template<class C, class T>int count2(const C& v, T val)
{
    int n = 0;
    typename C::const_iterator i = find(v.begin(), v.end(), val);
    while ( i != v.end() ) 
    {
        ++n;
        i = find(i+1, v.end(), val);
    }
    return n;
}

void simple()
{
    cout << "[Simple]" << endl;
    
    // construct the vector
    int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
    vector<int> myvector(myints, myints+8);
    display3(myvector);
    
    // use default comparison (operator <)
    sort(myvector.begin(), myvector.end());
    display3(myvector);
    
    // using custom "reverse" operator on last 4 elements
    sort(myvector.begin() + 4, myvector.end(), reverse_sort_function);
    display3(myvector);
    
    // sort the entire array in the "correct" direction, using object:
    sort(myvector.begin(), myvector.end(), my_sort_operator);
    display3(myvector);
}

#pragma mark -
#pragma mark Main Methods
int main (int argc, const char * argv[])
{
    // Example of Simple Sorting
    simple();
    
    cout << " " << endl;
    
    // Use of STL Vector
    vector<int> v1(3);
    v1[0] = 100;
    v1[1] = 105;
    v1[2] = 102;
    display1(v1);
    
    cout << " " << endl;
    
    // Use of STL List 
    list<int> v2;
    v2.push_back(100);
    v2.push_back(105);
    v2.push_back(102);
    display2(v2);
    
    cout << " " << endl;
    
    // Demonstrate counting STL String
    cout << "[Count String]" << endl;
    cout << "Count 't' in 'this': " << count1("this",'t') << endl;
    cout << "Count 'i' in 'this': " << count1("This",'i') << endl;
    cout << "Count 's' in 'Mississippi': " << count1("Mississippi",'s') << endl;
    cout << "Count 'i' in 'Mississippi': " << count1("Mississippi",'i') << endl;
    cout << "Count 'i' in 'Sholtz': " << count1("Sholtz",'i') << endl;
    cout << "Count 'a' in 'Mary had a little lamb': " << count1("Mary had a little lamb",'a') << endl;
    cout << "Count 'a' in 'aa': " << count1("aa",'a') << endl;
    cout << "Count 'a' in 'axa': " << count1("axa",'a') << endl;
    
    cout << " " << endl;
    
    // Demonstrate counting Complex
    complex<int> c1(1,2), c2(2,3), c3(1,1), c4(5,3), c5(1,1);
    complex<int> c0(0,0);
    vector< complex<int> > v3(5);
    v3[0] = c1;
    v3[1] = c2;
    v3[2] = c3;
    v3[3] = c4;
    v3[4] = c5;
    cout << "[Count Complex]" << endl;
    cout << "Count (2,3) in container: " << count2(v3,c2) << endl;
    cout << "Count (1,1) in container: " << count2(v3,c3) << endl;
    cout << "Count (0,0) in container: " << count2(v3,c0) << endl;
    
    return 0;
}