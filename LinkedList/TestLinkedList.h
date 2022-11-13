#ifndef TESTLINKEDLIST_H
#define TESTLINKEDLIST_H

#include <cassert>

#include "LinkedList.h"

/**
 * I decided to move from a Block Box Testing methodology to a White Box testing methodology since 
 * when it comes to datastructures it is crucial to verify that the internal structure of the 
 * datastructure is correct after some function is run. It would be terrible to have a linkedlist 
 * appear correct with its output but actually have an erroneous internal state.
 * 
 * TODO: Performance tests (?)
 */
class TestLinkedList{

    public:
        static void testLinkedList();

    private:
        static void testInsertion();
        static void testCopyConstructor();

        //For resuse
        static void printTestingCategoryStart(string category){
        cout<<"--- TESTING "<<category<<" ---"<<endl<<endl;
        }

        //For reuse
        static void printTestingCategoryEnd(string category){
        cout<<"--- "<<category<<" TESTS PASSED ---"<<endl<<endl;
        }

};


#endif 