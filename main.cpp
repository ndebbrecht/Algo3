/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: niklas_debbrecht
 *
 * Created on 23. November 2017, 11:02
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include "Random.h"

#include "BinarySearchTree.h"

#define GROESSEBST 1000000
#define MAXZAHLENWERT 1000000

using namespace std;

void insertValues(BinarySearchTree* tree, int size);
void removeOddNumbers(BinarySearchTree* tree, int size);
/*
 * 
 */
int main(int argc, char** argv) {
    BinarySearchTree* bst = new BinarySearchTree();
    clock_t preInsert = clock();
    insertValues(bst,GROESSEBST);

    clock_t postInsert = clock();

    clock_t insertTime = ((postInsert-preInsert)*1000)/CLOCKS_PER_SEC;
    cout<<"Der Baum mit "<<GROESSEBST<<" Werten hat zum Aufbau "<<insertTime<<"ms gebraucht!"<<endl;

    cout<<bst->height()<<endl;

    cout<<"Pruefen ob Baum bst: ";
    cout<<boolalpha<<bst->check()<<endl;
    return 0;
}

void insertValues(BinarySearchTree* tree, int size){
    Random r(MAXZAHLENWERT);
    for(int i = 0;i < size; i++){
        int rand = r.give();
        if(rand != INT_MIN) tree->insert(rand,"Knoten_"+to_string(rand/10));
    }
}

void removeOddNumbers(BinarySearchTree* tree, int size){
    int i = 0;
    for(i=0;i<size;i++){
        if(i%2!=0)tree->remove(i);
    }
}