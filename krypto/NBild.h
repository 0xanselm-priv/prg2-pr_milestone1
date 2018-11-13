//
// NBild.h ~ header-file of the class NBild
// Created by Niels Heissel on 05.11.18.
// Purpose: handles simple n*m matrices with values of ones and zeros. Able to import and export matrices,
// create random ones, test and print those and change certain pixel.
// Functions are individually commented in the cpp file.
//

#ifndef UNTITLED_NBILD_H
#define UNTITLED_NBILD_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class NBild {

public:

    vector < vector<int> > import_file(string);
    void export_file(string, vector < vector<int> >);

    vector < vector<int> > change_pixel(vector < vector<int> >, int x, int y, string);
    vector < vector<int> > change_pixel(vector < vector<int> >, int x, int y, int);
    vector < vector<int> > invert_pixel(vector < vector<int> >, int x, int y);

    vector < vector<int> > create_rand_picture(int, int);

    void print_certain_matrix(vector < vector<int> >);
    bool test_matrix(vector < vector<int> >);
};


#endif //UNTITLED_NBILD_H
