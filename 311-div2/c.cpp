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

struct BIT {
    vector<int> bit;

    BIT(int n) : bit(n+1) {}

    int sum(int i) {
        int s = 0;
        while(i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i,int x) {
        while(i <= bit.size()) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> L(n);
    vector<int> D(n);

    rep(i,n) cin >> L[i];
    rep(i,n) cin >> D[i];

    vector<P> v(n);
    int cnt[100005];
    memset(cnt,0,sizeof(cnt));

    rep(i,n) {
        v[i] = mp(L[i],-D[i]);
        cnt[L[i]]++;
    }

    for(int i=100005;i>=1;i--) {
        cnt[i-1] += cnt[i];
    }

    sort(v.begin(),v.end());
    rep(i,n) {
        v[i].second *= -1;
    }
    
    BIT bit(n);
    BIT bit2(n);

    rep(i,n) {
        bit.add(i+1,v[i].first);
        bit2.add(i+1,v[i].second);
    }

    
    return 0;
}
