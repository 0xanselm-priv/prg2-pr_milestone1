#include <iostream>
#include <random>

using namespace std;

int main(int argc, char** argv){
	char option = ' ';
	int rows = 30;
	int cols = 30;
	int **pa2d = new int*[rows];
	for (int i = 0; i < rows; ++i){
		pa2d[i] = new int[cols];
	}
	vector<int> pa1d(rows*cols);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> uniform(1,9);
	while (option != 'q'){
		cout << "Bitte geben Sie eine der folgenden Optionen ein." << endl 
			 << "q\tProgramm verlassen" << endl
			 << "n\tEin 2D-Array zufällig initialisieren." << endl
			 << "c\tInhalt vom 2-dimensionalen in ein eindimensionales Array kopieren." << endl
			 << "p\tDie beiden Arrays ausgeben." << endl;
		cin >> option;
		switch (option){
			case 'q': 
				return 0;
				break;
			case 'n':
				for (int i = 0; i < rows; ++i){
					for (int j = 0; j < rows; ++j){
						pa2d[i][j] = uniform(gen);
					}
				}
				break;
			case 'c': 	
				for(int i = 0; i < 30; ++i){
					for(int j = 0; j < 30; ++j){
						pa1d[rows*i+j] = pa2d[i][j];
					}
				}
				break;
			case 'p':	
				cout << "Zweidimensionales Array" << endl;
				for(int i=0; i<30; ++i){
					for(int j=0; j<30; ++j){
						cout << pa2d[i][j];
					}
					cout << endl;
				}
				cout << "Eindimensionales Array" << endl;
				for(int i=0; i<30; ++i){
					for(int j=0; j<30; ++j){
						cout << pa1d[rows*i + j];
					}
					cout << endl;
				}
				break;
			default: 
				cout << "Ungültige Eingabe";
				continue;
				break;
		}
	}
}