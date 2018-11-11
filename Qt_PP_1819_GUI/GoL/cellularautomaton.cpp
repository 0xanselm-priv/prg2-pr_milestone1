// graph.cpp (implementation of class CellularAutomaton)

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "cellularautomaton.h"

CellularAutomaton::CellularAutomaton(std::size_t num_cols, std::size_t num_rows)
	: old_state_(num_cols, std::vector<bool>(num_rows, false)),
	  new_state_(num_cols, std::vector<bool>(num_rows, false)),
	  num_cols_(num_cols),
	  num_rows_(num_rows) {}

CellularAutomaton::CellularAutomaton(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	std::getline(file,line);
	std::stringstream sstream_rows(line);
	sstream_rows >> num_rows_;
	std::getline(file,line);
	std::stringstream sstream_cols(line);
	sstream_cols << line;
	sstream_cols >> num_cols_;
	char state;
	ResizeWindow(num_rows_, num_cols_);
	for(std::size_t i = 0; i < num_rows_; ++i)
	{
		std::getline(file, line);
		std::stringstream sstream(line);
		if(not sstream) throw std::runtime_error("Invalid file format.");
		for(std::size_t j = 0; j < num_cols_; ++j)
		{
			sstream >> state;
			if(state != 'o' and state != '*')
			{
				throw std::runtime_error("Invalid symbol.");
			}
			state == '*' ? set_cell_state(i, j, true) : set_cell_state(i, j, false) ;
		}
	}
	CopyToOld();
	file.close();
}

void CellularAutomaton::ChangeCellState(std::size_t row, std::size_t col) {
		set_cell_state(row, col, not cell_state(row,col));
}

// Rezise Window, repeat for old and new state
void CellularAutomaton::ResizeWindow(std::size_t rows, std::size_t cols) {
	num_rows_ = rows;
	num_cols_ = cols;
	for(std::vector<bool> &x : old_state_) {
		x.resize(cols, false);
	}
	std::vector<bool> extend_rows_col(cols, false);
	old_state_.resize(rows, extend_rows_col);
	for(std::vector<bool> &x : new_state_) {
		x.resize(cols, false);
	}
	std::vector<bool> extend_cols_row(cols, false);
	new_state_.resize(rows, extend_cols_row);
	
}


void CellularAutomaton::Update() {
	CopyToOld();
	for (int i = 0; i < num_rows_; ++i) {
		for (int j = 0; j < num_cols_; ++j) {
			if (old_state_[i][j]) {
				if(neighbor_num(i,j) != 2 && neighbor_num(i,j) != 3) 
				{
					set_cell_state(i,j,false);
				}
			} else {
				if(neighbor_num(i,j)==3) set_cell_state(i,j,true);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& os, const CellularAutomaton& automaton) {
	os << automaton.num_rows() << std::endl 
	   << automaton.num_cols() << std::endl;
	for (int i = 0; i < automaton.num_rows(); ++i) {
		for (int j = 0; j < automaton.num_cols(); ++j) {
			automaton.cell_state(i, j) ? os << '*' : os << 'o';
		}
		os << std::endl;
	}
	return os;
}

int CellularAutomaton::neighbor_num(std::size_t i, std::size_t j) const {
	return (int) old_state_[i][(j+1)%num_cols()]
	+ (int) old_state_[(i+1)%num_rows()][(j+1)%num_cols()]
	+ (int) old_state_[(i+1)%num_rows()][j]
	+ (int) old_state_[(i+1)%num_rows()][(j-1)%num_cols()]
	+ (int) old_state_[i][(j-1)%num_cols()]
	+ (int) old_state_[(i-1)%num_rows()][(j-1)%num_cols()]
	+ (int) old_state_[(i-1)%num_rows()][j]
	+ (int) old_state_[(i-1)%num_rows()][(j+1)%num_cols()];
}

void CellularAutomaton::CopyToOld() {
	for (std::size_t i = 0; i < num_rows_; ++i) {
		for (std::size_t j = 0; j < num_cols_; ++j) {
			old_state_[i][j] = old_state_[i][j];
		}
	}
}
