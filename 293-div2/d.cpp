#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

double memo[2005][2005];

double dfs(int n,double p,int t)
{
	if(n == 0 || t == 0) return 0.0;
	if(memo[n][t] != -1) return memo[n][t];
	//乗らない、乗る+1.0
	return memo[n][t] = ((1.0 - p)*dfs(n,p,t-1) + p*(1.0 + dfs(n-1,p,t-1)));
}

int main()
{
	int n,t;
	double p;
	cin >> n >> p >> t;

	rep(i,2005) rep(j,2005) memo[i][j] = -1;

	cout << fixed;
	cout.precision(10);
	cout << dfs(n,p,t) << endl;
	
	return 0;
}
