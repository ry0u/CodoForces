#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[10][10],ans = 1;
	memset(a,0,sizeof(a));

	a[0][0] = 1;
	rep(i,n) 
	{
		a[0][i] = 1;
		a[i][0] = 1;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			a[i][j] = a[i-1][j] + a[i][j-1];
			a[j][i] = a[i][j];
			ans = max(ans,a[i][j]);
		}
	}

	cout << ans << endl;

	return 0;
}
