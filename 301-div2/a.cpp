#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	string s,t;
	cin >> n >> s >> t;

	int ans = 0;
	rep(i,n)
	{
		int a = s[i]-'0';
		int b = t[i]-'0';
		
		if(a < b) swap(a,b);
		ans += min(a-b,10-a+b);
	}

	cout << ans << endl;
	return 0;
}
