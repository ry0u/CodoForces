#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
   	double a,b,c,d;
	cin >> a >> b >> c >> d;

	double res,res2 = 0;
	res = max((3*a)/10,a - (a/250)*c);

	res2 = max((3*b)/10,b - (b/250)*d);

	if(res > res2)
	{
		cout << "Misha" << endl;
	}
	else if(res < res2)
	{
		cout << "Vasya" << endl;
	}
	else cout << "Tie" << endl;
}
