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

int main() {
    std::cout << "Hello, World!" << std::endl;

    CBild pic;
    //pic.set_path("/Users/nielsheissel/CLionProjects/untitled1/beispielbild_1.txt");
    pic.import_file("/Users/nielsheissel/CLionProjects/untitled1/beispielbild_1.txt");

    pic.print_matrix();


    interface interf;
    interf.main_menu();
    return 0;
}
