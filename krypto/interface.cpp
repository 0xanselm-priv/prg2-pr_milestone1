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
pair < bool, vector < vector<int> > > interface::encrypt(string source, string key, string result, bool gui){
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

    cout << "Program e started -- encryption can happen." << endl;
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

pair < bool, vector < vector<int> > > interface::decrypt(string source, string key, string result, bool gui){
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

    cout << "Third Program is warming up DECODE PICTURE" << endl;

    CBild char_canvas;

    vector < vector<char> > key_mat = char_canvas.import_file_char(key);
    vector < vector<char> > encrypted = char_canvas.import_file_char(source);

    if(char_canvas.test_matrices(char_canvas.trans_block_int(encrypted), key_mat)) {
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

pair < bool, vector < vector<int> > > interface::overlay(string img_a, string img_b, string result, bool gui){
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

    cout << "Third Program is warming up DECODE PICTURE" << endl;

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
vector < vector<char> > interface::create_rand_key(int heigth, int width){
    /*
     * This function creates a random key matrix.
     * parameter:
        * int height ~ determines the height of the key
        * int width ~ determines the width of the key
     * return:  vector < vector<char> > ~ key matrix
     */

    CBild canvas;
    vector < vector<char> > key = canvas.create_rand_picture(heigth, width);

    return key;
}

vector < vector<int> > interface::change_pixel(vector <vector <int> > mat, int x, int y, int color){
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

void interface::save_matrix(string path, vector <vector <int> > mat){
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

void interface::save_key(string path, vector <vector <char> > mat){
    /*
    * This method saves a certain key in a certain file.
    * parameter:
        * string path ~ path where the key will be saved
        * vector < vector<char> > ~ key that shall be saved
    * void
    */

    CBild canvas;
    canvas.export_file(path, canvas.trans_block_int(mat));
}