/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedBlackTree.h
 * Author: sandragall
 *
 * Created on December 6, 2017, 3:01 PM
 */

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <limits.h>
#include "Knoten.h"

using namespace std;

class RedBlackTree{
private:
    Knoten* root;
    Knoten* nil = new Knoten(-1,"nil",BLACK);
public:
    RedBlackTree();

    void insert(int key, string value);
    Knoten* search(int key);
    bool check(Knoten* v, int min, int max);
    bool check();
    int height(Knoten* v);
    int height();
    
    void RB_Repair_Insert(Knoten* z);
    void rotateLeft(Knoten* x);
    void rotateRight(Knoten* x);
    bool isRedBlack(Knoten* k);
    int blackHeight(Knoten* k);
};

#endif /* REDBLACKTREE_H */
