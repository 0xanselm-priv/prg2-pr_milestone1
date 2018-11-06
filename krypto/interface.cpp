//
// Created by Niels Heissel on 05.11.18.
//

#include "interface.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;


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
            running = false;
        }
        else if(prog_number == 1) {
            cout << "Choosen 1" << endl;
            exit_handler(prog1());
            running = false;
        }
    }
}


//void interface::prog_handler(int){}

int interface::prog1(){
    running = true;
    cout << "Please select the size of your random picture." << endl;
    while(running){
        cout << "What should your height be?" << endl;
        cin >> this->height;
        if(cin.fail()){
            return 2;
        }
        cout << "What should your width be?" << endl;
        cin >> this->width;
        if(cin.fail()){
            return 2;
        }
        running = false;
    }
    cout << "Building a randomised picture with size: " << this->height << " * " << this->width << endl;

    create_rand_picture(this->height, this->width);
    print_matrix();

    return 0;
 };

//int interface::prog2(){}

void interface::exit_handler(int i){
    if(i == 0){
        cout << "Everything worked fine, quiting program." << endl;
        exit(0);

    }
    else if(i == 2){
        cout << "Some error occurred, redirecting to the main menu..." << endl;
        main_menu();
    }
}
