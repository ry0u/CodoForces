#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int S,T;
int len,d;

int main()
{
	cin >> S >> T;
	cin >> len >> d;

	queue<pair<pair<int,int>,int> > que;
	que.push(mp(mp(S,0),0));

	while(true)
	{
		pair<pair<int,int>,int>  p = que.front();
		que.pop();

		int cur = p.first.first;
		int dep = p.first.second;
		int sum = p.second;

		if(dep == len-2)
		{
			cout << sum + cur +  T << endl;
			break;
		}

		for(int i=d;i>=-d;i--)
		{
			int diff = len-2-dep;
			int next = cur + i;
			if(abs(next-T) <= diff*d) 
			{
				que.push(mp(mp(cur+i,dep+1),sum+cur));
				break;
			}
		}
	}

	return 0;
}
