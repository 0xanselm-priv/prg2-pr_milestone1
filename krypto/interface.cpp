//
// Created by Niels Heissel on 05.11.18.
//

#include "interface.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>


vector < vector<int> > interface::create_rand_picture(int height, int width){
    this->height = height;
    this->width = width;
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

void interface::print_matrix() {
    cout << "Printing!" << endl << endl;
    // See that matrix is loaded with all information.
    for(int x = 0; x < height; x++){
        for(int y = 0; y < width; y++){
            cout << matrix1[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

int interface::main_menu(){
    running = true;
    while(running){
        prog_number = 0;

        cout << "Bitte geben Sie eine Zahl ein!" << endl;
        cin >> prog_number;

        if(prog_number != 1 && prog_number != 2){
            cout << "No valid program was chosen, try again!" << endl;
        }
        else if(prog_number == 2){
            cout << "Choosen 2" << endl;
            running = false;
        }
        else if(prog_number == 1) {
            cout << "Choosen 1" << endl;
            running = false;
        }
    }
}

void interface::prog_handler(int){}

int interface::prog1(){
    running = true;
 }

int interface::prog2(){}

void interface::exit_handler(int){}*/
