#pragma once
#include <bits/stdc++.h>

using namespace std;

class Grid {
	public:
		void show();
		Grid(int ni);
		int getColIndex(int index);
		int getRowIndex(int index);
		void transposing(void);
		void swap_rows_small(void);
		void swap_colums_small(void);
		void swap_rows_area(void);
		void swap_colums_area(void);
		void mix(void);
		void del(int diff);
		void insert(int i, char c);
		void erase(int i);
		bool isCellReadonly(int i);
		bool checkCorrectRow(int i, int c);
		bool checkCorrectColumn(int i, int c);
		bool checkCorrectSector(int i, int c);
		bool isSudocuCompleted1();
		bool isSudocuCompleted2();
		bool isGameWon(int typegame);
		int n;
		vector < int > table;
		vector < bool > allowedCells;

		~Grid();	
};
