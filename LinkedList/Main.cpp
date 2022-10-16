#include "LinkedList.h"
#include "LinkedList.cpp" //Template classes require cpp file inclusion. I forgot that for a hot minute
#include "TestLinkedList.h"
#include <iostream>
#include <string>

using namespace std;


/**
 * 
 * TODO: Test for memory leaks using Valgrind
 * @return int 
 */
int main(){

    TestLinkedList::testLinkedList();

    return 0;
}

