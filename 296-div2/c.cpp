#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int h,w,n;
	cin >> h >> w >> n;

	vector<pair<char,int> > v(n);
	rep(i,n) cin >> v[i].first >> v[i].second;
	
	
	return 0;
}
