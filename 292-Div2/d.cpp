#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int h,w;
vector<string> v;
int cnt = 0;

void dfs(vector<string> f,int y,int x)
{
	cout << y << " " << x << endl;
	if(y == h-1 && x == w-1) 
	{
		rep(i,h)
		{
			rep(j,w) cout << f[i][j];
			cout << endl;
		}

		cnt++;
		return;
	}

	if(x + 1 <= w && f[y][x] == '.' && f[y][x+1] == '.')
	{
		f[y][x] = '<';
		f[y][x+1] = '>';

		if(x == w-1)
		{
			x = 0;
			y++;
		}
		else x++;

		dfs(f,y,x);

		f[y][x] = '.';
		f[y][x+1] = '.';
	}
	
	if(y + 1 <= h && f[y][x] == '.' && f[y+1][x] == '.')
	{
		f[y][x] = '^';
		f[y+1][x] = 'v';

		if(x == w-1)
		{
			x = 0;
			y++;
		}
		else x++;

		dfs(f,y,x);

		f[y][x] = '.';
		f[y+1][x] = '.';
	}

	return;
}

int main()
{
	cin >> h >> w;
	
	v.clear();
	v.resize(h);

	rep(i,h) cin >> v[i];
	
	dfs(v,0,0);

	return 0;
}
