#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int n,m;
int ans = INF;
int memo[10005];

void dfs(int num,int cnt)
{
	if(num <= 0 || num > 10005) return;
	if(num == m)
	{
		ans = min(ans,cnt);
		return;
	}

	if(memo[num] == -1)
	{
		memo[num] = cnt;

		dfs(num*2,cnt+1);
		dfs(num-1,cnt+1);
	}

	return;
}

int main()
{
	cin >> n >> m;

	rep(i,10005) memo[i] = -1;
	dfs(n,0);

	cout << ans << endl;
	return 0;
}
