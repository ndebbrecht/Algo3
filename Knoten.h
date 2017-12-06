/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Knoten.h
 * Author: niklas_debbrecht
 *
 * Created on 23. November 2017, 11:08
 */

#ifndef KNOTEN_H
#define KNOTEN_H

#include <string>

using namespace std;

class Knoten {
public:
    Knoten();
    //Knoten(const Knoten& orig);
    Knoten(int key, string value);
    virtual ~Knoten();
    void setLeft(Knoten* left);
    void setRight(Knoten* right);
    void setRoot(Knoten* root);
    void setKey(int key);
    void setValue(string value);
    Knoten* getRight();
    Knoten* getLeft();
    Knoten* getRoot();
    int getKey();
    string getValue();
private:
    Knoten* root;
    Knoten* left;
    Knoten* right;
    int key;
    string value;
};

#endif /* KNOTEN_H */

