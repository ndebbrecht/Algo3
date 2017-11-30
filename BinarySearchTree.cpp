/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.cpp
 * Author: niklas_debbrecht
 * 
 * Created on 23. November 2017, 11:07
 */

#include "BinarySearchTree.h"

Knoten root;

BinarySearchTree::BinarySearchTree(int key, string value) {
    this->root = new Knoten(key, value);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& orig) {
}

BinarySearchTree::~BinarySearchTree() {
}

BinarySearchTree::insert(int key, string value){
    Knoten u = new Knoten(key, value);
    Knoten v = this->root;
    while(v != NULL){
        if(u.getKey() < v.getKey()){
            if(v.getKey() == NULL){
                v.setLeft(u);
                return;
            } else {
                v = v.getLeft();
            }
        } else {
            if(v.getRight() == NULL){
                v.setLeft(u);
                return;
            } else {
                v = v.getRight();
            }
        }
    }
    this->root = u;
    
}

Knoten BinarySearchTree::search(int key){
    Knoten v = this->root;
    while(v != NULL){
        if(k < v.getKey()){
            v = v.getLeft();
        } else if(k == v.getKey()){
            return v;
        } else {
            v = v.getRight();
        }
        return NULL;
    }
}

BinarySearchTree::remove(int key){
    Knoten u = this->search(key);
    if(u.getLeft() == NULL && u.getRight() == NULL){ //no leafs
        if(u.getRoot()->getLeft()->getKey() == u.getKey()){ //check for u being the right or left leaf
            u.getRoot()->setLeft(NULL);
            u.~Knoten();
        } else {
            u.getRoot()->setRight(NULL);
            u.~Knoten();
        }
    } else if(u.getLeft() != NULL && u.getRight() != NULL){ // 2 leafs
        if(u.getRoot()->getLeft()->getKey() == u.getKey()){
            u.getRoot()->setLeft(u.getLeft());
            this->insert(u.getRight());
            u.~Knoten();
        } else {
           u.getRoot()->setRight(u.getRight());
           this->insert(u.getLeft());
           u.~Knoten();
        }
    } else { // one leaf
        if(u.getLeft() != NULL){
            if(u.getRoot()->getLeft()->getKey() == u.getKey()){ //check for u being the right or left leaf
                u.getRoot()->setLeft(u.getLeft());
                u.~Knoten();
            } else {
                u.getRoot()->setRight(u.getLeft());
                u.~Knoten();
            }
        } else {
            if(u.getRoot()->getLeft()->getKey() == u.getKey()){ //check for u being the right or left leaf
                u.getRoot()->setLeft(u.getRight());
                u.~Knoten();
            } else {
                u.getRoot()->setRight(u.getRight());
                u.~Knoten();
            }
        }
    }
}

BinarySearchTree::check(){
    //TODO
}

int BinarySearchTree::height(){
    int height = 0;
    //TODO
    return height;
}