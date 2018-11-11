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


void interface::main_menu(){
    running = true;
    while(running){
        cin.clear();
        cout << "Bitte geben Sie eine Zahl ein!" << endl;
        cin >> prog_number;

        if(cin.fail()){
            return exit_handler(2);
        }

        if(prog_number != 1 && prog_number != 2){
            cout << "No valid program was chosen, try again!" << endl;
        }
        else if(prog_number == 2){
            cout << "Choosen 2" << endl;
            prog2();
            running = false;
        }
        else if(prog_number == 1) {
            cout << "Choosen 1" << endl;
            exit_handler(prog1());
            running = false;
        }
    }
}
void interface::exit_handler(int i){
    if(i == 0){
        cout << "Everything worked fine, quiting program." << endl;
        exit(0);

    }
    else if(i == 1){
        //sub program done!;
        return;
    }
    else if(i == 2){
        cout << "Some error occurred, redirecting to the main menu..." << endl;
        main_menu();
    }
}


int interface::prog1(){
    cout << "Enter '1' for a normal matrix, '2' for block matrix." << endl;
    int sub_prog;
    running = true;
    while(running){
        cin >> sub_prog;
        if(sub_prog == 1){
            exit_handler(prog1_sub1());
            return 0;
        }
        else if(sub_prog == 2){
            exit_handler(prog1_sub2());
            return 0;
        }
        else{return 2;}
    }

    return 2;

 };

int interface::prog2(){
    cout << "Program e started -- encryption can happen." << endl;
    NBild int_canvas;
    CBild char_canvas;
    string example_txtfile = "../ProgPrak1819/Qt_PP_1819_GUI/beispielbild_1.txt";

    vector < vector<int> > matrix = int_canvas.import_file(example_txtfile);
    vector < vector<char> > key = char_canvas.create_rand_picture(matrix.size(), matrix[0].size());
    vector < vector<char> > encrypted = char_canvas.encrypt_picture(matrix, key);
    char_canvas.print_certain_matrix(char_canvas.trans_block_int(encrypted));
    char_canvas.print_certain_matrix(matrix);
    char_canvas.print_certain_matrix(encrypted);
    char_canvas.print_certain_matrix(key);
    vector < vector<int > > decrypt = char_canvas.decrypt_picture(encrypted, key);
    char_canvas.print_certain_matrix(decrypt);
}


int interface::prog1_sub2(){
    int height;
    int width;

    CBild img;

    running = true;
    cout << "Please select the size of your random picture." << endl;
    while(running){
        cout << "What should your height be?" << endl;
        cin >> height;
        if(cin.fail()){
            return 2;
        }
        cout << "What should your width be?" << endl;
        cin >> width;
        if(cin.fail()){
            return 2;
        }
        running = false;
    }
    cout << "Building a randomised picture with size: " << height << " * " << width << endl;

    img.print_certain_matrix(img.create_rand_picture(height, width));

    return 0;
}

int interface::prog1_sub1(){
    int height;
    int width;

    NBild img;

    running = true;
    cout << "Please select the size of your random picture." << endl;
    while(running){
        cout << "What should your height be?" << endl;
        cin >> height;
        if(cin.fail()){
            return 2;
        }
        cout << "What should your width be?" << endl;
        cin >> width;
        if(cin.fail()){
            return 2;
        }
        running = false;
    }
    cout << "Building a randomised picture with size: " << height << " * " << width << endl;

    img.print_certain_matrix(img.create_rand_picture(height, width));

    return 0;
}
