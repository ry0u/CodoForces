#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    int len = max(a+b+c,a+e+f);
    int ans = 0;
    int t = 1;

    rep(i,len) {
        ans += t;
        t += 2;
    }

    t = 1;
    rep(i,a) {
        ans -= t;
        t += 2;
    }

    t = 1;
    rep(i,c) {
        ans -= t;
        t += 2;
    }

    t = 1;
    rep(i,e) {
        ans -= t;
        t += 2;
    }

    cout << ans << endl;


    return 0;
}
