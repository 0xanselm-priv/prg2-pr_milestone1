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


