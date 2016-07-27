#pragma once
#include<iostream>
using namespace std;
class Sudoku {
	int x[9][9];
	int z();
public:
	Sudoku(int a[81]);
	operator bool();
	void print();
	int getProc();
	void printProc();
	void Solve();
	friend ostream & operator << (ostream & out, Sudoku & s);
};