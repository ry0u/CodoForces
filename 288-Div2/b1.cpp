#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int main()
{
	string s;
	cin >> s;

	int m = INF;
	rep(i,s.size()-1)
	{
		if((s[i] - '0')%2 == 0)
		{
			m = i;
		}
	}

	if(m == INF) cout << -1 << endl;
	else
	{
		bool changed = false;
		rep(i,s.size()-1)
		{
			if((s[i]-'0')%2 == 0 && s[i] < s[s.size()-1])
			{
				swap(s[i],s[s.size()-1]);
				changed = true;
				break;
			}
		}

		if(!changed)
		{
			swap(s[m],s[s.size()-1]);
		}

		cout << s << endl;
	}

	return 0;
}
