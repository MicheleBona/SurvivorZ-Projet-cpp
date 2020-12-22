#include "passgrid.hh"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <fstream>
#include <random>
using namespace std;

// obtain a seed from the system clock:
std::default_random_engine PassGrid::_generator(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> PassGrid::_distribution(33,94);


PassGrid::PassGrid(const PassGrid & p)
{
	_w = p._w;
	_h = p._h;
}

PassGrid::PassGrid(std::size_t w, std::size_t h)
{
	_w = w; // _w = w;
	_h = h;
	grid = new char* [w]; // allocate the width of the grid
	for (size_t i = 0; i < w;  i++){
		grid[i] = new char[h]; // allocate the first column
	}
	//grid = new char [w][h];
	// let's fill this grid
	for (size_t i = 0; i < _w;  i++){
		for (size_t j = 0; j < _h; j++){
			grid[i][j] = (char) _distribution(_generator); // fill the column
		}
	}
}

PassGrid::~PassGrid()
{
	for (size_t i = 0; i < _w; i++)
    	delete [] grid[i];
	delete [] grid;
}


void PassGrid::save(std::ostream& out) const
{
   if (this -> grid != NULL)
	{
		//let's save the size of the grid first
		out << _w << endl;
		out << _h << endl;
		for (size_t i = 0; i < _h;  i++)
		{
			for (size_t j = 0; j < _w; j++)
			{
				out << grid[i][j];// print the line
			}
		} 
	}
}
void PassGrid::print() const
{
	if (this -> grid != NULL)
	{
		for (size_t i = 0; i < _h;  i++)
		{
			for (size_t w = 0; w < _w-1; ++w)
			{
				std::cout << "__";
			}
	  		std::cout << "__" << std::endl;
	  		std::cout << "|";
			for (size_t j = 0; j < _w; j++)
			{
				cout << grid[i][j] << "|";// print the line
			}
			cout << endl;
		}
		for (size_t w = 0; w < _w; ++w)
			{
				std::cout << "--";
		}
		cout << endl;
	}
}

void PassGrid::load(std::istream& in)
{
  if (this -> grid != NULL)
	{	
		// let's delete the old grid
		for (size_t i = 0; i < _w; i++)
    		delete [] grid[i];
		delete [] grid;
		// let's read the size of the new grid
		int w;
		int h;
		in >> w;
		in >> h;
		// let's allocate the new grid
		grid = new char* [w]; // allocate the width of the grid
		for (int i = 0; i < w;  i++){
			grid[i] = new char[h]; // allocate the first column
		}
		// let's load the new grid
		char caractere;
		// let's fill this grid
		for (int n = 0; n < w;  n++){
			for (int m = 0; m < h; m++){
				in >> caractere;
				grid[n][m] = caractere; 
			}
		}
	}
}

void PassGrid::reset()
{
	if (this -> grid != NULL)
	{
		for (size_t i = 0; i < _w;  i++){
			for (size_t j = 0; j < _h; j++){
				grid[i][j] = (char) _distribution(_generator); // fill the column
			}
		}
	}
}


std::string PassGrid::generate(const Path& p)const
{	
	string password;
	if (this -> grid != NULL)
	{	
		//size_t w = p.getMaxX();
		//size_t h = p.getMaxY();
		size_t x = p.getStartX();
		size_t y = p.getStartY();
		size_t n = p.getSize();
		cout << grid[x][y] << endl;
		for (size_t  i = 0; i < n; i++){
			switch(p(i)) {
				case 0:
					x--;
					break;
				case 1: 
					y++;
					x--;
					break;
				case 2: 
					y--;
					x--;
					break;
				case 3: 
					x++;
					break;
				case 4: 
					y++;
					x++;
					break;
				case 5: 
					y--;
					x++;
					break;
				case 6: 
					y++;
					break;
				case 7: 
					y--;
					break;
			}
			cout << grid[x][y] << endl;
		}
	}
	return password;		
}

void PassGrid::fillPG()
{
	/*srand((unsigned)time(0));
	rand()%((94-33)+33);*/
	for (size_t i = 0; i < _w;  i++){
		for (size_t j = 0; j < _h; j++){
			grid[i][j] = (char) _distribution(_generator); // fill the column
		}
	}
}

//getter
std::size_t PassGrid::getW() const {return this -> _w;}
std::size_t PassGrid::getH() const {return this -> _h;}
char PassGrid::operator()(size_t i, size_t j) const {return this -> grid[i][j];}

