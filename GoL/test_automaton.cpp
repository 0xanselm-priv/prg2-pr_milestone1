#include <iostream>
#include <random>
#include <fstream>
#include <functional>
#include "cellularautomaton.h"

int main(int argc, char** argv){
	char option = '0';
	std::unique_ptr<CellularAutomaton> automaton;
	while (option!='q') {
		std::cout << "Bitte geben Sie eine der folgenden Optionen ein." << std::endl
				  << "q\tProgramm verlassen" << std::endl
				  << "o\tEine Datei öffnen" << std::endl
				  << "n\tEin 30x30-Feld von Toten Zellen initialisieren" << std::endl;
		std::string filename;
		std::cin.clear();
		std::cin >> option;
		switch (option){
			case 'q': 
				return 0;
			case 'n':
				automaton = std::unique_ptr<CellularAutomaton>(new CellularAutomaton(30, 30));
				break;
			case 'o':
				std::cout << "Bitte geben Sie den Dateinamen mit Endung ein." << std::endl;
				std::cin.clear();
				std::cin >> filename;
				try {
					automaton = std::unique_ptr<CellularAutomaton>(new CellularAutomaton(filename));
				}
				catch (std::runtime_error& e) {
					std::cout << "Lesefehler:" << e.what() << std::endl;
					continue;
				}
				catch (std::invalid_argument& e) {
					std::cout << "Unbekanntes Zeichen:" << e.what() << std::endl;
					continue;
				}
				break;
			default: 
				std::cout << "Ungültige Eingabe" << std::endl;
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
		std::cin.clear();
		std::cin >> option;
		switch (option) {
			case 'q': {
				return 0;
				break;
			}
			case 'r': {
				try {
					std::size_t num_rows, num_cols;
					std::cout << "Neue Anzahl Zeilen eingeben." << std::endl;
					std::cin.clear();
					std::cin >> num_rows;
					std::cout << "Neue Anzahl Spalten eingeben." << std::endl;
					std::cin.clear();
					std::cin >> num_cols;
					automaton->ResizeWindow(num_rows, num_cols);
					break;
				}
				catch (const std::exception& e) {
					std::cout << "Invalid input:" << e.what() << std::endl;
				}
			}
			case 's': {
				std::size_t row, col;
				char state;
				try {
					std::cout << "Zeile der Zelle eingeben." << std::endl;
					while(true) {
						std::cin.clear();
						if (std::cin >> row) 
							break;
						std::cout << "Falsche Eingabe." << std::endl;
					}
					std::cout << "Spalte der Zelle eingeben." << std::endl;
					while(true) {
						std::cin.clear();
						if (std::cin >> col) 
							break;
						std::cout << "Falsche Eingabe." << std::endl;
					}
					std::cout << "d für tot eingeben, a für lebendig, sonstige Eingabe ändert nichts." << std::endl;
					while(true) {
						std::cin.clear();
						if (std::cin >> state) 
							break;
						std::cout << "Falsche Eingabe." << std::endl;
					}
				}
				catch (const std::exception& e) {
					std::cout << "Invalid input:" << e.what() << std::endl;
				}
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
						std::cout << "Keine mögliche Option." << std::endl;
						break;
					}
				}		
				break;
			}
			case 'c': {
				std::size_t row, col;
				std::cout << "Zeile der Zelle eingeben." << std::endl;
				while(true) {
					std::cin.clear();
					if (std::cin >> row) 
						break;
					std::cout << "Falsche Eingabe." << std::endl;
				}
				std::cout << "Spalte der Zelle eingeben." << std::endl;
				while(true) {
					std::cin.clear();
					if (std::cin >> col) 
						break;
					std::cout << "Falsche Eingabe." << std::endl;
				}
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
				std::cin.clear();
				std::cin >> filename;
				std::cout << "Eingabe.";
				std::ofstream file(filename);
				if (not file) {
					std::cout << "Unable to open file" << std::endl;
					continue;
				}
				file << *automaton;	
				file.close();	
				break;
			}
			default: {
				std::cout << "Ungültige Eingabe" << std::endl;
				continue;
			}
		}
		std::cout << *automaton;
	}
}