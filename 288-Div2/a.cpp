#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int n,m,k;
bool f[1001][1001];

bool check(int y,int x)
{
	if(0 <= y-1 && y-1 < n && 0 <= y && y < n && 0 <= x-1 && x-1 < m && 0 <= x && x < m)
	{
		if(f[y-1][x-1] && f[y-1][x] && f[y][x-1] && f[y][x]) return true;
	}
	if(0 <= y-1 && y-1 < n && 0 <= y && y < n && 0 <= x && x < m && 0 <= x+1 && x+1 < m)
	{
		if(f[y-1][x] && f[y-1][x+1] && f[y][x] && f[y][x+1]) return true;
	}
	if(0 <= y && y < n && 0 <= y+1 && y+1 < n && 0 <= x-1 && x-1 < m && 0 <= x && x < m)
	{
		if(f[y][x-1] && f[y][x] && f[y+1][x-1] && f[y+1][x]) return true;
	}
	if(0 <= y && y < n && 0 <= y+1 && y+1 < n && 0 <= x && x < m && 0 <= x+1 && x+1 < m)
	{
		if(f[y][x] && f[y][x+1] && f[y+1][x] && f[y+1][x+1]) return true;
	}

	return false;
}

int main()
{
	cin >> n >> m >> k;

	rep(i,1001) rep(j,1001) f[i][j] = false;

	bool flag = true;
	vector<int> a,b;
	rep(i,k)
	{
		int t,t2;
		cin >> t >> t2;
		t--;
		t2--;

		a.push_back(t);
		b.push_back(t2);
	}

	rep(i,k)
	{
		f[a[i]][b[i]] = true;

		if(check(a[i],b[i]))
		{
			flag = false;
			cout << i+1 << endl;
			break;
		}
	}

	if(flag) cout << 0 << endl;


}
