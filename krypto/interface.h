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

    void main_menu(); // return the int, of which porgram should be calles
    void prog_handler(int); // calls program ? Necessary ?
    int prog1(); // returns whether to exit the program or return to the menu
    vector < vector<int> > prog2(string, string, string, bool); // returns whether to exit the program or return to the menu
    vector < vector<int> > prog3(string, string, string, bool);
    vector < vector<int> > prog4(string, string, string, bool);
    void exit_handler(int); // exits or returns back to menu

    int prog1_sub1();
    int prog1_sub2();

};


#endif //UNTITLED_INTERFACE_H
