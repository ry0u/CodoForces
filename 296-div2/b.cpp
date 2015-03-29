#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

bool d[30][30];
int index[30][30];

int main()
{
	int n;
	cin >> n;

	string s,t;
	cin >> s >> t;
	
	rep(i,30) 
	{
		rep(j,30) 
		{
			d[i][j] = false;
			index[i][j] = -1;
		}
	}
	
	map<char,int> m,m2;
	vector<pair<int,int> > diff;
	rep(i,n)
	{
		if(s[i] != t[i]) 
		{
			m[s[i]]++;
			m2[t[i]]++;
			d[s[i]-'a'][t[i]-'a'] = true;
			index[s[i]-'a'][t[i]-'a'] = i;

			diff.push_back(make_pair(s[i]-'a',t[i]-'a'));
		}
	}

	bool flag = false;
	rep(i,diff.size())
	{
		if(d[diff[i].second][diff[i].first])
		{
			flag = true;
			cout << diff.size() - 2 << endl;
			cout << index[diff[i].first][diff[i].second]+1 << " " << index[diff[i].second][diff[i].first]+1 << endl;
			break;
		}
	}

	if(!flag)
	{
		bool f = false;
		rep(i,diff.size())
		{
			rep(j,26)
			{
				if(!d[j][diff[i].first]) continue;
				else
				{
					cout << diff.size()-1 << endl;
					f = true;
					cout << min(index[diff[i].first][diff[i].second],index[j][diff[i].first]) + 1 << " " << max(index[diff[i].first][diff[i].second],index[j][diff[i].first]) + 1 << endl;
					break;
				}
			}

			if(f) break;
		}

		if(!f)
		{
			cout << diff.size() << endl;
			cout << -1 << " " << -1 << endl;
		}

	}

	return 0;
}
