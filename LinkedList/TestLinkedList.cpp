#include "TestLinkedList.h"
#include "LinkedList.cpp"


/**
 * @brief
 * TODO: come up with better unit testing, since there is probably a better way 
 * Idea is: create a test class that is a friend of LinkedList. This allows checking of the state 
 * of LinkedList after each operation. 
 * TODO: make sure every method is tested 
 * TODO: test for memory leaks 
 */
void TestLinkedList::testLinkedList(){
    
    testInsertion();
    testCopyConstructor();
}

/**
 * @brief 
 * 
 */
void TestLinkedList::testInsertion(){

    printTestingCategoryStart("INSERTION");

    //Test appending from empty list

    LinkedList<int> * ll = new LinkedList<int>();
    int size = 8;
    int arr[size] = {4,-2,4,67,3,-14,0,78};
    string expected = "";
    string actual = "";

    cout<<"Case 1: appending"<<endl;

    for(int i=0; i< size; ++i){
        expected += to_string(arr[i]) + " ";
        ll->pushBack(arr[i]);
    }
    actual = ll->toString();
    expected = expected.substr(0, expected.length()-1);
    cout<<"\tExpected: "<<expected<<endl;
    cout<<"\tActual:   "<<actual<<endl;
    assert(expected == ll->toString());
    cout<<"\tChecking head and tail are non-null"<<endl;
    assert(ll->tail != NULL);
    assert(ll->head != NULL);
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
    assert(ll->tail != NULL);
    assert(ll->head != NULL);
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

    printTestingCategoryEnd("INSERTION");
}

void TestLinkedList::testCopyConstructor(){

    printTestingCategoryStart("COPY CONSTRUCTOR");

    cout<<"Case 1: Empty List"<<endl;
    LinkedList<int> * ll = new LinkedList<int>();
    LinkedList<int> * ll2 = new LinkedList<int>((*ll));
    string expected = ll->toString();
    string actual = ll2->toString();

    cout<<"\tExpected string representation: "<<expected<<endl;
    cout<<"\tActual string representation:   "<<actual<<endl;
    assert(expected == actual);
    cout<<endl;

    cout<<"\tExpected size : "<<ll->getSize()<<endl;
    cout<<"\tActual size:   "<<ll2->getSize()<<endl;
    assert(ll->getSize() == ll2->getSize());
    cout<<endl;

    cout<<"\tExpected head: "<<ll->head<<endl; //Only case where heads should be the same (ie NULL)
    cout<<"\tActual head:   "<<ll2->head<<endl;
    assert(ll->head == ll2->head);
    cout<<endl;

    cout<<"Case 2: Non-Empty List"<<endl;
    int size = 9;
    int arr []= {10,20,30,40,50,60,70,80,-100};
    for(int i=0;i< size; i++)
        ll->pushBack(arr[i]);
  
    delete ll2;
    ll2 = new LinkedList<int>(*ll);

    expected = ll->toString();
    actual = ll2->toString();

    cout<<"\tExpected string representation: "<<expected<<endl;
    cout<<"\tActual string representation:   "<<actual<<endl;
    assert(expected == actual);
    cout<<endl;

    cout<<"\tExpected size : "<<ll->getSize()<<endl;
    cout<<"\tActual size:    "<<ll2->getSize()<<endl;
    assert(ll->getSize() == ll2->getSize());
    cout<<endl;

    cout<<"\tActual head: "<<ll->head<<endl; 
    cout<<"\tshould not equal: "<<ll2->head<<endl;
    assert(ll->head != ll2->head);
    cout<<endl;

    delete ll;
    delete ll2;

    cout<<"Case 3: Verifying that a deep copy is made"<<endl;

    LinkedList<char *> * d1 = new LinkedList<char *>();
    LinkedList<char *> * d2;

    size = 5;
    char *words[] = {"Exisistence","Emergence","Expedite","Plenty","Abiogenesis"};

    for(int i=0;i<size; ++i)
        d1->pushBack(words[i]);
    d2 = new LinkedList<char *>(*d1);

    cout<<"\tList 1: "<<d1->toString()<<endl;
    cout<<"\tList 2: "<<d2->toString()<<endl;
    cout<<"\tNow delete List 1 and print List 2 again"<<endl;
    delete d1;
    cout<<"\tList 2: "<<d2->toString()<<endl;
    delete d2;

    printTestingCategoryEnd("COPY CONSTRUCTOR");
}

