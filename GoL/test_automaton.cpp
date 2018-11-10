#include <iostream>
#include <random>
#include <fstream>
#include <functional>
#include "cellularautomaton.h"

using namespace std;

int main(int argc, char** argv){
	char option = '0';
	std::unique_ptr<CellularAutomaton> automaton;
	while (option!='q') {
		std::cout << "Bitte geben Sie eine der folgenden Optionen ein." << std::endl
				  << "q\tProgramm verlassen" << std::endl
				  << "o\tEine Datei öffnen" << std::endl
				  << "n\tEin 30x30-Feld von Toten Zellen initialisieren" << std::endl;
		std::string filename;
		std::cin >> option;
		switch (option){
			case 'q': 
				return 0;
			case 'n':
				automaton = std::unique_ptr<CellularAutomaton>(new CellularAutomaton(30, 30));
				break;
			case 'o':
				std::cout << "Bitte geben Sie den Dateinamen mit Endung ein." << std::endl;
				std::cin >> filename;
				automaton = std::unique_ptr<CellularAutomaton>(new CellularAutomaton(filename));
				break;
			default: 
				cout << "Ungültige Eingabe";
				continue;
		}
		break;
	}
	option = '0';
	while (option != 'q'){
		std::cout << "Bitte geben Sie eine der folgenden Optionen ein." << std::endl 
			 << "q\tProgramm verlassen" << std::endl
			 << "r\tFeldgroesse aendern" << std::endl
			 << "s\tDen Inhalt einer Zelle setzen" << std::endl
			 << "c\tDen Inhalt einer Zelle ändern" << std::endl
			 << "u\tDas Spielfeld um einen Schritt updaten" << std::endl
			 << "e\tDie Änderungen in einer Datei speichern." << std::endl;
		cin >> option;
		switch (option) {
			case 'q': {
				return 0;
				break;
			}
			case 'r': {
				std::size_t num_rows, num_cols;
				std::cout << "Neue Anzahl Zeilen eingeben.";
				std::cin >> num_rows;
				std::cout << "Neue Anzahl Spalten eingeben.";
				std::cin >> num_cols;
				automaton->ResizeWindow(num_rows, num_cols);
				break;
			}
			case 's': {
				std::size_t row, col;
				char state;
				std::cout << "Zeile der Zelle eingeben.";
				std::cin >> row;
				std::cout << "Spalte der Zelle eingeben.";
				std::cin >> col;
				std::cout << "d für tot eingeben, a für lebendig, sonstige Eingabe ändert nichts.";
				std::cin >> state;
				switch (state) {
					case 'd': {
						automaton->set_cell_state(row, col, false);
						break;
					}
					case 'a': {
						automaton->set_cell_state(row, col, true);
						break;
					}
					default: {
						break;
					}
				}		
				break;
			}
			case 'c': {
				std::size_t row;
				std::size_t col;
				std::cout << "Zeile der Zelle eingeben.";
				std::cin >> row;
				std::cout << "Spalte der Zelle eingeben.";
				std::cin >> col;
				automaton->ChangeCellState(row, col);
				break;
			}			
			case 'u': {
				automaton->Update();		
				break;
			}
			case 'e': {
				std::cout << "Enter filename." << std::endl;
				std::string filename;
				std::cin >> filename;
				std::cout << "Eingabe.";
				std::ofstream file(filename);
				if (not file) {
					throw std::runtime_error("Unable to open file.");
				}
				file << *automaton;	
				file.close();	
				break;
			}
			default: {
				cout << "Ungültige Eingabe";
				continue;
			}
		}
		std::cout << *automaton;
	}
}