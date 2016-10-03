#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

bool prime[10000000];
void Eratosthenes(int n)
{
	rep(i,n) prime[i] = true;
	prime[1] = false;

	REP(i,2,(int)sqrt(n))
	{
		if(prime[i])
		{
			for(int j=0;i*(j+2)<n;j++)
			{
				prime[i*(j+2)] = 0;
			}
		}
	}
} 

int func(int i)
{
	if(i <= 1) return 1;
	return i * func(i-1);
}

int main()
{
	Eratosthenes(10000000);

	int n;
	cin >> n;

	string s;
	cin >> s;

	ll ret = 1;
	rep(i,n)
	{
		cout << func(s[i]-'0') << endl;
		ret *= func(s[i]-'0');
	}

	cout << "ret:" << ret << endl;

	vector<int> v;
	while(true)
	{
		cout << ret << " " << v.size() << " | ";
		rep(i,v.size()) cout << v[i] << " ";
		cout << endl;
		if(prime[ret])
		{
			break;
		}

		REP(i,2,ret)
		{
			if(prime[i] && ret%func(i) == 0)
			{
				ret /= func(i);
				v.push_back(i);
				break;
			}
		}
	}

	sort(v.begin(),v.end(),greater<int>());
	rep(i,v.size()) cout << v[i];
	cout << endl;

		
	return 0;
}
