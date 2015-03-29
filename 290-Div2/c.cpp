#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<string> v(n);
	rep(i,n) cin >> v[i];

	map<char,int> table;
	map<char,bool> used;

	rep(i,26)
	{
		table[(char)('a'+i)] = i;
	}

	vector<string> s;
	rep(i,n-1)
	{

		int len = min(v[i].size(),v[i+1].size());
		rep(j,len)
		{
			string temp = "";
			if(table[v[i][j]] > table[v[i+1][j]]) 
			{
				stringstream ss;
				ss << v[i+1][j] << v[i][j];
				temp += ss.str();
			}

			s.push_back(temp);
		}
	}

	rep(i,s.size())
	{
		rep(j,s[i].size())
		{
			used[s[i][j]] = true;
		}
	}

	rep(i,26)
	{
		char c = (char)('a' + i);
		if(!used[c])
		{
			cout << c;
		}
		else
		{
			rep(j,s.size())
			{
				if(s[j][0] == c)
				{
					cout << s[j];
				}
			}
		}
	}



	return 0;
}
