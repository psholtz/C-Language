//
//  main.cpp
//  Chapter3
//
//  Created by Engineer on 5/14/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Entry {
    string name;
    int number;
};

Entry phone_book1[1000];
vector<Entry> phone_book2(1000);
list<Entry> phone_book3(1000);

#pragma mark -
#pragma mark Add Entries
void addEntries1()
{
    Entry e1;
    e1.name = "Person 1 (Array)";
    e1.number = 123;
    phone_book1[0] = e1;
    
    Entry e2;
    e2.name = "Person 2 (Array)";
    e2.number = 456;
    phone_book1[1] = e2;
    
    Entry e3;
    e3.name = "Person 3 (Array)";
    e3.number = 901;
    phone_book1[2] = e3;
}

void addEntries2()
{
    Entry e1;
    e1.name = "Person 1 (Vector)";
    e1.number = 123;
    phone_book2[0] = e1;
    
    Entry e2;
    e2.name = "Person 2 (Vector)";
    e2.number = 456;
    phone_book2[1] = e2;
    
    Entry e3;
    e3.name = "Person 3 (Vector)";
    e3.number = 901;
    phone_book2[2] = e3;
}

void addEntries3()
{
    Entry e1;
    e1.name = "Person 1 (List)";
    e1.number = 123;
    phone_book3.push_front((const Entry&)e1);
    
    Entry e2;
    e2.name = "Person 2 (List)";
    e2.number = 456;
    phone_book3.push_front((const Entry&)e2);
    
    Entry e3;
    e3.name = "Person 3 (List)";
    e3.number = 901;
    phone_book3.push_front((const Entry&)e3);
}

#pragma mark -
#pragma mark Print Entries
// Note that print_entry1 and print_entry2 have essentially the identical syntax;
// In other words, "vectors" can be used in much the same way as "arrays";
void print_entry1(int i)
{
    cout << phone_book1[i].name << " " << phone_book1[i].number << endl;
}

void print_entry2(int i)
{
    cout << phone_book2[i].name << " " << phone_book2[i].number << endl;
}

void pop_entry()
{
    const Entry &e1 = phone_book3.front();
    phone_book3.pop_front();
    cout << e1.name << " " << e1.number << endl;
}

#pragma mark -
#pragma mark Driver
int main (int argc, const char * argv[])
{
    // TEST ARRAY
    addEntries1();
    print_entry1(0);        // Person 1 (Array) 123
    print_entry1(1);        // Person 2 (Array )456
    print_entry1(2);        // Person 3 (Array) 901
    
    cout << " " << endl;
    
    // TEST VECTOR
    addEntries2();
    print_entry2(0);        // Person 1 (Vector) 123
    print_entry2(1);        // Person 2 (Vector) 456
    print_entry2(2);        // Person 3 (Vector) 901
    
    cout << " " << endl;
    
    // TEST LIST (used as a stack)
    addEntries3();
    pop_entry();            // Person 3 (List) 901
    pop_entry();            // Person 3 (List) 456
    pop_entry();            // Person 3 (List) 123
    
    return 0;
}

