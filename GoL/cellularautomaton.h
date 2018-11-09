// cellularautomaton.h (declaration of class CellularAutomaton)
#ifndef CELLULAR_AUTOMATON_H
#define CELLULAR_AUTOMATON_H

#include <iostream>
#include <vector>

class CellularAutomaton{
public:
	using MatrixType = std::vector< std::vector<bool> >;

	CellularAutomaton(std::size_t num_rows, std::size_t num_cols);
    CellularAutomaton(std::string filename);
    CellularAutomaton();

    void SetoldState(MatrixType oldState);
    void SetnewState(MatrixType newState);
    void SetnumRows(std::size_t num_rows);
    void SetnumCols(std::size_t num_cols);
    void SetCell(std::size_t, std::size_t, bool);
    void ChangeState(std::size_t, std::size_t);

    MatrixType oldState() const;
    MatrixType newState() const;
    std::size_t num_rows() const;
	std::size_t num_cols() const;
	void exportState(std::string filename) const;
	bool GetState(std::size_t row, std::size_t col) const;

	void resize(std::size_t, std::size_t);
	void load(std::string filename);
	void update();

	friend std::ostream& operator<<(std::ostream& os, const CellularAutomaton& automaton);
private:
	void CopyToOld();
	unsigned int _neighbor_num(std::size_t i, std::size_t j) const;
	CellularAutomaton::MatrixType _oldState;
	CellularAutomaton::MatrixType _newState;
	std::size_t _num_rows;
	std::size_t _num_cols;
};
#endif