#include <bits/stdc++.h>
using namespace std;

const int INF = -1e8 + 5;

int rev[100][100];
int s[100][100];

int chocolate_cut(int price[100][100], int col, int row)
{

	if (rev[row][col] >= 0)
		return rev[row][col];

	int horizontal, vertical;

	if (row == 0)
		horizontal = 0;
	else
	{
		horizontal = INF;

		for (int i = 1; i <= row; i++)
		{
			int x = price[i][col] + chocolate_cut(price, col, row - i);
			if (horizontal < x) horizontal = x;
		}
	}

	if (col == 0)
	{
		vertical = 0;
	}

	else
	{
		vertical = INF;

		for (int i = 1; i <= col; i++)
		{
			int y = price[row][i] + chocolate_cut(price, col - i, row);
			if (vertical < y) vertical = y;
		}
	}

	rev[row][col] = max(horizontal, vertical);
	return rev[row][col];
}

int main()
{

	freopen("in.txt", "r", stdin);

	int row, col, price[100][100];
	cin >> row >> col;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cin >> price[i][j];
		}
	}

	for (int i = 0; i <= row; i++)
		rev[i][0] = 0;
	for (int i = 0; i <= col; i++)
		rev[0][i] = 0;

	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			rev[i][j] = -1;
		}
	}

	int max_rev = chocolate_cut(price, col, row);
	cout << "MAX REVENUE: " << max_rev << endl;
}