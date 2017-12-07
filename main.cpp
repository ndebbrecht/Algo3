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
#include "RedBlackTree.h"

#define GROESSEBST 1000
#define MAXZAHLENWERT 1000

using namespace std;

void insertValues(BinarySearchTree* tree, int size);
void insertValuesInARow(BinarySearchTree* tree, int size);
void insertValues(RedBlackTree* tree, int size);
void insertValuesInARow(RedBlackTree* tree, int size);
void removeOddNumbers(BinarySearchTree* tree, int size);
void removeFirstFiveHundred(BinarySearchTree* tree);
/*
 * 
 */
int main(int argc, char** argv) {
    /******* AUFGABE 1 *******/
    BinarySearchTree* bst = new BinarySearchTree();
    clock_t preInsert = clock();
    insertValuesInARow(bst,GROESSEBST);

    clock_t postInsert = clock();

    clock_t insertTime = ((postInsert-preInsert)*1000)/CLOCKS_PER_SEC;
    cout<<"Der Binäre Suchbaum mit "<<GROESSEBST<<" Werten hat zum Aufbau "<<insertTime<<"ms gebraucht!"<<endl;

    cout<<bst->height()<<endl;

    cout<<"Prüfung ob Binärer Suchbaum: ";
    cout<<boolalpha<<bst->check()<<endl;
    
    /*BinarySearchTree *bst1 =new BinarySearchTree();
    insertValues(bst1,10000);
    cout<<"Hoehe bei 10000: "<<bst1->height()<<endl;
    BinarySearchTree *bst2 =new BinarySearchTree();
    insertValues(bst2,100000);
    cout<<"Hoehe bei 100000: "<<bst2->height()<<endl;
    BinarySearchTree *bst3 =new BinarySearchTree();
    insertValues(bst3,250000);
    cout<<"Hoehe bei 250000: "<<bst3->height()<<endl;
    BinarySearchTree *bst4 =new BinarySearchTree();
    insertValues(bst4,500000);
    cout<<"Hoehe bei 500000: "<<bst4->height()<<endl;
    cout<<"Hoehe bei 1000000: "<<bst->height()<<endl;*/
    
    cout<<"Remove die ersten 500 Elemente:"<<endl;
    removeFirstFiveHundred(bst);
    cout<<"Pruefen ob noch immer Bst: ";
    cout<<boolalpha<<bst->check()<<endl;
    cout<<bst->height()<<endl;
    
    /******* AUFGABE 2 *******/
    RedBlackTree* rbt = new RedBlackTree();
    clock_t preInsertRBT = clock();
    insertValuesInARow(rbt,GROESSEBST);
    clock_t postInsertRBT = clock();

    clock_t insertTimeRBT = ((postInsertRBT-preInsertRBT)*1000)/CLOCKS_PER_SEC;
    cout<<"Der Rot Schwarz Baum mit "<<GROESSEBST<<" Werten hat zum Aufbau "<<insertTimeRBT<<"ms gebraucht!"<<endl;

    cout<<"Prüfung ob Rot Schwarz: ";
    cout<<boolalpha<<rbt->check()<<endl;

    /*cout<<"Hoehe von verschiedenen Baeumen: "<<endl;
    RedBlackTree *rbt1 =new RedBlackTree();
    insertValues(rbt1,10000);
    cout<<"Hoehe bei 10000: "<<rbt1->height()<<endl;
    RedBlackTree *rbt2 =new RedBlackTree();
    insertValues(rbt2,100000);
    cout<<"Hoehe bei 100000: "<<rbt2->height()<<endl;
    RedBlackTree *rbt3 =new RedBlackTree();
    insertValues(rbt3,250000);
    cout<<"Hoehe bei 250000: "<<rbt3->height()<<endl;
    RedBlackTree *rbt4 =new RedBlackTree();
    insertValues(rbt4,500000);
    cout<<"Hoehe bei 500000: "<<rbt4->height()<<endl;
    cout<<"Hoehe bei 1000000: "<<rbt->height()<<endl;*/
    
    return 0;
}

void insertValues(BinarySearchTree* tree, int size){
    Random r(MAXZAHLENWERT);
    for(int i = 0;i < size; i++){
        int rand = r.give();
        if(rand != INT_MIN) tree->insert(rand,"Knoten_"+to_string(rand/10));
    }
}


void insertValuesInARow(BinarySearchTree* tree, int size){
    for(int i = 0;i < size; i++){
        if(i != INT_MIN) tree->insert(i,"Knoten_"+to_string(i/10));
    }
}

void insertValues(RedBlackTree* tree, int size){
    Random r(MAXZAHLENWERT);
    for(int i = 0;i < size; i++){
        int rand = r.give();
        if(rand != INT_MIN) tree->insert(rand,"Knoten_"+to_string(rand/10));
    }
}

void insertValuesInARow(RedBlackTree* tree, int size){
    for(int i = 0;i < size; i++){
        if(i != INT_MIN) tree->insert(i,"Knoten_"+to_string(i/10));
    }
}

void removeOddNumbers(BinarySearchTree* tree, int size){
    int i = 0;
    for(i=0;i<size;i++){
        if(i%2!=0)tree->remove(i);
    }
}

void removeFirstFiveHundred(BinarySearchTree* tree){
    int i = 0;
    for(i=0;i<=500;i++){
        tree->remove(500);
    }
}