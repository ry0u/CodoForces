#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int memo[10005];

int main()
{
	int n,m;
	cin >> n >> m;

	rep(i,10005) memo[i] = -1;
	queue<pair<int,int> > que;
	que.push(make_pair(n,0));

	int ans = 0;
	while(que.size())
	{
		pair<int,int> p = que.front();
		que.pop();
		
		int num = p.first;
		int cnt = p.second;
		
		if(num == m)
		{
			ans = cnt;
			break;
		}

		if(0 < num && num <= 10000 && memo[num] == -1)
		{
			memo[num] = cnt;
			que.push(make_pair(num*2,cnt+1));
			que.push(make_pair(num-1,cnt+1));
		}
	}

	cout << ans << endl;
	return 0;
}
