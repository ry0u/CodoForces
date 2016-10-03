#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

ll cnt[2*100005];

int main()
{
	int n;
	cin >> n;

	ll A;
	cin >> A;

	vector<int> v(n);
	ll sum = 0;
	rep(i,n) 
	{
		cin >> v[i];
		sum += v[i];
	}


	rep(i,n)
	{
		int cnt = 0;
		REP(j,n-1,sum-v[i]+1)
		{
			if(j <= A && A <= j+v[i]) cnt++;
		}

		if(v[i] - cnt >= 0) cout << v[i] - cnt;
		else cout << 0;

		if(i == n-1) cout << endl;
		else cout << " ";
	}
	
	return 0;
}
