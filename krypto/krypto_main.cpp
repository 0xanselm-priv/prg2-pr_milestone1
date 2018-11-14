//
// Created by Niels Heissel on 30.10.18.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
//#include "file_handler_class.h"
#include "NBild.h"
#include "CBild.h"
#include "interface.h"
#include <random>
#include <iostream>


using namespace std;

void create_rand_key(int height, int width){
    CBild canvas_char;
    canvas_char.export_file("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/key.txt", canvas_char.create_rand_picture(height, width));
}

void aufgabe_f(){
    Interface inter;
    CBild canvas_char;
    NBild canvas_int;

    // Save a second picture and a random key
    canvas_char.export_file("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispiel_f_pic2.txt", canvas_int.create_rand_picture(89,303));
    canvas_char.export_file("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispiel_f_key.txt", canvas_char.create_rand_picture(89, 303));

    // Encrypt the first picture : "beispielbild_1.txt"
    inter.encrypt("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispielbild_1.txt",
                "/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispiel_f_key.txt",
                "/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispielbild_1_enc.txt", false);

    // Encrypt the first picture : "beispiel_f_pic2.txt"
    inter.encrypt("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispiel_f_pic2.txt",
                "/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispiel_f_key.txt",
                "/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispielbild_2_enc.txt", false);

    // Overlay both pictures and save result as "result_f.txt"
    inter.overlay("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispielbild_2_enc.txt", "/Users/nielsheissel/CLionProjects/prg2-pr/krypto/beispielbild_1_enc.txt",
                "/Users/nielsheissel/CLionProjects/prg2-pr/krypto/result_f.txt", false);
}

int main(int argc, char *argv[]) {
    if(argc == 5) {
        string program = argv[1];
        string arg1 = argv[2];
        string arg2 = argv[3];
        string arg3 = argv[4];

        Interface interf;
        cout << "You passed " << argc << " arguments: " << argv[1] << endl;

        if (program == "encode") {
            cout << "Encoding your source." << endl;
            interf.encrypt(arg1, arg2, arg3, false);
        } else if (program == "decode") {
            cout << "Decoding your source." << endl;
            interf.decrypt(arg1, arg2, arg3, false);
        } else if (program == "overlay") {
            cout << "Overlaying your sources." << endl;
            interf.overlay(arg1, arg2, arg3, false);
        }
    }

    else{
        cerr << "You need to pass four arguments: ... you passed " << argc << endl;
    }

    //aufgabe_f();
    Interface face;
    vector <vector <int> > mat = face.load_matrix("/Users/nielsheissel/CLionProjects/prg2-pr/krypto/2f_approval.txt").second;
    cout << "HAH______________" << endl;
    create_rand_key(mat.size(), mat[0].size());

    return 0;
}

