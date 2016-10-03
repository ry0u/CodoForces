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

	string s;
	cin >> s;
	
	sort(s.begin(),s.end(),greater<char>());

	vector<int> v;
	bool check[15];
	rep(i,15) check[i] = false;
	rep(i,n)
	{
		if(check[i]) continue;

		if(s[i] == '1' || s[i] == '0') continue;
		if(s[i] == '4')
		{
			v.push_back(2);
			v.push_back(2);
			v.push_back(3);
		}
		else if(s[i] == '6')
		{
			v.push_back(3);
			v.push_back(5);
		}
		else if(s[i] == '8')
		{
			v.push_back(2);
			v.push_back(2);
			v.push_back(2);
			v.push_back(7);
		}
		else if(s[i] == '9')
		{
			v.push_back(7);
			v.push_back(3);
			v.push_back(3);
			v.push_back(2);
		}
		else v.push_back(s[i] - '0');
	}

	sort(v.begin(),v.end(),greater<int>());
	rep(i,v.size()) cout << v[i];
	cout << endl;


	return 0;
}
