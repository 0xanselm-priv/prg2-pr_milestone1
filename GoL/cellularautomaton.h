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
  // Sets all cells to dead.
  explicit CellularAutomaton(std::size_t num_rows, std::size_t num_cols);
  explicit CellularAutomaton(std::string filename);
  void set_cell_state(std::size_t row, std::size_t col, bool cell_state);
  std::size_t num_rows() const { return num_rows_; }
	std::size_t num_cols() const { return num_cols_; }
  bool cell_state(std::size_t row, 
  	std::size_t col) const { return old_state_[row][col]; }
  void ChangeCellState(std::size_t, std::size_t);
	void ResizeWindow(std::size_t, std::size_t);
	// Advance Cellular Automaton by one round.
	void Update();
	friend std::ostream& operator<<(std::ostream& os, const CellularAutomaton& automaton);
 private:
	void CopyToOld();
	int neighbor_num(std::size_t i, std::size_t j) const;
	// Sets cell value, but does not copy to temporary array
	void set_cell_state_no_copy(std::size_t row, 
		std::size_t col, bool cell_state) { new_state_[row][col] = cell_state; }
	std::vector< std::vector<bool> > old_state_;
	std::vector< std::vector<bool> > new_state_;
	std::size_t num_rows_;
	std::size_t num_cols_;
};
#endif