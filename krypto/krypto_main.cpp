//
// Created by Niels Heissel on 30.10.18.
//

#include <iostream>
#include <fstream>
#include <vector>
//#include "file_handler_class.h"
#include "NBild.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    NBild pic;
    //pic.set_path("/Users/nielsheissel/CLionProjects/untitled1/beispielbild_1.txt");
    pic.import_file("/Users/nielsheissel/CLionProjects/untitled1/beispielbild_1.txt");

    pic.print_matrix();

    return 0;
}
