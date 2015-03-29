#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	string s,s2;
	cin >> s >> s2;

	int n = s.size();

	for(int i=n-1;i>=0;i--)
	{
		if(s[i] == 'z') 
		{
			s[i] = 'a';
			continue;
		}

		s[i]++;
		break;
	}

	if(s >= s2) cout << "No such string" << endl;
	else cout << s << endl;
	
	return 0;
}
