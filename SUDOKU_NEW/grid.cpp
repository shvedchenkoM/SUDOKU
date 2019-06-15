#include "grid.h"

using namespace std;

Grid::Grid(int ni)
{
    srand(time(NULL));
	
	n = ni;
    table.resize(n*n*n*n);
	allowedCells.resize(n*n*n*n);
	
    for(int i = 0; i<n*n; i++)
    {
	    for(int j = 0; j<n*n; j++)
	    {
		    table[i*n*n+j] = (i*n + i/n +j) % (n*n) + 1; 	    
	        allowedCells[i*n*n+j] = false;
		}
    }
} 	

int Grid::getRowIndex(int index)
{
	return (index/(n*n));
}

int Grid::getColIndex(int index)
{
	return (index%(n*n));
}

void Grid::show()
{
	for(int i = 0; i<n*n*n*n; i++)
	{
		if(i % (n*n) == 0)
		{
			cout << endl;
		}
		cout <<table[i]<<" ";
	}
	cout <<endl;
}

void Grid::transposing()
{
	for(int i = 0; i<n*n; i++)
	{
		for(int j = i; j<n*n; j++)
		{
			if (i != j)
			{
				int t = table[i*n*n+j];
				table[i*n*n+j] = table[j*n*n+i];
				table[j*n*n+i] =t;
				//swap(table[i*n*n+j], table[j*n*n+i]);
			}
		}
	}
      
}

void Grid::swap_rows_small()
{
	int area = rand() % n;
	int line1 = rand() % n;
	int N1 = area*n+line1;
	int line2 = rand() % n;
	while(line1 == line2)
	{
		line2 = rand() % n;
	}
	int N2 = area * n + line2;
        for(int i = 0; i<n*n; i++)
	{
		int t = table[N1*n*n+i];
		table[N1*n*n+i] = table[N2*n*n+i];
		table[N2*n*n+i] = t;
	}

}

void Grid::swap_colums_small()
{
	transposing();
	swap_rows_small();
	transposing();
}

void Grid::swap_rows_area()
{
	int area1 = rand() % n;
	int area2 = rand() % n;
	while(area1 == area2)
	{
		area2 = rand() % n;
	}
	for(int j = 0; j<n; j++)
	{
		int N1 = area1*n+j;
		int N2 = area2*n+j;
		for(int i = 0; i<n*n; i++)
	        {
			int t = table[N1*n*n+i];
                	table[N1*n*n+i] = table[N2*n*n+i];
                	table[N2*n*n+i] = t;
    		}

	}
}

void Grid::swap_colums_area()
{
	transposing();
	swap_rows_area();
	transposing();
}

void Grid::mix()
{
	int p = rand() % 100;
	for(int i = 0; i<p; i++)
	{
		int r = rand() % 5;
		if(r == 0) transposing();
		if(r == 1) swap_rows_small();
		if(r == 2) swap_colums_small();
		if(r == 3) swap_rows_area();
		if(r == 4) swap_colums_area();
	}
}

void Grid::del(int diff)
{
	for(int t = 0; t< diff; t++)
	{
		int i = rand() % (n*n);
		int j = rand() % (n*n);
		table[i*n*n+j] = 0;
		allowedCells[i*n*n+j] = true;
	}
	
}

bool Grid::isCellReadonly(int i)
{
	return allowedCells[i];
}
bool Grid::checkCorrectRow(int i, int c)
{
	int col = i % (n*n);
	int f = 0;
	int digit = c - 26;
	int row = i / (n*n);
	for(int k = row*n*n; k<(row+1)*n*n; k++)
	{
		if (table[k] == digit) 
		{
			cout <<"row "<<digit<<" "<<getRowIndex(k)<<" "<<getColIndex(k)<<endl;
			return false;
			f++;
		}
	}
	
	if (f == 0) return true;
	
}

bool Grid::checkCorrectColumn(int i, int c)
{
	int digit = c - 26;
	int col = i % (n*n);
	int row = i / (n*n);
	for(int k = 0; k<(n*n); k++)
    {
        if (table[k*n*n+col] == digit) 
		{
			cout <<"Col "<<digit<<" "<<k<<" "<<col<<endl;
			return false;
		}
    }
	return true;
}

bool Grid::checkCorrectSector(int i, int c)
{
	int digit = c - 26;
	int col = i % (n*n);
	int row = i / (n*n);
	int Scol = col / n;
	int Srow = row / n;
	
	for(int i = Srow*n; i<(Srow+1)*n; i++)
	{
		for(int j = Scol*n; j<(Scol+1)*n; j++)
		{
			//cout <<table[i*n*n+]
			if (table[i*n*n+j] == digit) 
			{
				cout <<"Sec "<<digit<<" "<<j<<" "<<i<<endl;
				return false;
			}		
		}
	}

	return true;
}

bool Grid::isSudocuCompleted1()
{
	for(int i = 0; i<n*n*n*n; i++)
	{
		if(table[i]==0) return false;
	}
	return true;
}

bool Grid::isSudocuCompleted2()
{
	for(int i = 0; i<n*n; i++)
	{
		int s1 = 0;
		int s2 = 0;
		for(int j = 0; j<n*n; j++)
		{
			s1 += table[i*n*n+j];
			s2 += table[j*n*n+i];
		}
		if(s1!=45 || s2 !=45) return false;
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			int s3 = 0;
			for(int k = i*n; k<(i+1)*n; k++)
			{
				for(int l = j*n; l<(j+1)*n; l++)
				{
					s3+=table[k*n*n+l];
				}
			}
			if(s3 != 45) return false;
		}
	}
	return true;
}

bool Grid::isGameWon(int typegame)
{
	if(typegame == 1) return isSudocuCompleted1();
	if(typegame == 2) return isSudocuCompleted2();
}


Grid::~Grid()
{
}



