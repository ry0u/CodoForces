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
    int n,x;
    cin >> n >> x;

    vector<int> v(n);
    rep(i,n) {
        v[i] = i+1;
    }

    int cnt = 0;
    rep(i,n) {
        if(x % v[i] != 0) continue;
        if(x / v[i] <= n) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
