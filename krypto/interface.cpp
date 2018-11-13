//
// Created by Niels Heissel on 05.11.18.
//

#include "interface.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "CBild.h"
#include "NBild.h"

using namespace std;


pair < bool, vector < vector<int> > > interface::prog2(string source, string key, string result, bool gui){
    cout << "Program e started -- encryption can happen." << endl;
    CBild char_canvas;
    NBild int_canvas;

    //char_canvas.export_file("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/key.txt", char_canvas.trans_block_int(char_canvas.create_rand_picture(89, 303)));

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

pair < bool, vector < vector<int> > > interface::prog3(string source, string key, string result, bool gui){
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

pair < bool, vector < vector<int> > > interface::prog4(string img_a, string img_b, string result, bool gui){
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

