#include "LinkedList.h"
#include "LinkedList.cpp" //Template classes require cpp file inclusion. I forgot that for a hot minute
#include <iostream>
#include <string>

using namespace std;


void testLinkedList();
void testInsertion();

int main(){

    testLinkedList();

    return 0;
}

/**
 * @brief
 * TODO: come up with better unit testing, since there is probably a better way 
 * Idea is: create a test class that is a friend of LinkedList. This allows checking of the state 
 * of LinkedList after each operation. 
 * 
 */
void testLinkedList(){
    
    testInsertion();
    testDeletion();

}

/**
 * @brief 
 * 
 */
void testInsertion(){

    cout<<"--- TESTING INSERTION ---"<<endl<<endl;

    //Test appending from empty list

    LinkedList<int> * ll = new LinkedList<int>();
    int size = 8;
    int arr[size] = {4,-2,4,67,3,-14,0,78};
    string expected = "";
    string actual = "";

    cout<<"Case 1: appending"<<endl;

    for(int i=0; i< size; ++i){
        expected += to_string(arr[i]) + " ";
        ll->add(arr[i]);
    }
    actual = ll->toString();
    expected = expected.substr(0, expected.length()-1);
    cout<<"\tExpected: "<<expected<<endl;
    cout<<"\tActual:   "<<actual<<endl;
    assert(expected == ll->toString());
    cout<<endl;

    delete ll;

    //test insertion at other points
    cout<<"Case 2: insertion at head from empty"<<endl;

    ll = new LinkedList<int>();
    expected = "";
    actual = "";

    for(int i=0; i< size; ++i){
        expected += to_string(arr[size - i - 1]) + " ";
        ll->insertAt(arr[i], 0);
    }
    actual = ll->toString();
    expected = expected.substr(0, expected.length()-1);
    cout<<"\tExpected: "<<expected<<endl;
    cout<<"\tActual:   "<<actual<<endl;
    assert(expected == ll->toString());
    cout<<endl;

    cout<<"Case 3: insertion into middle of list, just after head and just before tail"<<endl;
    expected = "78 4 0 -14 3 23 67 4 -2 17 4";

    ll->insertAt(17, 7);
    ll->insertAt(23, 4);
    ll->insertAt(4, 1);
    actual = ll->toString();
    cout<<"\tExpected: "<<expected<<endl;
    cout<<"\tActual:   "<<actual<<endl;
    assert(actual == expected);

    cout<<"--- INSERTION TESTS PASSED ---"<<endl<<endl;
}

