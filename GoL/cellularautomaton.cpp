// graph.cpp (implementation of class Graph)

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include "cellularautomaton.h"

CellularAutomaton::CellularAutomaton(std::size_t num_cols, std::size_t num_rows)
: _oldState(num_cols, std::vector<bool>(num_rows, false)),
_newState(num_cols, std::vector<bool>(num_rows, false)),
_num_cols(num_cols),
_num_rows(num_rows){}

std::size_t CellularAutomaton::num_rows() const
{
	return _num_rows;
}

std::size_t CellularAutomaton::num_cols() const
{
	return _num_cols;
}

std::ostream& operator<<(std::ostream& os, const CellularAutomaton& automaton)
{
	os << automaton.num_rows() << std::endl 
	   << automaton.num_cols() << std::endl;
	for (std::vector<bool> row : automaton.newState())
	{
		for(bool state : row)
		{
			state ? os << '*' : os << 'o';
		}
		os << std::endl;
	}
	return os;
}

CellularAutomaton::CellularAutomaton(){}

void CellularAutomaton::load(std::string filename) {
	std::cout << "Arrived.";
	CellularAutomaton a(filename);
	SetoldState(a.oldState());
	SetnewState(a.newState());
	SetnumCols(a.num_cols());
	SetnumRows(a.num_rows());
}

void CellularAutomaton::SetnumRows(std::size_t num_rows)
{
	_num_rows = num_rows;
}

void CellularAutomaton::SetnumCols(std::size_t num_cols)
{
	_num_cols = num_cols;
}

CellularAutomaton::MatrixType CellularAutomaton::oldState() const
{
	return _oldState;
}

CellularAutomaton::MatrixType CellularAutomaton::newState() const
{
	return _newState;
}

void CellularAutomaton::SetoldState(MatrixType oldState)
{
	_oldState = oldState;
}
   
void CellularAutomaton::SetnewState(MatrixType newState)
{
	_newState = newState;
}

unsigned int CellularAutomaton::_neighbor_num(std::size_t i, std::size_t j) const
{
	unsigned int a = 
	  (int) _oldState[i][(j+1)%_num_cols]
	+ (int) _oldState[(i+1)%_num_rows][(j+1)%_num_cols]
	+ (int) _oldState[(i+1)%_num_rows][j]
	+ (int) _oldState[(i+1)%_num_rows][(j-1)%_num_cols]
	+ (int) _oldState[i][(j-1)%_num_cols]
	+ (int) _oldState[(i-1)%_num_rows][(j-1)%_num_cols]
	+ (int) _oldState[(i-1)%_num_rows][j]
	+ (int) _oldState[(i-1)%_num_rows][(j+1)%_num_cols];
	
	return a;
}

void CellularAutomaton::update()
{
	CopyToOld();
	for(int i = 0; i<_num_rows; ++i)
	{
		for(int j = 0; j<_num_cols; ++j)
		{
			if(_newState[i][j])
			{
				if(_neighbor_num(i,j) !=2 and _neighbor_num(i,j) !=3) SetCell(i,j,false);
			}
			else
			{
				if(_neighbor_num(i,j)==3) SetCell(i,j,true);
			}
		}
	}
}

void CellularAutomaton::resize(std::size_t rows, std::size_t cols){
	for(std::vector<bool> &x : _oldState)
	{
		x.resize(cols, false);
	}
	std::vector<bool> extend_rows_col(cols, false);
	_oldState.resize(rows, extend_rows_col);
	for(std::vector<bool> &x : _newState)
	{
		x.resize(cols, false);
	}
	std::vector<bool> extend_cols_row(cols, false);
	_newState.resize(rows, extend_cols_row);
	_num_rows = rows;
	_num_cols = cols;
}

void CellularAutomaton::SetCell(std::size_t row, std::size_t col, bool state)
{
	if(row < _num_rows and col < _num_cols)
	{
		_newState[row][col] = state;
	}
	else
	{
		throw std::runtime_error("Accessing inexistant index.");
	}
}

void CellularAutomaton::CopyToOld()
{
	for(std::size_t i = 0; i < _num_rows; ++i)
	{
		for(std::size_t j = 0; j < _num_cols; ++j)
		{
			_oldState[i][j] = _newState[i][j];
		}
	}
}

bool CellularAutomaton::GetState(std::size_t row, std::size_t col) const
{
	if(row < _num_rows and col < _num_cols)
	{
		return _oldState[row][col];
	}
	else
	{
		throw std::runtime_error("Accessing inexistant index.");
	}
}

void CellularAutomaton::ChangeState(std::size_t row, std::size_t col)
{
		SetCell(row, col, not GetState(row,col));
}

CellularAutomaton::CellularAutomaton(std::string filename)
{
	std::ifstream file(filename);
	if (not file) 
	{
		throw std::runtime_error("Unable to open file.");
	}
	std::string line;
	std::getline(file,line);
	std::stringstream sstream_rows(line);
	sstream_rows >> _num_rows;
	std::getline(file,line);
	std::stringstream sstream_cols(line);
	sstream_cols << line;
	sstream_cols >> _num_cols;
	char state;
	resize(_num_rows, _num_cols);
	for(std::size_t i = 0; i < _num_rows; ++i)
	{
		std::getline(file, line);
		std::stringstream sstream(line);
		if(not sstream) throw std::runtime_error("Invalid file format.");
		for(std::size_t j = 0; j < _num_cols; ++j)
		{
			sstream >> state;
			if(state != 'o' and state != '*')
			{
				throw std::runtime_error("Invalid symbol.");
			}
			state == '*' ? SetCell(i, j, true) : SetCell(i, j, false) ;
		}
	}
	CopyToOld();
	file.close();
}
