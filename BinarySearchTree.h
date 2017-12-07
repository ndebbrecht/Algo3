/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: niklas_debbrecht
 *
 * Created on 23. November 2017, 11:07
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <string>
#include <limits.h>
#include "Knoten.h"

using namespace std;

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(int key, string value);
    BinarySearchTree(const BinarySearchTree& orig);
    Knoten* getRoot();
    void setRoot(Knoten* newRoot);
    bool insert(int key, string value);
    string search(int key);
    Knoten* searchKnoten(int key);
    void remove(int key);
    bool check(Knoten* v, int min, int max);
    bool check();
    int height(Knoten* v);
    int height();
private:
    Knoten* root;
};

#endif /* BINARYSEARCHTREE_H */

