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
    vector< vector<int> > matrix1;
    int height;
    int width;
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

    int main_menu(); // return the int, of which porgram should be calles
    void prog_handler(int); // calls program ? Necessary ?
    int prog1(); // returns whether to exit the program or return to the menu
    int prog2(); // returns whether to exit the program or return to the menu
    void exit_handler(int); // exits or returns back to menu

    void print_matrix();

};


#endif //UNTITLED_INTERFACE_H
