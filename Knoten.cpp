/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Knoten.cpp
 * Author: niklas_debbrecht
 * 
 * Created on 23. November 2017, 11:08
 */

#include "Knoten.h"
#include <string>

int key;
string value;
Knoten* left;
Knoten* right;
Knoten* root;

Knoten::Knoten(int key, string value) {
    this->key = key;
    this->value = value;
    this->root = NULL;
    this->right = NULL;
    this->left = NULL;
}

Knoten::~Knoten() {
}

void Knoten::setLeft(Knoten* left){
    this->left = left;
    left->setRoot(this);
}

void Knoten::setRight(Knoten* right){
    this->right = right;
    right->setRoot(this);
}

Knoten* Knoten::getLeft(){
    return this->left;
}

Knoten* Knoten::getRight(){
    return this->right;
}

int Knoten::getKey(){
    return this->key;
}

string Knoten::getValue(){
    return this->value;
}

Knoten* Knoten::getRoot(){
    return this->root;
}

void Knoten::setRoot(Knoten* root){
    this->root = root;
}

void Knoten::setValue(string value){
    this->value = value;
}

void Knoten::setKey(int key){
    this->key = key;
}