//
// interface.h ~ header-file of the class interface
// Created by Niels Heissel on 05.11.18.
// Purpose: handles the interface between the functionality and usability.
//

#ifndef UNTITLED_INTERFACE_H
#define UNTITLED_INTERFACE_H

#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;



class interface {

public:

    pair < bool, vector < vector<int> > > encrypt(string, string, string, bool);
    pair < bool, vector < vector<int> > > decrypt(string, string, string, bool);
    pair < bool, vector < vector<int> > > overlay(string, string, string, bool);
    vector < vector<char> > create_rand_key(int, int);
    vector < vector<int> > change_pixel(vector <vector <int> >, int, int, int);
    void save_matrix(string, vector <vector <int> >);
    void save_key(string, vector <vector <char> >);



};


#endif //UNTITLED_INTERFACE_H
