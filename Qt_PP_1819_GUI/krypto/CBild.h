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

public:
    vector < vector<int> > import_file(string path);
    vector< vector<int> > import_file_int(string);
    vector< vector<char> > import_file_char(string);
    vector< vector<char> > load_key(string);
    void export_file(string, vector< vector<int> >);
    void export_file(string, vector< vector<char> >);


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


    vector< vector<char> > change_block(vector< vector<char> > mat, int x, int y, char color);
    vector< vector<int> > change_pixel(vector< vector<int> >, int x, int y, string);
    vector< vector<int> > change_pixel(vector< vector<int> >, int x, int y, int);
    vector< vector<int> > invert_pixel(vector< vector<int> >, int x, int y);

    vector < vector<char> > create_rand_picture(int, int);
    vector < vector<char> > encrypt_picture(vector < vector<int> >, vector < vector<char> >);
    vector < vector<int> > decrypt_picture(vector < vector<char> >, vector < vector<char> >);
    vector < vector<char> > overlay_pictures(vector < vector<char> >, vector < vector<char> >);
    vector < vector<int> > overlay_pictures(vector < vector<int> >, vector < vector<int> >);

    vector < vector<int> > trans_block_int(vector < vector<char> >);
    vector < vector<char> > trans_int_block(vector < vector<int> > matrix);
    void print_matrix();
    void print_certain_matrix(vector < vector<char> >);
    void print_certain_matrix(vector < vector<int> >);

    bool test_matrices(vector < vector<int> >, vector < vector<char> >);
    bool test_matrices(vector < vector<int> >, vector < vector<int> >);
};



#endif //UNTITLED_CBILD_H
