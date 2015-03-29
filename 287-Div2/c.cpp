#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    ll h,n;
	cin >> h >> n;

	ll ans = 0;
	bool flag = 1;

	while(h)
	{
		ll l = 1ll << (h - 1ll);

		if( (l >= n) ^ flag)
		{
			ans += (1ll << h) - 1ll;
		}
		else
		{
			flag = !flag;
		}

		ans++;
		if(l < n) n -= l;
		h--;
	}

	cout << ans << endl;
}
