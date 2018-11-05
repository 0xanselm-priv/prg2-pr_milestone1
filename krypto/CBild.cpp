//
// Created by Niels Heissel on 05.11.18.
//

#include "CBild.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void CBild::import_file(){
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
        collum1.clear();
        collum2.clear();
        while(l < length){
            int m = stoi(line.substr(l,1));
            if(m == 1) {
                collum1.push_back(1);
                collum1.push_back(0);
                collum2.push_back(0);
                collum2.push_back(1);
            }
            else {
                collum1.push_back(0);
                collum1.push_back(1);
                collum2.push_back(1);
                collum2.push_back(0);
            }

            ++l;
        }
        matrix.push_back(collum1);
        matrix.push_back(collum2);
    }

    cout << length << "  " << height << endl;


    file.close();

};

void CBild::export_file(){
    ofstream ofile;
    ofile.open(destination);
    if(ofile.fail()){
        cerr << "Writing file failed!" << endl;
        exit(1);
    }
    for(int x = 0; x < 2*height; x++){
        for(int y = 0; y < 2*length; y++){
            ofile << matrix[x][y];
        }
        ofile << "\n";
    }
};

void CBild::import_file(string path){
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
        collum1.clear();
        collum2.clear();
        while(l < length){
            int m = stoi(line.substr(l,1));
            if(m == 1) {
                collum1.push_back(1);
                collum1.push_back(0);
                collum2.push_back(0);
                collum2.push_back(1);
            }
            else {
                collum1.push_back(0);
                collum1.push_back(1);
                collum2.push_back(1);
                collum2.push_back(0);
            }

            ++l;
        }
        matrix.push_back(collum1);
        matrix.push_back(collum2);
    }

    cout << length << "  " << height << endl;


    file.close();
};

void CBild::export_file(string dest){
    ofstream ofile;
    ofile.open(dest);
    if(ofile.fail()){
        cerr << "Writing file failed!" << endl;
        exit(1);
    }
    for(int x = 0; x < 2*height; x++){
        for(int y = 0; y < 2*length; y++){
            ofile << matrix[x][y];
        }
        ofile << "\n";
    }
};

void CBild::change_pixel(int x, int y, string color){
    int c;
    if (color == "black" || color == "b" || color == "Black"){
        c = 0;
    }
    else if(color == "white" || color == "w" || color == "White"){
        c = 1;
    }
    else {
        cout << "No valid color was given." << endl;
    };
    matrix[x][y] = c;
};
void CBild::change_pixel(int x, int y, int color){
    matrix[x][y] = color;
};
void CBild::invert_pixel(int x, int y){
    int &value = matrix[x][y];
    if(value == 1){
        value = 0;
    }
    else{value = 1;}
};

void CBild::print_matrix() {
    // See that matrix is loaded with all information.
    for(int x = 0; x < 2*height; x++){
        for(int y = 0; y < 2*length; y++){
            cout << matrix[x][y];
        }
        cout << endl;
    }
    cout << endl;
}