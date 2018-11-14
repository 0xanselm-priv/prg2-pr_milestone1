// cellularautomaton.h (declaration of class CellularAutomaton)
#ifndef CELLULAR_AUTOMATON_H
#define CELLULAR_AUTOMATON_H

#include <iostream>
#include <vector>

// Implements Conway's Game of Life
// Example:
// 	  CellularAutomaton automaton("input_file.txt");
// 	  automaton.resize(5,5);
// 	  automaton.update;
// 	  std::cout << automaton;
class CellularAutomaton{
 public:
  // Initialise all cells to false.
  explicit CellularAutomaton(std::size_t num_rows, std::size_t num_cols);
  explicit CellularAutomaton(std::string filename);

  void set_cell_state(std::size_t row, std::size_t col, bool cell_state);

  std::size_t num_rows() const { return num_rows_; }
  std::size_t num_cols() const { return num_cols_; }
  bool cell_state(std::size_t row, 
  	std::size_t col) const { return old_state_[row][col]; }
  // Change cell state false -> true resp. true -> false
  void ChangeCellState(std::size_t, std::size_t);
  // Resize window to given dimensions
  void ResizeWindow(std::size_t, std::size_t);
  // Advance Cellular Automaton by one round.
  void Update();
  friend std::ostream& operator<<(std::ostream& os, const CellularAutomaton& automaton);
 private:
	void CopyToOld();
	// return number of neighbors with value true
	int neighbor_num(std::size_t i, std::size_t j) const;
	// Set cell value, but do not copy to temporary array
	void set_cell_state_no_copy(std::size_t row, 
		std::size_t col, bool cell_state);
	// old_state_ and new_state_ only differ during update.
	std::vector< std::vector<bool> > old_state_;
	std::vector< std::vector<bool> > new_state_;
	std::size_t num_rows_;
	std::size_t num_cols_;
};
#endif