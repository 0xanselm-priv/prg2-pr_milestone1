//
// CBild.h ~ header-file of the class CBild
// Created by Niels Heissel on 05.11.18.
// Purpose: handles more complex n*m matrices with values of ones and zeros or of blocks (A, B and C).
// Able to import and export matrices, test two matrices if they are compatible
// and print those and change certain pixel.
// Functions are individually commented in the cpp file.
//


#ifndef UNTITLED_CBILD_H
#define UNTITLED_CBILD_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class CBild {

public:
    vector < vector<int> > import_file(string path);
    vector< vector<char> > import_file_char(string);
    vector< vector<char> > load_key(string);
    void export_file(string, vector< vector<int> >);
    void export_file(string, vector< vector<char> >);


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

    void print_certain_matrix(vector < vector<char> >);
    void print_certain_matrix(vector < vector<int> >);

    bool test_matrices(vector < vector<int> >, vector < vector<char> >);
    bool test_matrices(vector < vector<int> >, vector < vector<int> >);
};



#endif //UNTITLED_CBILD_H
