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
#include "Knoten.h"

class BinarySearchTree {
public:
    BinarySearchTree(int key, string value);
    BinarySearchTree(const BinarySearchTree& orig);
    virtual ~BinarySearchTree();
    insert(int key, string value);
    Knoten* search(int key);
    remove(int key);
    check();
    int height();
private:
    Knoten root;

};

#endif /* BINARYSEARCHTREE_H */

