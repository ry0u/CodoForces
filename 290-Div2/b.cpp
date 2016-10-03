#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<string> v;
bool visited[51][51];
int n,m,sy,sx;
bool ret;
char temp;

void dfs(int y,int x,int prey,int prex)
{
	rep(i,4)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(0 <= ny && ny < n && 0 <= nx && nx < m && v[ny][nx] == temp)
		{
			if(ny == prey && nx == prex) 
			{
				continue;
			}
			if(visited[ny][nx] && ny == sy && nx == sx)
			{
				ret = true;
				return;
			}
			else if(!visited[ny][nx])
			{
				visited[ny][nx] = true;
				dfs(ny,nx,y,x);
			}
		}
	}
}


int main()
{
	cin >> n >> m;

	v.resize(n);
	rep(i,n) cin >> v[i];

	bool res = false;

	rep(i,n)
	{
		if(res) break;
		rep(j,m)
		{
			if(res) break;

			rep(k,51) rep(l,51) visited[k][l] = false;
			visited[i][j] = true;

			sy = i;
			sx = j;
			temp = v[i][j];
			ret = false;

			dfs(i,j,-1,-1);

			if(ret) res = true;
		}
	}

	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
