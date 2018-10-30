//
// Created by Niels Heissel on 30.10.18.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    ifstream file;
    file.open("/Users/nielsheissel/CLionProjects/untitled1/beispielbild_1.txt");

    if(file.fail()){
        cout << "Reading file failed!" << endl;
        exit(0);
    }



    int height = 0;
    int length;
    string teststring;
    //count length and height of matrix
    while(!file.eof()){
        height ++;
        file >> teststring;
        length = teststring.length();
    }

    file.close();

    cout << "Lenght: " << length << "; Height: " << height << endl;




    file.open("/Users/nielsheissel/CLionProjects/untitled1/beispielbild_1.txt");


    string line;
    int counter {0};
    int matrix[height][length];

    while(!file.eof()){
        file >> line;
        cout << line << endl;

        int l = 0;
        while(l < line.length()){
            int m = stoi(line.substr(l,1));
            matrix[counter][l] = m;
            ++l;
        }
        counter++;
    }

    file.close();

    cout << "You have lines: " << counter << endl;
    cout << "Items: " << line << " with the size of " << line.length() << endl;





    // See that matrix is loaded with all information.
    for(int x = 0; x < height; x++){
        for(int y = 0; y < length; y++){
            cout << matrix[x][y];
        }
        cout << endl;
    }

    cout << endl;


    return 0;
}
