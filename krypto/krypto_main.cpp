//
// Created by Niels Heissel on 30.10.18.
//

#include <iostream>
#include <fstream>
#include <vector>
//#include "file_handler_class.h"
#include "NBild.h"
#include "CBild.h"
#include "interface.h"
#include <random>
#include <iostream>


using namespace std;

int main(int argc, char *argv[]) {
    string program = argv[1];
    string arg1 = argv[2];
    string arg2 = argv[3];
    string arg3 = argv[4];

    interface interf;
    cout << "You passed " << argc << " arguments: " << argv[1] << endl;

    if(argc != 5){
        cerr << "You need to pass four arguments: ... you passed " << argc << endl;
    }
    if(program == "encode"){
        cout << "Encoding your source." << endl;
        interf.prog2(arg1, arg2, arg3);
    }
    else if(program == "decode"){
        cout << "Decoding your source." << endl;
        interf.prog2(arg1, arg2, arg3);
    }
    else if(program == "overlay"){
        cout << "Overlaying your sources." << endl;
        interf.prog4(arg1, arg2, arg3);
    }


    return 0;
}
