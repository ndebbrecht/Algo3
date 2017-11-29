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
        } else if(k == v.key){
            return v;
        } else {
            v = v.getRight();
        }
        return NULL;
    }
}

BinarySearchTree::remove(int key){
    
}

BinarySearchTree::check(){
    
}

int BinarySearchTree::height(){
    int height = 0;
    
    return height;
}