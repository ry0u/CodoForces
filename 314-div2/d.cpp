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
    int n,k,c;
    cin >> n >> k >> c;

    int m;
    cin >> m;

    vector<int> v(m);
    rep(i,m) {
        cin >> v[i];
    }

    map<int,int> ma;
    ma[n]++;

    rep(i,m) {
        ma[v[i]]++;

        map<int,int>::iterator ite;
        int pre = 1;
        int cnt = 0;
        for(ite = ma.begin();ite != ma.end(); ite++) {
            int d = ite->first - pre;
            cnt += d / c;
            pre = ite->first;
        }

        if(cnt >= k) {
            continue;
        }

        cout << i+1 << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
