// graph.cpp (implementation of class CellularAutomaton)
// Created by Andreas Haupt

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <assert.h>
#include "cellularautomaton.h"

CellularAutomaton::CellularAutomaton(std::size_t num_cols, std::size_t num_rows)
  : old_state_(num_cols, std::vector<bool>(num_rows, false)),
    new_state_(num_cols, std::vector<bool>(num_rows, false)),
    num_cols_(num_cols),
    num_rows_(num_rows) {}

// First, resize window to size needed with dead cells, then assign as needed.
CellularAutomaton::CellularAutomaton(std::string filename) {
  // Read one line and assign to num_rows_
  try{
    std::ifstream file(filename);
    if(not file) throw std::runtime_error("Cannot read file.");
    std::string line;
    std::getline(file,line);
    std::stringstream sstream_rows(line);
    if(not sstream_rows) throw std::runtime_error("Invalid file format.");
    sstream_rows >> num_rows_;
    // Read second line to num_cols_
    std::getline(file,line);
    std::stringstream sstream_cols(line);
    if(not sstream_cols) throw std::runtime_error("Invalid file format.");
    sstream_cols << line;
    sstream_cols >> num_cols_;
    // Read state char and assign conditionally
    char state;
    ResizeWindow(num_rows_, num_cols_);
    for(std::size_t i = 0; i < num_rows_; ++i)
    {
      // Read one line to file
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
  catch (const std::runtime_error& e) {
    std::cout << "Could not load file, please run constructor again." << e.what();
  }
}

void CellularAutomaton::set_cell_state(std::size_t row, std::size_t col, bool cell_state) {
  try {
    if (not (row < num_rows_ and col < num_cols_)) throw std::runtime_error("Index out of bound.");
    new_state_[row][col] = cell_state;
    CopyToOld(); 
  }
  catch (const std::runtime_error& e) {
    std::cout << "Invalid index, please enter index within bounds." << e.what();
  }
}

void CellularAutomaton::set_cell_state_no_copy(std::size_t row, std::size_t col, bool cell_state) { 
  assert (row < num_rows_ and col < num_cols_);
  new_state_[row][col] = cell_state; 
}

void CellularAutomaton::ChangeCellState(std::size_t row, std::size_t col) {
  set_cell_state(row, col, not cell_state(row,col));
  assert (row < num_rows_ and col < num_cols_);
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
          set_cell_state_no_copy(i,j,false);
        }
      } else {
        if(neighbor_num(i,j)==3) set_cell_state_no_copy(i,j,true);
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
  assert (i < num_rows_ and j < num_cols_);
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
      old_state_[i][j] = new_state_[i][j];
    }
  }
}