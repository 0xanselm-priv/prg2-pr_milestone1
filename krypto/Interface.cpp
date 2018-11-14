//
// interface.cpp ~ cpp-file of the class interface
// Created by Niels Heissel on 05.11.18.
// Purpose: handles the interface between the functionality and usability.
//

#include "interface.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "CBild.h"
#include "NBild.h"

using namespace std;

// Main programms
pair < bool, vector < vector<int> > > Interface::encrypt(string source, string key, string result, bool gui){
    /*
     * This functions encrypts a certain picture with a certain key and saves it on a file path, if gui is false.
     * gui is the variable which is set true when the graphical user interface calls it and false otherwise.
     * parameter:
        * string source ~ path of the image that shall be encrypted
        * string key ~ path of the key that is used for encryption
        * string result ~ path of the file where the result shall be saved to
        * bool ~ see above
     * result: pair < bool, vector < vector<int> > > ~ tuple of bool and matrix, the bool states, whether everything
        * went correctly and the matrix is the result of the operation
     */

    cout << "Program started -- encrypting source." << endl;
    CBild char_canvas;
    NBild int_canvas;


    vector< vector<int> > source_mat = int_canvas.import_file(source);
    vector< vector<char> > key_mat = char_canvas.load_key(key);
    if(char_canvas.test_matrices(source_mat, key_mat)) {
        vector<vector<char> > encrypted = char_canvas.encrypt_picture(source_mat, key_mat);

        if (!gui) {
            char_canvas.export_file(result, char_canvas.trans_block_int(encrypted));
        }
        return pair < bool, vector < vector<int> > > (true ,char_canvas.trans_block_int(encrypted));
    }
    else{
        cerr << "Key and source are not compatible (not the same size)!" << endl;
        return pair < bool, vector < vector<int> > > (false, source_mat);
    }
}

pair < bool, vector < vector<int> > > Interface::encrypt(string source, vector <vector <int> > key, string result, bool gui){
    /*
     * This functions encrypts a certain picture with a certain key and saves it on a file path, if gui is false.
     * gui is the variable which is set true when the graphical user interface calls it and false otherwise.
     * parameter:
        * string source ~ path of the image that shall be encrypted
        * vector <vector <int> > key ~ key matrix that is used for encryption
        * string result ~ path of the file where the result shall be saved to
        * bool ~ see above
     * result: pair < bool, vector < vector<int> > > ~ tuple of bool and matrix, the bool states, whether everything
        * went correctly and the matrix is the result of the operation
     */

    cout << "Program started -- encrypting source." << endl;
    CBild char_canvas;
    NBild int_canvas;


    vector< vector<int> > source_mat = int_canvas.import_file(source);
    vector< vector<char> > key_mat = char_canvas.trans_int_block(key);
    if(char_canvas.test_matrices(source_mat, key_mat)) {
        vector<vector<char> > encrypted = char_canvas.encrypt_picture(source_mat, key_mat);

        if (!gui) {
            char_canvas.export_file(result, char_canvas.trans_block_int(encrypted));
        }
        return pair < bool, vector < vector<int> > > (true ,char_canvas.trans_block_int(encrypted));
    }
    else{
        cerr << "Key and source are not compatible (not the same size)!" << endl;
        return pair < bool, vector < vector<int> > > (false, source_mat);
    }
}

pair < bool, vector < vector<int> > > Interface::decrypt(string source, string key, string result, bool gui){
    /*
 * This functions decrypts a certain picture with a certain key and saves it on a file path, if gui is false.
 * gui is the variable which is set true when the graphical user interface calls it and false otherwise.
 * parameter:
    * string source ~ path of the image that shall be decrypted
    * string key ~ path of the key that is used for decryption
    * string result ~ path of the file where the result shall be saved to
    * bool ~ see above
 * result: pair < bool, vector < vector<int> > > ~ tuple of bool and matrix, the bool states, whether everything
    * went correctly and the matrix is the result of the operation
 */

    cout << "Decoding picture... please wait." << endl;

    CBild char_canvas;

    vector < vector<char> > key_mat = char_canvas.load_key(key);
    vector < vector<char> > encrypted = char_canvas.load_key(source);

    if(char_canvas.test_matrices(encrypted, key_mat)) {
        vector<vector<int> > decrypted = char_canvas.decrypt_picture(encrypted, key_mat);
        if (!gui) {
            char_canvas.export_file(result, decrypted);
        }
        return pair < bool, vector < vector<int> > > (true, decrypted);
    }
    else{
        cerr << "Key and source are not compatible (not the same size)!" << endl;
        return pair < bool, vector < vector<int> > > (false, char_canvas.trans_block_int(encrypted));
    }

}

pair < bool, vector < vector<int> > > Interface::overlay(string img_a, string img_b, string result, bool gui){
    /*
 * This functions overlays two pictures and saves the result on a file path, if gui is false.
 * gui is the variable which is set true when the graphical user interface calls it and false otherwise.
 * parameter:
    * string img_a ~ path of the first image
    * string img_b ~ path of the second image
    * string result ~ path of the file where the result shall be saved to
    * bool ~ see above
 * result: pair < bool, vector < vector<int> > > ~ tuple of bool and matrix, the bool states, whether everything
    * went correctly and the matrix is the result of the operation
 */

    cout << "Pictures are now going to be overlayed... please wait." << endl;

    CBild char_canvas;
    NBild int_canvas;

    vector < vector<int> > mat_a = char_canvas.import_file(img_a);
    vector < vector<int> > mat_b = char_canvas.import_file(img_b);

    if(char_canvas.test_matrices(mat_a, mat_b)) {
        vector<vector<int> > overlayed = char_canvas.overlay_pictures(mat_a, mat_b);

        if (!gui) {
            char_canvas.export_file(result, overlayed);
        }
        return pair < bool, vector < vector<int> > > (true, overlayed);
    }
    else{
        cerr << "Key and source are not compatible (not the same size)!" << endl;

        return pair < bool, vector < vector<int> > > (true, mat_a);
    }
}


// Extras for GUI
vector < vector<int> > Interface::create_rand_key(int height, int width){
    /*
     * This function creates a random key matrix.
     * parameter:
        * int height ~ determines the height of the key
        * int width ~ determines the width of the key
     * return:  vector < vector<int> > ~ key matrix with ones and zeros
     */

    CBild canvas;
    vector < vector<int> > key = canvas.trans_block_int(canvas.create_rand_picture(height, width));

    return key;
}

vector < vector<int> > Interface::change_pixel(vector <vector <int> > mat, int x, int y, int color){
    /*
     * This function changes the value of a pixel of a certain matrix.
     * parameter:
        * vector < vector<int> > ~ matrix which shall be changed
        * int x ~ x coordinate of the pixel
        * int y ~ y coordinate of the pixel
        * int color ~ color of the pixel
     * return: vector < vector<int> > ~ adjusted matrix
     */

    NBild canvas;
    return canvas.change_pixel(mat, x, y, color);
}

void Interface::save_matrix(string path, vector <vector <int> > mat){
    /*
     * This method saves a certain matrix in a certain file.
     * parameter:
        * string path ~ path where the matrix will be saved
        * vector < vector<int> > ~ matrix that shall be saved
     * void
     */

    NBild canvas;
    canvas.export_file(path, mat);
    cout << "Exported Matrix to: " << path << endl;
}

void Interface::save_key(string path, vector <vector <int> > mat){
    /*
    * This method saves a certain key in a certain file.
    * parameter:
        * string path ~ path where the key will be saved
        * vector < vector<int> > ~ key that shall be saved
    * void
    */

    CBild canvas;
    canvas.export_file(path, mat);
}

pair < bool, vector < vector<int> > > Interface::load_matrix(string path){
    /*
     * This function loads a matrix and checks whether it is valid or not.
     * parameter: string ~ the path of the matrix which shall be loaded
     * return: pair < bool, vector < vector<int> > > ~ pair of (valid? and matrix)
     */

    NBild canvas;

    vector<vector<int> > mat = canvas.import_file(path);
    if (canvas.test_matrix(mat)) {
        return pair<bool, vector<vector<int> > >(true, mat);
    } else {
        vector<vector<int> > zero;
        return pair<bool, vector<vector<int> > >(false, zero);

    }
}