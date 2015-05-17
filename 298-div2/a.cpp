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
	cin >> n;

	if(n == 1) 
	{
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	else if(n == 2)
	{
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	
	vector<int> v,t;
	REP(i,1,n+1)
	{
		if(i%2 == 0) v.push_back(i);
		else t.push_back(i);
	}

	if(n == 3)
	{
		cout << 2 << endl;
		rep(i,t.size())
		{
			cout << t[i];
			if(i == t.size()-1) cout << endl;
			else cout << " ";
		}

		return 0;
	}
	else if(n == 4)
	{
		cout << 4 << endl;
		rep(i,v.size()) cout << v[i] << " ";
		rep(i,t.size())
		{
			cout << t[i];
			if(i == t.size()-1) cout << endl;
			else cout << " ";
		}

		return 0;
	}

	int k = 0;
	if(t.size() >= 1 && t[t.size()-1] - v[0] >= 2)
	{
		k = t.size() + v.size();
		cout << k << endl;
		rep(i,t.size()) cout << t[i] << " ";
		rep(i,v.size())
		{
			cout << v[i];
			if(i == v.size()-1) cout << endl;
			else cout << " ";
		}
	}
	else
	{
		k = t.size() + v.size()-1;
		cout << k << endl;
		rep(i,t.size()) 
		{
			cout << t[i];
			
			if(i == t.size()-1)
			{
				if(v.size()-1 >= 1) cout << " ";
				else cout << endl;
			}
			else cout << " ";
		}


		REP(i,1,v.size())
		{
			cout << v[i];
			if(i == v.size()-1) cout << endl;
			else cout << " ";
		}
	}

	return 0;
}
