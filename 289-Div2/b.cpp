#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;

	vector<int> v(n),t(n);
	rep(i,n) 
	{
		cin >> v[i];
		t[i] = v[i];
	}

	sort(v.begin(),v.end(),greater<int>());

	if(v[0] - v[n-1] > k) cout << "NO" <<endl;
	else
	{
		cout << "YES" << endl;

		rep(i,n)
		{
			int c = 1;
			rep(j,t[i])
			{
				cout << c << " ";
				c++;
				if(c > k) c -= k;
			}
			cout << endl;
		}

	}
	return 0;
}
