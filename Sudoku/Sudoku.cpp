#include"Sudoku.h"
Sudoku::Sudoku(int a[81]) {
	int k = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			x[j][i] = a[k++];
		}
	}
}
Sudoku::operator bool() {
	for (int i = 0; i < 9; i++) {
		bool a[10];
		for (int j = 0; j < 10; j++) {
			a[j] = false;
		}
		for (int j = 0; j < 9; j++) {
			if (x[i][j] != 0 && a[x[i][j]] == true) {
				return false;
			}
			else {
				a[x[i][j]] = true;
			}
		}
		for (int j = 0; j < 10; j++) {
			a[j] = false;
		}
		for (int j = 0; j < 9; j++) {
			if (x[j][i] != 0 && a[x[j][i]] == true) {
				return false;
			}
			else {
				a[x[j][i]] = true;
			}
		}
	}
	for (int l = 0; l < 3; l++) {
		for (int y = 0; y < 3; y++) {
			bool a[10];
			for (int j = 0; j < 10; j++) {
				a[j] = false;
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int * ll = &(x[y * 3 + j][l * 3 + i]);
					if (*ll != 0 && a[*ll] == true) {
						return false;
					}
					else {
						a[*ll] = true;
					}
				}
			}
		}
	}
	return true;
}
void Sudoku::print() {
	cout << *this;
}
int Sudoku::getProc() {
	int s = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (x[i][j] > 0) {
				s++;
			}
		}
	}
	return (int)((double)s / 0.81);
}
void Sudoku::printProc() {
	cout << " " << getProc() << "%\n";
}
int Sudoku::z() {
	int l = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (x[i][j] == 0) {
				l++;
			}
		}
	}
	return l;
}
void Sudoku::Solve() {
	bool q = true;
	while (q) {
		q = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (x[i][j] == 0) {
					int l = 0;
					for (int p = 1; p < 10; p++) {
						Sudoku asd(*this);
						asd.x[i][j] = p;
						if ((bool)asd) {
							if (l == 0) {
								l = p;
							}
							else {
								l = -1;
							}
						}
					}
					if (l == 0) {
						//cout << " Wrong Matrix\n\n ";
						//exit(0);
						return;
					}
					else if (l > 0) {
						x[i][j] = l;
						q = true;
					}
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int p = 1; p < 10; p++) {
				int l = 0;
				for (int j = 0; j < 9; j++) {
					Sudoku asd(*this);
					if (asd.x[i][j] == 0) {
						asd.x[i][j] = p;
						if ((bool)asd) {
							l++;
						}
					}
				}
				if (l == 1) {
					for (int j = 0; j < 9; j++) {
						Sudoku asd(*this);
						if (asd.x[i][j] == 0) {
							asd.x[i][j] = p;
							if ((bool)asd) {
								x[i][j] = p;
								//cout << " x:" << j << " y:" << i << " = " << p << endl;
								j = 9;
								p = 10;
								q = true;
							}
						}
					}
				}
			}
		}
	}
	if ((*this).getProc() != 100) {
		int min = 9, min_x, min_y;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (x[i][j] == 0) {
					int l = 0;
					for (int p = 1; p < 10; p++) {
						Sudoku asd(*this);
						asd.x[i][j] = p;
						if ((bool)asd) {
							l++;
						}
					}
					if (l < min) {
						min = l;
						min_x = i;
						min_y = j;
					}
				}
			}
		}
		Sudoku rty(*this);
		for (int p = 1; p < 10; p++) {
			Sudoku asd(*this);
			asd.x[min_x][min_y] = p;
			if ((bool)asd) {
				Sudoku zxc(asd);
				//cout << min_x + 1 << " " << min_y + 1 << endl;
				//zxc.print();
				//system("pause");
				zxc.Solve();
				if (rty.getProc() < zxc.getProc()) {
					rty = zxc;
				}
			}
		}
		*this = rty;
	}
}

ostream & operator << (ostream & out, Sudoku & s) {
	out << endl;
	for (int i = 0; i < 9; i++) {
		out << " ";
		for (int j = 0; j < 9; j++) {
			if (s.x[j][i] == 0) {
				out << "_";
			}
			else {
				out << s.x[j][i];
			}
			if (j % 3 == 2) {
				out << " ";
			}
		}
		out << endl;
		if (i % 3 == 2) {
			out << endl;
		}
	}
	return out;
}
