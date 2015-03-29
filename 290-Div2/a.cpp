#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	bool flag = false;
	rep(i,n)
	{
		rep(j,m)
		{
			if(i%2 == 0) cout << "#";
			else if(flag)
			{
				if(j != m-1) cout << ".";
				else cout << "#";
			}
			else
			{
				if(j != 0) cout << ".";
				else cout << "#";
			}
			
		}
		cout << endl;

		if(i%2 == 0)
		{
			if(flag) flag = false;
			else flag = true;
		}
	}
	return 0;
}		

