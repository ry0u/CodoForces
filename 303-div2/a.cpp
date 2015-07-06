#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    int a[105][105];
    memset(a,0,sizeof(a));

    rep(i,n) {
        rep(j,n) cin >> a[i][j];
    }

    bool f[105];
    rep(i,n) f[i] = true;

    rep(i,n) {
        rep(j,n) {
            if(i == j) continue;
            if(a[i][j] == 0) continue;

            if(a[i][j] == 1) f[i] = false;
            if(a[i][j] == 2) f[j] = false;
            if(a[i][j] == 3) {
                f[i] = false;
                f[j] = false;
            }
        }
    }

    vector<int> v;
    rep(i,n) {
        if(f[i]) v.push_back(i);
    }

    cout << v.size() << endl;
    rep(i,v.size()) {
        cout << v[i]+1;

        if(i == v.size()-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
