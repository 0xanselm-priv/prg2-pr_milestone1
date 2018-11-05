//
// Created by Niels Heissel on 05.11.18.
//

#include "NBild.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void NBild::import_file(){
    ifstream file;
    file.open(path);

    if(file.fail()){
        cerr << "Reading file failed!" << endl;
        exit(1);
    }

    string line;
    getline(file, line);
    length = line.length();
    while(!file.eof()){
        height ++;
        file >> line;
        if (length != line.length()){
            cerr << "Unvalid file format" << endl;
            exit(1);
        }

        int l = 0;
        collum.clear();
        while(l < length){
            int m = stoi(line.substr(l,1));
            collum.push_back(m);
            ++l;
        }
        matrix.push_back(collum);
    }

    cout << length << "  " << height << endl;


    file.close();

};

void NBild::export_file(){

};

void NBild::import_file(string path){
    ifstream file;
    file.open(path);

    if(file.fail()){
        cerr << "Reading file failed!" << endl;
        exit(1);
    }

    string line;
    getline(file, line);
    length = line.length();
    while(!file.eof()){
        height ++;
        file >> line;
        if (length != line.length()){
            cerr << "Unvalid file format" << endl;
            exit(1);
        }

        int l = 0;
        collum.clear();
        while(l < length){
            int m = stoi(line.substr(l,1));
            collum.push_back(m);
            ++l;
        }
        matrix.push_back(collum);
    }

    cout << length << "  " << height << endl;


    file.close();
};

void NBild::export_file(string dest){

};

void NBild::change_pixel(int x, int y, string color){

};
void NBild::invert_pixel(int x, int y){

};

void NBild::print_matrix() {
    // See that matrix is loaded with all information.
    for(int x = 0; x < height; x++){
        for(int y = 0; y < length; y++){
            cout << matrix[x][y];
        }
        cout << endl;
    }
}