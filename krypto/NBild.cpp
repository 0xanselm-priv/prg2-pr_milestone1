//
// Created by Niels Heissel on 05.11.18.
//

#include "NBild.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

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

    ofstream ofile;
    ofile.open(destination);
    if(ofile.fail()){
        cerr << "Writing file failed!" << endl;
        exit(1);
    }
    for(int x = 0; x < height; x++){
        for(int y = 0; y < length; y++){
            ofile << matrix[x][y];
        }
        ofile << "\n";
    }
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
    ofstream ofile;
    ofile.open(dest);
    if(ofile.fail()){
        cerr << "Writing file failed!" << endl;
        exit(1);
    }
    for(int x = 0; x < height; x++){
        for(int y = 0; y < length; y++){
            ofile << matrix[x][y];
        }
        ofile << "\n";
    }
};

void NBild::change_pixel(int x, int y, string color){
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
void NBild::change_pixel(int x, int y, int color){
    matrix[x][y] = color;
};
void NBild::invert_pixel(int x, int y){
    int &value = matrix[x][y];
    if(value == 1){
        value = 0;
    }
    else{value = 1;}
};

void NBild::print_matrix() {
    // See that matrix is loaded with all information.
    for(int x = 0; x < height; x++){
        for(int y = 0; y < length; y++){
            cout << matrix[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

vector < vector<int> > NBild::create_rand_picture(int height, int width){ // creates random key matrices with blocks
    vector< vector<int> > matrix1;

    for(int x = 0; x < height; x++){
        vector<int> collum;
        collum.clear();
        for(int y = 0; y < width; y++){

            mt19937 rng;
            rng.seed(random_device()());
            uniform_int_distribution<mt19937::result_type> dist6(0, 1);
            collum.push_back(dist6(rng));
        }
        matrix1.push_back(collum);
    }
    return matrix1;
}

void NBild::print_certain_matrix(vector < vector<int> > mat){
    for(int x = 0; x < mat.size(); x++){
        for(int y = 0; y < mat[0].size(); y++){
            cout << mat[x][y];
        }
        cout << endl;
    }
    cout << endl;
}