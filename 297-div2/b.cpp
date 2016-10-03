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
	string s;
	cin >> s >> n;

	vector<int> v(s.size()+1,0);

	rep(i,n)
	{
		int x;
		cin >> x; 
		
		x--;
		v[x]++;
	}

	REP(i,1,s.size()/2)
	{
		v[i] += v[i-1];
	}

	rep(i,s.size()/2)
	{
		if(v[i]%2 == 0) continue;

		int x = i+1;
		int to = s.size() - x + 1;

		x--;
		to--;

		swap(s[x],s[to]);
	}

	cout << s << endl;


	return 0;
}
