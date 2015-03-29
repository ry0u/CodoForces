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
	string s;
	cin >> s;


	rep(i,s.size())
	{
		int a = (int)(s[i] - '0');
		int b = (int)('9' - s[i]);
		
		if(i == 0)
		{
			if(min(a,b) == 0) cout << max(a,b);
			else cout << min(a,b);
		}
		else cout << min(a,b);
	}

	cout << endl;
	
	return 0;
}
