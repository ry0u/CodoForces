#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	
	vector<int> v(n),p(n);
	rep(i,n)
	{
		int a;
		cin >> a;
		a--;

		v[i] = a;
		p[a] = i;
	}

	int ans = 0;
	rep(i,m)
	{
		int b;
		cin >> b;
		b--;

		ans += p[b]/k + 1;
		if(p[b] == 0) continue;

		int t = v[p[b]-1];
		v[p[b]--] = b;
		v[p[t]++] = t;
	}

	cout << ans << endl;
	
	return 0;
}
