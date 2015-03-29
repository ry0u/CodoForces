#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int cnt[1000005];

int main()
{
	int n;
	cin >> n;
	
	memset(cnt,0,sizeof(cnt));
	int top = 0;
	rep(i,n)
	{
		int x;
		cin >> x;
		
		cnt[x]++;
		top = max(top,x);
	}
	
	vector<pair<ll,int> > v;
	for(int i=top;i>0;i--)
	{
		if(cnt[i] >= 2)
		{
			v.push_back(make_pair(i,2));
		}
		else if(cnt[i] >= 1 && cnt[i-1] >= 1)
		{
			v.push_back(make_pair(i-1,1));
		}
	}

	rep(i,v.size())
	{
		cout << v[i].first << " " << v[i].second << endl;
	}

	bool flag = true;
	rep(i,v.size()-1)
	{
		ll a = v[i].first;
		int ta = v[i].second;
		ll b = v[i+1].first;
		int tb = v[i+1].second;

		if(ta == 2 && tb == 2)
		{
			cnt[a] -= 2;
			cnt[b] -= 2;

			if(cnt[a] >= 0 && cnt[b] >= 0)
			{
				cout << a*b << endl;
				flag = false;
			}
			else
			{
				cnt[a] += 2;
				cnt[b] += 2;
			}
		}
		if(ta == 2 && tb == 1)
		{
			cnt[a] -= 2;
			cnt[b] -= 1;
			cnt[b+1] -= 1;

			if(cnt[a] >= 0 && cnt[b] >= 0 && cnt[b+1] >= 0) 
			{
				cout << a*b << endl;
				flag = false;
			}
			else
			{
				cnt[a] += 2;
				cnt[b] += 1;
				cnt[b+1] += 1;
			}
		}
		if(ta == 1 && tb == 2)
		{
			cnt[a] -= 1;
			cnt[a+1] -= 1;
			cnt[b] -= 2;

			if(cnt[a] >= 0 && cnt[a+1] >= 0 && cnt[b] >= 0)
			{
				cout << a*b << endl;
				flag = false;
			}
			else
			{
				cnt[a] += 1;
				cnt[a+1] += 1;
				cnt[b] += 2;
			}
		}
		if(ta == 1 && tb == 1)
		{
			cnt[a]--;
			cnt[a+1]--;
			cnt[b]--;
			cnt[b+1]--;

			if(cnt[a] >= 0 && cnt[a+1] >= 0 && cnt[b] >= 0 && cnt[b+1] >= 0)
			{
				cout << a*b << endl;
				flag = false;
			}
			else
			{
				cnt[a]++;
				cnt[a+1]++;
				cnt[b]++;
				cnt[b+1]++;
			}
		}		
	}
	
	if(flag) cout << 0 << endl;

	return 0;
}

