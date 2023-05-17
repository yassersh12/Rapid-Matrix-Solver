#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;
void header();
void dataInput();
void solution();
void clearAll();
void footer();

int m, n;
int i, j, k;
char CONTINUE;
bool okInput[10][10];
float constant[10][10];
float temp;

int main()
{
start:
	header();
	cout << "Enter The Number of Equations: ";
	cin >> m;
	n = m + 1;
	cout << setprecision(3);
	dataInput();
	cout << endl;
	solution();
	cout << endl << endl;
	footer();
	
	cin >> CONTINUE;
	if (CONTINUE == 'Y' || CONTINUE == 'y') { clearAll(); goto start; }
	else return 0;
}

void header()
{
	cout << "************************************************************" << endl;
	cout << "|                                                          |" << endl;
	cout << "|               Gauss-Jordan Calculator                    |" << endl;
	cout << "|                                                          |" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}

void dataInput()
{
step1:
	system("cls");
	header();
	cout << "The Number Of Equations: " << m << endl;
	cout << endl;
	cout << "Enter The Constants: " << endl;
	cout << endl;
	cout << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "\t";
			if (j == n - 1) cout << "| ";
			if (okInput[i][j])
			{
				if (j == n - 1) cout << constant[i][j] << endl << endl;
				else cout << constant[i][j];
			}
			else {
				cin >> constant[i][j];
				okInput[i][j] = true;
				goto step1;
			}
		}
	}
}

void solution()
{
stepOne:
	for (k = 0; k < m; k++)
	{
		if (constant[k][k] != 1)
		{
			if (constant[k][k] == 0)
			{
				for (j = 0; j < n; j++)
				{
					temp = constant[k][j];
					constant[k][j] = constant[k + 1][j];
					constant[k + 1][j] = temp;
				}
				cout << "Exchange row" << k + 1 << " and row" << k + 2 << endl;
				goto stepTwo;
			}
			temp = constant[k][k];
			for (j = 0; j < n; j++) constant[k][j] /= temp;
		    cout << " Row " << k + 1 << " / (" << temp << ")" << endl;
			
			goto stepTwo;

		}
		for (i = 0; i < m; i++)
		{
			if (i != k)
			{
				if (constant[i][k] != 0)
				{
					temp = constant[i][k];
					for (j = 0; j < n; j++) constant[i][j] -= temp * constant[k][j];
					cout << " Row " << i + 1 << " - (" << temp << ") Row" << k + 1 << endl;
					if (i == m - 1) goto stepTwo;
				}
			}
		}
	}
 stepTwo:
	cout << endl << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (constant[i][j] == -0) constant[i][j] = 0;
			cout << "\t";
			if (j == n - 1) cout << "| ";
			cout << constant[i][j];
		}
		cout << endl << endl;
    }
	if (constant[m-1][n-2] == 0 && constant[m-1][n - 1] == 0)
	{
			cout << "The Linear system has Iinfintely Many Solution." << endl;
			return;
	}
	
	cout << endl;
	
    if (constant [m - 1][n - 1] == 1 || constant [m - 2][n - 2] == 0) return;
	else goto stepOne;
}
void clearAll()
{
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			okInput[i][j] = false;
		}
	}
	system("cls");
	
}

void footer()
{
	cout << "************************************************************" << endl;
	cout << "|                                                          |" << endl;
	cout << "|              Created By Karam Abu-Ghaboush               |" << endl;
	cout << "|           Type 'Y' to restart, otherwise exit            |" << endl;
	cout << "|                                                          |" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}