//
// Created by Niels Heissel on 05.11.18.
//

#ifndef UNTITLED_INTERFACE_H
#define UNTITLED_INTERFACE_H

#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;



class interface {
private:
    string default_path;
    bool running;
    int prog_number;

public:
    vector < vector<int> > create_rand_picture(int, int);

    void set_default_path(string path){
        this->default_path = path;
    };
    string get_default_path(){
        return this->default_path;
    };

    pair < bool, vector < vector<int> > > prog2(string, string, string, bool); // returns whether to exit the program or return to the menu
    pair < bool, vector < vector<int> > > prog3(string, string, string, bool);
    pair < bool, vector < vector<int> > > prog4(string, string, string, bool);


};


#endif //UNTITLED_INTERFACE_H
