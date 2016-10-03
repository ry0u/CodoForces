#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int cnt[1000005],cnt2[1000005];

int main()
{
	int n;
	cin >> n;
	
	memset(cnt,0,sizeof(cnt));
	memset(cnt2,0,sizeof(cnt2));

	int top = 0;
	rep(i,n)
	{
		int x;
		cin >> x;
		
		cnt[x]++;
		cnt2[x]++;
		top = max(top,x);
	}

	ll a,b,ans = 0;

	while(true)
	{
		a = 0;
		for(int i=top;i>0;i--)
		{
			if(cnt[i] >= 2)
			{
				a = i;
				cnt[i] -= 2;
				break;
			}
			else if(cnt[i] >= 1 && cnt[i-1] >= 1)
			{
				a = i-1;
				cnt[i]--;
				cnt[i-1]--;
				break;
			}
		}

		b = 0;
		for(int i=top;i>0;i--)
		{
			if(cnt[i] >= 2)
			{
				b = i;
				cnt[i] -= 2;
				break;
			}
			else if(cnt[i] >= 1 && cnt[i-1] >= 1)
			{
				b = i-1;
				cnt[i]--;
				cnt[i-1]--;
				break;
			}
		}
		
		if(a*b == 0) break;
		ans += a*b;
	}
	
	cout << ans << endl;

	return 0;
}
