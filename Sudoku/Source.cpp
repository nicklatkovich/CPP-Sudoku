#include"Sudoku.h"
#include <time.h>
#include<fstream>

void main() {
	int a[81];
	ifstream input("INPUT.TXT");
	for (int i = 0; i < 81; i++) {
		input >> a[i];
	}
	int t = time(0);
	Sudoku qwe(a);
	cout << qwe;
	qwe.printProc();
	qwe.Solve();
	cout << qwe;
	cout << " " << time(0) - t << " sec\n\n ";
	system("pause");
}