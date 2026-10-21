/*
	
	Input formate:
	Enter the length of rod to be cut
	
	Output formate:
	Maximum revenue
	Optimal cutting sequence
	
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = -1e5 + 5;

int s[100];
int r[100];

void rod_cut(int p[], int n)
{
	r[0] = 0;

	for (int j = 1; j <= n; j++)
	{
		int q = INF;

		for (int i = 1; i <= j; i++)
		{
			if (q < p[i - 1] + r[j - i])
			{
				q = p[i - 1] + r[j - i];

				s[j] = i;
			}
		}

		r[j] = q;
	}
}

void Print_Cut_Rod_Solution(int p[], int n)
{
	while (n > 0)
	{
		cout << s[n] << " ";
		n -= s[n];
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int price[] = { 1, 5, 8, 9, 10, 12, 17 };
	int n = sizeof(price) / sizeof(price[0]);

	int len;
	//cout << "Enter the length to be cut: ";
	cin >> len;

	if (len > n)
	{
		cout << "Invalid Input. Length should be less than the size of price list (n)";
	}
	else
	{
		rod_cut(price, n);
		cout << "MAX revenue: " << r[len] << endl;

		cout << "Optimal Cutting: ";
		Print_Cut_Rod_Solution(price, len);
		cout << endl;
	}
}