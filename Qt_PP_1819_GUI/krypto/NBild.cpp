//
// Created by Niels Heissel on 05.11.18.
//

#include "NBild.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

vector < vector<int> > NBild::import_file(string path){
    vector < vector<int> > matrix;
    vector <int> collum;
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

    return matrix;
};
void NBild::export_file(string dest, vector < vector<int> > mat){
    ofstream ofile;
    ofile.open(dest);
    if(ofile.fail()){
        cerr << "Writing file failed!" << endl;
        exit(1);
    }
    for(int x = 0; x < mat.size(); x++){
        for(int y = 0; y < mat[0].size(); y++){
            ofile << mat[x][y];
        }
        ofile << "\n";
    }
};

vector < vector<int> > NBild::change_pixel(vector < vector<int> > mat, int x, int y, string color){
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
    mat[x][y] = c;
    return mat;
};
vector < vector<int> > NBild::change_pixel(vector < vector<int> > mat, int x, int y, int color){
    mat[x][y] = color;
    return mat;
};
vector < vector<int> > NBild::invert_pixel(vector < vector<int> > mat, int x, int y){
    int &value = mat[x][y];
    if(value == 1){
        value = 0;
    } else {
        value = 1;
    }
    return mat;
};


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
