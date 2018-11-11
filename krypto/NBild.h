//
// Created by Niels Heissel on 05.11.18.
//

#ifndef UNTITLED_NBILD_H
#define UNTITLED_NBILD_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class NBild {
private:
    string path;
    string destination;
    string new_file_name;

public:
    vector < vector<int> > import_file(string);
    void export_file(string, vector < vector<int> >);

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

    vector < vector<int> > change_pixel(vector < vector<int> >, int x, int y, string);
    vector < vector<int> > change_pixel(vector < vector<int> >, int x, int y, int);
    vector < vector<int> > invert_pixel(vector < vector<int> >, int x, int y);

    vector < vector<int> > create_rand_picture(int, int);
    vector < vector<int> > encrypt_picture(vector < vector<int> >, vector < vector<int> >);

    void print_certain_matrix(vector < vector<int> >);
};


#endif //UNTITLED_NBILD_H
