//
// CBild.cpp ~ cpp-file of the class CBild
// Created by Niels Heissel on 05.11.18.
// Purpose: handles more complex n*m matrices with values of ones and zeros or of blocks (A, B and C).
// Able to import and export matrices, test two matrices if they are compatible
// and print those and change certain pixel.
// Functions are individually commented in this cpp file.
//

#include "CBild.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

vector < vector<int> > CBild::import_file(string path){
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
        for(l; l < length; l++){
            string n = line.substr(l,1);
            if(n == "1"){
                collum.push_back(1);
            }
            else if (n == "0"){
                collum.push_back(0);
            }
            else if (n == " "){
                matrix.push_back(collum);
                collum.clear();
            }
            else{cerr << "Wrong symbol given." << endl;}
        }
        matrix.push_back(collum);
    }

    file.close();

    return matrix;
};
vector< vector<char> > CBild::import_file_char(string path){
    /*
    * Imports a matrix, saved in a .txt-file which consists of ones and zeros and turns it into a block matrix.
     * This makes it bigger and doesn't look for existing blocks (1->A, 0->B). Used for overlaying matrices.
    * Only controls if it's a n*m matrix not whether it only consists of ones and zeros.
    * parameters: string ~ Path to file with file name
    * return: vector < vector<char> > ~ loaded and transformed matrix, consisting of blocks
    */

    cout << "Starting Block!" << endl;
    vector< vector<char> > matrix_char;
    vector<char> collum_char;

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
        collum_char.clear();
        for(int l = 0; l < length; l++){
            string n = line.substr(l,1);
            if(n == "1"){
                collum_char.push_back('A');
            }
            else if (n == "0"){
                collum_char.push_back('B');
            }
            else if (n == " "){
                matrix_char.push_back(collum_char);
                collum_char.clear();
            }
            else{cerr << "Wrong symbol given." << endl;}
        }
        matrix_char.push_back(collum_char);
    }

    file.close();
    cout << "Ending Block!" << endl;
    return matrix_char;
};
vector< vector<char> > CBild::load_key(string path){
    /*
     * This method loads a key from a certain .txt-file.
     * It imports the matrix at the file path and transforms it back into a block matrix.
     * paramter: string ~ path where to find matrix
     * return: vector< vector<char> > ~ key block matrix
     */

    return trans_int_block(import_file(path));
}
void CBild::export_file(string dest, vector< vector<int> > mat){
    /*
    * Exports a int-matrix (consisting of 0's and 1's) and saves it in a .txt-file.
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
void CBild::export_file(string dest, vector< vector<char> > mat){
    /*
    * Exports a char-matrix (consisting of A's, C's and B's) and saves it in a .txt-file.
    * parameters:
     * string ~ path where matrix shall be saved to
     * vector < vector<int> > ~ matrix which shall be saved
    * void
    */
    vector< vector<int> > ret_mat = trans_block_int(mat);
    ofstream ofile;
    ofile.open(dest);
    if(ofile.fail()){
        cerr << "Writing file failed!" << endl;
        exit(1);
    }
    for(int x = 0; x < ret_mat.size(); x++){
        for(int y = 0; y < ret_mat[0].size(); y++){
            ofile << ret_mat[x][y];
        }
        ofile << "\n";
    }
};

vector< vector<char> > CBild::change_block(vector< vector<char> > mat, int x, int y, char color){
    /*
    * Changes a certain block of a char-matrix.
    * parameters:
     * vector < vector<int> > ~ matrix where value should be changed
     * int x ~ x coordinate of pixel
     * int y ~ y coordinate of pixel
     * char ~ character of block to which it should be changed (A, B or C)
    * return: vector < vector<int> > ~ new matrix
    */
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
    /*
* Changes a certain pixel of a int-matrix according to the parameter.
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
vector< vector<int> > CBild::change_pixel(vector< vector<int> > mat, int x, int y, int color){
    /*
* Changes a certain pixel of a int-matrix according to the parameter. Checks for correct color.
* parameters:
* vector < vector<int> > ~ matrix where value should be changed
* int x ~ x coordinate of pixel
* int y ~ y coordinate of pixel
* int color ~ color which should be the new pixel value (1 or 0)
* return: vector < vector<int> > ~ new matrix
*/

    if(color == 1 || color == 0){
        mat[x][y] = color;
    }
    else{cerr << "Wrong color was given only 0 or 1 is accepted." << endl; }
    return mat;
};
vector< vector<int> > CBild::invert_pixel(vector< vector<int> > mat, int x, int y){
    /*
* Inverts a certain pixel of a int-matrix. 1 -> 0 and 0 -> 1.
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

vector < vector<char> > CBild::create_rand_picture(int height, int width){
    /*
    * Creates a random height * width matrix consisting of blocks, optimal for keys.
    * parameters:
     * int height ~ height of the matrix
     * int width ~ width of the matrix
    * return: vector < vector<char> > ~ new random key- or char-matrix
    */

    vector< vector<char> > matrix1;

    for(int x = 0; x < height; x++){
        vector<char> collum;
        collum.clear();
        for(int y = 0; y < width; y++){
            default_random_engine eng;
            uniform_int_distribution<int> d{0,1};

            if(d(eng)) {
                collum.push_back('A');}
            else {collum.push_back('B');}
        }
        matrix1.push_back(collum);
    }
    return matrix1;
}


void CBild::print_certain_matrix(vector < vector<char> > mat){
    /*
* Prints a certain matrix onto the console.
* parameters:
* vector < vector<char> > ~ matrix which shall be printed
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
void CBild::print_certain_matrix(vector < vector<int> > mat){
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

vector < vector<char> > CBild::encrypt_picture(vector < vector<int> > pic, vector < vector<char> > key){
    /*
     * Encrypts a matrix with respect to a certain key.
     * The key must be a char matrix with the same size as the pic-matrix.
     * parameter:
      * vector < vector<int> > ~ matrix that shall be encrypted
      * vector < vector<char> > ~ key matrix with which we will encrypt
     * return: vector < vector<char> > ~ encrypted matrix.
     */

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
    /*
 * Decrypts a matrix with respect to a certain key.
 * The key must be a char matrix with the same size as the encrypted-matrix.
 * parameter:
  * vector < vector<char> > ~ encrypted matrix that shall be decrypted
  * vector < vector<char> > ~ key matrix with which we will decrypt
 * return: vector < vector<int> > ~ decrypted matrix.
 */

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
    /*
    * Overlays two pictures or matrices over each other to create a new one.
     * both matrices must be char-matrices of the same size.
    * parameter:
     * vector < vector<int> > ~ matrix that shall be encrypted
     * vector < vector<char> > ~ key matrix with which we will encrypt
    * return: vector < vector<char> > ~ encrypted matrix.
    */

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
    /*
* Overlays two pictures or matrices over each other to create a new one.
 * both matrices must be int-matrices of the same size.
* parameter:
 * vector < vector<int> > ~ matrix that shall be encrypted
 * vector < vector<char> > ~ key matrix with which we will encrypt
* return: vector < vector<char> > ~ encrypted matrix.
*/

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
    /*
     * Transforms a block- or char-matrix into a int-matrix.
     * Does this by turning A's -> (1, 0), B's -> (0, 1) and C's -> (1, 1)
     *                             (0, 1)         (1, 0)            (1, 1)
     * parameter: vector < vector<char> > ~ matrix that shall be transformed
     * return: vector < vector<int> > ~ transformed matrix
     */

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
    /*
 * Transforms a int-matrix into a char- or block-matrix. Used for reading in keys.
 * Does this by turning A's <- (1, 0), B's <- (0, 1) and C's <- (1, 1)
 *                             (0, 1)         (1, 0)            (1, 1)
 * parameter: vector < vector<char> > ~ matrix that shall be transformed
 * return: vector < vector<int> > ~ transformed matrix
 */
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
                cout << matrix[x][y] << matrix[x][y+1] << endl;
                cout << matrix[x+1][y] << matrix[x+1][y+1] <<endl;
                cerr << "ERROR OCCURED WRONG MATRIX GIVEN" <<  matrix[x][y] << " " <<  matrix[x][y+1] << " " <<  matrix[x+1][y] << " " <<  matrix[x+1][y+1] << " " << endl;
                cout << "X:" << x << "Y:" << y << endl;
                exit(0);
            }
        }
        ret_mat.push_back(ret_col);
    }
    return ret_mat;
}

bool CBild::test_matrices(vector < vector<int> > mat_a, vector < vector<int> > mat_b){
    /*
     * Tests two matrices for their compability for overlay and en- and decryption.
     * parameter:
      * vector < vector<int> > ~ first matrix
      * vector < vector<int> > ~ second matrix
     * return: bool ~ tets result
     */

    if(mat_a.size() == mat_b.size() && mat_a[0].size() == mat_b[0].size()){
        for(int x; x < mat_a.size(); x++){
            for(int y; y < mat_a[0].size(); y++){
                if(mat_a[x][y]!=0 && mat_a[x][y]!= 1){
                    return false;
                }
                if(mat_b[x][y]!=0 && mat_b[x][y]!= 1){
                    return false;
                }
            }
        }
        return true;
    }
    else{return false;}
}
bool CBild::test_matrices(vector < vector<int> > mat_a, vector < vector<char> > mat_b){
    /*
 * Tests two matrices for their compability for overlay and en- and decryption.
 * parameter:
  * vector < vector<int> > ~ first matrix
  * vector < vector<char> > ~ block-matrix
 * return: bool ~ tets result
 */

    if(mat_a.size() == mat_b.size() && mat_a[0].size() == mat_b[0].size()){
        for(int x; x < mat_a.size(); x++){
            for(int y; y < mat_a[0].size(); y++){
                if(mat_a[x][y]!=0 && mat_a[x][y]!= 1){
                    cerr << "Wrong values." << endl;
                    return false;
                }
                if(mat_b[x][y]!= 'A' && mat_b[x][y]!= 'B' && mat_b[x][y] != 'C'){
                    cerr << "Wrong values for mat_b." << endl;
                    return false;
                }
            }
        }
        return true;
    }
    else{cerr << "Wrong sizes. Mat_A has size: " << mat_a.size() << " * " << mat_a[0].size()
    << " And Mat_B has size: " << mat_b.size() << " * " << mat_b[0].size() << endl;
        return false;}
}

bool CBild::test_matrices(vector < vector<char> > mat_a, vector < vector<char> > mat_b){
    /*
 * Tests two matrices for their compability for overlay and en- and decryption.
 * parameter:
  * vector < vector<int> > ~ first matrix
  * vector < vector<char> > ~ block-matrix
 * return: bool ~ tets result
 */

    if(mat_a.size() == mat_b.size() && mat_a[0].size() == mat_b[0].size()){
        for(int x; x < mat_a.size(); x++){
            for(int y; y < mat_a[0].size(); y++){
                if(mat_a[x][y]!= 'A' && mat_a[x][y]!= 'B' && mat_a[x][y] != 'C'){
                    cerr << "Wrong values." << endl;
                    return false;
                }
                if(mat_b[x][y]!= 'A' && mat_b[x][y]!= 'B' && mat_b[x][y] != 'C'){
                    cerr << "Wrong values for mat_b." << endl;
                    return false;
                }
            }
        }
        return true;
    }
    else{cerr << "Wrong sizes. Mat_A has size: " << mat_a.size() << " * " << mat_a[0].size()
              << " And Mat_B has size: " << mat_b.size() << " * " << mat_b[0].size() << endl;
        return false;}
}