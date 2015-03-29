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


int main()
{
	int n;
	string s;
	cin >> n >> s;

	map<char,int> m;
	rep(i,n) m[s[i]]++;

	int k = 0;
	map<char,int>::iterator ite;
	for(ite = m.begin();ite != m.end();ite++)
	{
		k = max(k,ite->second);
	}

	int same = 0;
	for(ite = m.begin();ite != m.end();ite++)
	{
		if(ite->second == k) same++;
	}

	ll ans = 1;
	rep(i,n)
	{
		ans *= same;
		ans %= MOD;
	}

	cout << (same * n) %MOD << endl;

	cout << ans << endl;

	return 0;
}
