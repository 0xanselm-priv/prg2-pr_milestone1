//
// NBild.cpp ~ cpp-file of the class NBild
// Created by Niels Heissel on 05.11.18.
// Purpose: handles simple n*m matrices with values of ones and zeros. Able to import and export matrices,
// create random ones, test and print those and change certain pixel.
// Functions are individually commented in this cpp file.
//

#include "NBild.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

vector < vector<int> > NBild::import_file(string path){
    /*
    * Imports a matrix, saved in a .txt-file.
    * Only controls if it's a n*m matrix not whether it only consists of ones and zeros.
    * parameters: string ~ Path to file with file name
    * return: vector < vector<int> > ~ loaded matrix
   */

    vector < vector<int> > matrix;
    vector <int> collum;
    ifstream file;
    file.open(path);

    if(file.fail()){
        cerr << "Reading file failed! Filename: " << path << endl;
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
void NBild::export_file(string dest, vector < vector<int> > mat){
    /*
    * Exports a matrix and saves it in a .txt-file.
    * parameters:
     * string ~ path where matrix shall be saved to
     * vector < vector<int> > ~ matrix which shall be saved
    * void
   */

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
    /*
   * Changes a certain pixel of a matrix according to the parameter.
   * parameters:
     * vector < vector<int> > ~ matrix where value should be changed
     * int x ~ x coordinate of pixel
     * int y ~ y coordinate of pixel
     * string ~ color which should be the new pixel value ("black", "b", "Black" or "white", "w", "White")
   * return: vector < vector<int> > ~ new matrix
  */

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
    /*
  * Changes a certain pixel of a matrix according to the parameter. Checks for correct color.
  * parameters:
    * vector < vector<int> > ~ matrix where value should be changed
    * int x ~ x coordinate of pixel
    * int y ~ y coordinate of pixel
    * int color ~ color which should be the new pixel value (1 or 0)
  * return: vector < vector<int> > ~ new matrix
 */

    if(color == 1 || color == 0) {
        mat[x][y] = color;
    }
    else{cerr << "Wrong number given. Only ones and zeros accepted." << endl;}
    return mat;
};
vector < vector<int> > NBild::invert_pixel(vector < vector<int> > mat, int x, int y){
    /*
  * Inverts a certain pixel of a matrix. 1 -> 0 and 0 -> 1.
  * parameters:
    * vector < vector<int> > ~ matrix where value should be changed
    * int x ~ x coordinate of pixel
    * int y ~ y coordinate of pixel
  * return: vector < vector<int> > ~ new matrix
 */
    int &value = mat[x][y];
    if(value == 1){
        value = 0;
    }
    else{value = 1;}
    return mat;
};


vector < vector<int> > NBild::create_rand_picture(int height, int width){
    /*
  * Creates a random height * width matrix.
  * parameters:
    * int height ~ height of the matrix
    * int width ~ width of the matrix
  * return: vector < vector<int> > ~ new random matrix
 */

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
    /*
  * Prints a certain matrix onto the console.
  * parameters:
    * vector < vector<int> > ~ matrix which shall be printed
  * void
 */
    for(int x = 0; x < mat.size(); x++){
        for(int y = 0; y < mat[0].size(); y++){
            cout << mat[x][y];
        }
        cout << endl;
    }
    cout << endl;
}
bool NBild::test_matrix(vector < vector<int> > mat){
    /*
  * Tests a matrix for correct values and width and height.
  * parameters:
    * vector < vector<int> > ~ matrix where value should be changed
  * return: bool ~ whether test was good (true) or bad (false)
 */
    int height = mat.size();
    int width = mat[0].size();
    for(int x = 0; x < height; x++){
        if(mat[x].size() != width){
            return false;
        }
        for(int y = 0; y < width; y++){
            if(mat[x][y] != 1 && mat[x][y] != 0){
                return false;
            }
        }
    }
    return true;
}