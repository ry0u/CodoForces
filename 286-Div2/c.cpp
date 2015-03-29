#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int n,d;
map<int,int> m;
int memo[30010][1010];

int dfs(int cur,int l)
{
	if(memo[cur][d-l+300] != -1) return memo[cur][d-l+300];

	int res = 0;

	if(1 < l && cur+l-1 < 30001)
	{
		res = max(res,dfs(cur+l-1,l-1));
	}

	if(cur+l < 30001)
	{
		res = max(res,dfs(cur+l,l));
	}

	if(cur+l+1 < 30001)
	{
		res = max(res,dfs(cur+l+1,l+1));
	}

	return (memo[cur][d-l+300] = res + m[cur]);
}

int main()
{
	cin >> n >> d;

	rep(i,n)
	{
		int t;
		cin >> t;
		
		m[t]++;
	}
	
	memset(memo,-1,sizeof(memo));
    cout << dfs(d,d) << endl;
}
