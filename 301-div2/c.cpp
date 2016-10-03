#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m,sy,sx,gy,gx,memo[505][505];
bool flag;
vector<string> v;

bool can(int y,int x)
{
	if(0 <= y && y < n && 0 <= x && x < m) return true;
	else return false;
}

bool used[505][505];
bool visited[505][505];

void dfs(int y,int x,int prey,int prex)
{
	if(prey != -1 && prex != -1 && y == gy && x == gx)
	{
		flag = true;
		return;
	}

	if(!visited[y][x])
	{
		visited[y][x] = true;
		
	}
}


int main()
{
	cin >> n >> m;


	v.resize(n);
	rep(i,n) cin >> v[i];

	cin >> sy >> sx;
	sy--;
	sx--;

	cin >> gy >> gx;
	gy--;
	gx--;

	memset(memo,0,sizeof(memo));
	rep(i,n)
	{
		rep(j,m)
		{
			if(v[i][j] == 'X') memo[i][j]++;
		}
	}
	
	queue<pair<int,int> > que;
	que.push(make_pair(sy,sx));

	memset(used,0,sizeof(used));
	while(que.size())
	{
		pair<int,int> p = que.front();
		que.pop();

		int y = p.first;
		int x = p.second;

		if(y == gy && x == gx)
		{
		
		}
		else
		{
			used[y][x] = true;

			rep(i,4)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if(can(ny,nx) && !used[ny][nx])
				{
					que.push(make_pair(ny,nx));
				}
			}
		}
	}

	return 0;
}
