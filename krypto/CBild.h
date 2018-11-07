//
// Created by Niels Heissel on 05.11.18.
//

#ifndef UNTITLED_CBILD_H
#define UNTITLED_CBILD_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class CBild {
private:
    string path;
    string destination;
    string new_file_name;
    vector< vector<int> > matrix;
    vector<int> collum1;
    vector<int> collum2;
    vector< vector<char> > matrix_char;
    vector<char> collum_char;
    int height{0};
    int length{0};

public:
    void import_file();
    void export_file();
    void import_file(string);
    void export_file(string);


    void set_path(string path){
        this->path = path;
    };
    void set_destination(string dest){
        this->destination = dest;
    };
    void set_new_file_name(string name){
        this->new_file_name = name;
    };
    string get_path(){
        return this->path;
    };
    string get_destination(){
        return this->destination;
    };
    string get_new_file_name(){
        return this->new_file_name;
    };
    int get_length(){
        return this->length;
    };
    int get_height(){
        return this->height;
    };

    void change_pixel(int x, int y, string);
    void change_pixel(int x, int y, int);
    void invert_pixel(int x, int y);

    vector < vector<char> > create_rand_picture(int, int);

    void print_matrix();
    void print_certain_matrix(vector < vector<char> >);
    void print_certain_matrix(vector < vector<int> >);
};



#endif //UNTITLED_CBILD_H
