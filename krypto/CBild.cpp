//
// Created by Niels Heissel on 05.11.18.
//

#include "CBild.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

vector < vector<int> > CBild::import_file(string path){
    vector < vector<int> > matrix;
    vector <int> collum;
    ifstream file;
    file.open(path);

    if(file.fail()){
        cerr << "Reading file failed!" << endl;
        exit(1);
    }


    int height = 0;
    for(string line; getline(file, line); ){
        height ++;
        int length = line.length();
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

    file.close();

    return matrix;
};
vector< vector<int> > CBild::import_file_int(string path){
    vector< vector<int> > matrix;
    vector<int> collum1;
    vector<int> collum2;

    ifstream file;
    file.open(path);

    if(file.fail()){
        cerr << "Reading file failed!" << endl;
        exit(1);
    }

    string line;
    int height = 0;
    for(string line; getline(file, line); ){
        height ++;
        int length = line.length();
        if (length != line.length()){
            cerr << "Unvalid file format" << endl;
            exit(1);
        }

        collum1.clear();
        collum2.clear();
        for(int l = 0; l < length; l++){
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

    file.close();
    return matrix;
};
vector< vector<char> > CBild::import_file_char(string path){
    cout << "Starting Block!" << endl;
    vector< vector<char> > matrix_char;
    vector<char> collum_char;

    ifstream file;
    file.open(path);

    if(file.fail()){
        cerr << "Reading file failed!" << endl;
        exit(1);
    }

    string line;
    int height = 0;
    for(string line; getline(file, line); ){
        height ++;
        int length = line.length();
        if (length != line.length()){
            cerr << "Unvalid file format" << endl;
            exit(1);
        }
        collum_char.clear();
        for(int l = 0; l < length; l++){
            int m = stoi(line.substr(l,1));
            if(m == 1) {
                collum_char.push_back('A');
            }
            else {
                collum_char.push_back('B');
            }

            ++l;
        }
        matrix_char.push_back(collum_char);
    }

    file.close();
    cout << "Ending Block!" << endl;
    return matrix_char;
};
vector< vector<char> > CBild::load_key(string path){
    return trans_int_block(import_file(path));
}
void CBild::export_file(string dest, vector< vector<int> > mat){
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
void CBild::export_file(string dest, vector< vector<char> > mat){
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

vector< vector<char> > CBild::change_block(vector< vector<char> > mat, int x, int y, char color){
    if(color == 'A'){
        mat[x][y] = 'A';
    }
    else if(color == 'B'){
        mat[x][y] = 'B';
    }
    else{cerr << "Wrong Block was given --> either A or B are accepted." << endl;}

    return mat;
};
vector< vector<int> > CBild::change_pixel(vector< vector<int> > mat, int x, int y, string color){
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
vector< vector<int> > CBild::change_pixel(vector< vector<int> > mat, int x, int y, int color){
    if(color == 1 || color == 0){
        mat[x][y] = color;
    }
    else{cerr << "Wrong color was given only 0 or 1 is accepted." << endl; }
    return mat;
};
vector< vector<int> > CBild::invert_pixel(vector< vector<int> > mat, int x, int y){
    int &value = mat[x][y];
    if(value == 1){
        value = 0;
    }
    else{value = 1;}
    return mat;
};

vector < vector<char> > CBild::create_rand_picture(int height, int width){ // creates random key matrices with blocks
    vector< vector<char> > matrix1;

    for(int x = 0; x < height; x++){
        vector<char> collum;
        collum.clear();
        for(int y = 0; y < width; y++){

            mt19937 rng;
            rng.seed(random_device()());
            uniform_int_distribution<mt19937::result_type> dist6(0, 1);
            if(dist6(rng)) {
                collum.push_back('A');}
            else {collum.push_back('B');}
        }
        matrix1.push_back(collum);
    }
    return matrix1;
}


void CBild::print_certain_matrix(vector < vector<char> > mat){
    for(int x = 0; x < mat.size(); x++){
        for(int y = 0; y < mat[0].size(); y++){
            cout << mat[x][y];
        }
        cout << endl;
    }
    cout << endl;
}
void CBild::print_certain_matrix(vector < vector<int> > mat){
    for(int x = 0; x < mat.size(); x++){
        for(int y = 0; y < mat[0].size(); y++){
            cout << mat[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

vector < vector<char> > CBild::encrypt_picture(vector < vector<int> > pic, vector < vector<char> > key){
    vector < vector<char> > enc_mat;
    vector<char> enc_col;
    for(int x = 0; x < pic.size(); x++){
        enc_col.clear();
        for(int y = 0; y < pic[0].size(); y++){
            if(pic[x][y] == 0){
                if(key[x][y] == 'A'){enc_col.push_back('B');}
                else{enc_col.push_back('A');}
            }
            else{enc_col.push_back(key[x][y]);}
        }
        enc_mat.push_back(enc_col);
    }
    return enc_mat;
}
vector < vector<int> > CBild::decrypt_picture(vector < vector<char> > enc_pic, vector < vector<char> > key){
    vector < vector<int> > dec_mat;
    vector<int> dec_col;
    for(int x = 0; x < key.size(); x++){
        dec_col.clear();
        for(int y = 0; y < key[0].size(); y++){
            if(enc_pic[x][y] == key[x][y]){
                dec_col.push_back(1);
            }
            else{
                dec_col.push_back(0);
            }
        }
        dec_mat.push_back(dec_col);
    }
    return dec_mat;
}
vector < vector<char> > CBild::overlay_pictures(vector < vector<char> > enc_pic, vector < vector<char> > key){
    if(key.size() == enc_pic.size() && key[0].size() == enc_pic[0].size()) {
        vector<vector<char> > dec_mat;
        vector<char> dec_col;
        for (int x = 0; x < key.size(); x++) {
            dec_col.clear();
            for (int y = 0; y < key[0].size(); y++) {
                if (enc_pic[x][y] == key[x][y]) {
                    dec_col.push_back(key[x][y]);
                } else {
                    dec_col.push_back('C');
                }
            }
            dec_mat.push_back(dec_col);
        }
        return dec_mat;
    }
    else {
        cerr << "The pictures have a different size!" << endl;
        exit(0);
    }
}
vector < vector<int> > CBild::overlay_pictures(vector < vector<int> > enc_pic, vector < vector<int> > key){
    if(key.size() == enc_pic.size() && key[0].size() == enc_pic[0].size()) {
        vector<vector<int> > dec_mat;
        vector<int> dec_col;
        for (int x = 0; x < key.size(); x++) {
            dec_col.clear();
            for (int y = 0; y < key[0].size(); y++) {
                if (enc_pic[x][y] == key[x][y]) {
                    dec_col.push_back(key[x][y]);
                } else {
                    dec_col.push_back(1);
                }
            }
            dec_mat.push_back(dec_col);
        }
        return dec_mat;
    }
    else {
        cerr << "The pictures have a different size!" << endl;
        exit(0);
    }
}


vector < vector<int> > CBild::trans_block_int(vector < vector<char> > matrix){
    vector < vector<int> > ret_mat;
    vector<int> ret_col1;
    vector<int> ret_col2;
    for(int x = 0; x < matrix.size(); x++) {
        ret_col1.clear();
        ret_col2.clear();
        for (int y = 0; y < matrix[0].size(); y++) {
            if (matrix[x][y] == 'A') {
                ret_col1.push_back(1);
                ret_col1.push_back(0);
                ret_col2.push_back(0);
                ret_col2.push_back(1);
            } else if (matrix[x][y] == 'B') {
                ret_col1.push_back(0);
                ret_col1.push_back(1);
                ret_col2.push_back(1);
                ret_col2.push_back(0);
            } else if (matrix[x][y] == 'C') {
                ret_col1.push_back(1);
                ret_col1.push_back(1);
                ret_col2.push_back(1);
                ret_col2.push_back(1);
            } else {
                cerr << "ERROR ACCURED WRONG MATRIX Given" << endl;
                exit(0);
            }
        }
        ret_mat.push_back(ret_col1);
        ret_mat.push_back(ret_col2);
    }
    return ret_mat;
}
vector < vector<char> > CBild::trans_int_block(vector < vector<int> > matrix){
    vector < vector<char> > ret_mat;
    vector<char> ret_col;
    for(int x = 0; x < matrix.size(); x += 2) {
        ret_col.clear();
        for (int y = 0; y < matrix[0].size(); y+=2) {
            if (matrix[x][y] == 1 && matrix[x+1][y] == 0 && matrix[x][y+1] == 0 && matrix[x+1][y+1] == 1) {
                ret_col.push_back('A');
            } else if (matrix[x][y] == 0 && matrix[x+1][y] == 1 && matrix[x][y+1] == 1 && matrix[x+1][y+1] == 0) {
                ret_col.push_back('B');
            } else if (matrix[x][y] == 1 && matrix[x+1][y] == 1 && matrix[x][y+1] == 1 && matrix[x+1][y+1] == 1) {
                ret_col.push_back('C');
            } else {
                cout << matrix[0][0] << matrix[0][1] << endl;
                cout << matrix[1][0] << matrix[1][1] <<endl;
                cerr << "ERROR ACCURED WRONG MATRIX Given" << x << y <<  matrix[x][y] << " " <<  matrix[x][y+1] << " " <<  matrix[x+1][y] << " " <<  matrix[x+1][y+1] << " " << endl;
                exit(0);
            }
        }
        ret_mat.push_back(ret_col);
    }
    return ret_mat;
}

bool CBild::test_matrices(vector < vector<int> > mat_a, vector < vector<int> > mat_b){
    return (mat_a.size() == mat_b.size() && mat_a[0].size() == mat_b[0].size());
}
bool CBild::test_matrices(vector < vector<int> > mat_a, vector < vector<char> > mat_b){
    return (mat_a.size() == 2*mat_b.size() && mat_a[0].size() == 2*mat_b[0].size());
}