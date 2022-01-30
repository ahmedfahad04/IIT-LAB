#include <iostream>
#define ll long int
using namespace std;

int main(int argc, char *argv[])
{	

	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		if (n % 2 == 0)
			cout << 0 << endl;
		else
		{
			int pos = -1;
			int len = 1;
			while(n)
			{
				int x = n % 10;
				n /= 10;
				if (pos <= len && x % 2 == 0)
				{
					pos = len;
					//cout << "x: " << x << ", pos: " << pos << endl;
				}
				len++;
			}

			// cout << "Len: " << len << endl;
			// cout << "Pos: " << pos << endl;
			if(pos!=-1)cout << len-pos << endl;
			else cout << -1 << endl;
		}
	}
}