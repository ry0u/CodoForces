#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007

using namespace std;
typedef long long ll;

vector<string> samesplit(string s)
{
	vector<string> ret;
	rep(i,s.size())
	{
		char c = s[i];
		stringstream ss;
		ss << c;
		REP(j,i+1,s.size())
		{
			if(s[j] == c) ss << s[j],i++;
			else break;
		}
		ret.push_back(ss.str());
	}

	return ret;
}

ll f(ll x)
{
	if(x == 1) return 1;
	return x * f(x-1);
}

int main()
{
	int n;
	string s;
	cin >> n >> s;

	ll ans = f(n)%MOD;
	int cnt = 0;
	vector<string> v = samesplit(s);

	rep(i,v.size())
	{
		cnt = max(cnt,(int)v[i].size());

		ans /= f(v[i].size());
		ans %= MOD;
	}

	int same = 0;
	rep(i,v.size())
	{
		if(v[i].size() == cnt) same++;
	}

	cout << (ans*same)%MOD << endl;
	
	return 0;
}
