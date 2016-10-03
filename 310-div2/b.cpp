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

    int n;
    cin >> n;

    vector<int> v(n);
    rep(i,n) cin >> v[i];

    int d = v[0];
    rep(i,n) {
        if(i%2 == 0) {
            v[i] -= d;
            if(v[i] < 0) v[i] += n;
        }
        else {
            v[i] += d;
            v[i] %= n;
        }
    }

    bool flag = true;
    rep(i,n) if(v[i] != i) flag = false;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
