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

    map<int,int> m;
    rep(i,n) {
        m[v[i]]++;
    }

    bool used[100005];
    memset(used,0,sizeof(used));

    map<int,int>::iterator ite;
    for(ite = m.begin(); ite != m.end(); ite++) {
        used[ite->first] = true;
    }

    vector<int> res;
    REP(i,1,n+1) {
        if(!used[i]) res.push_back(i);
    }
    int id = 0;

    rep(i,n) {
        if(m[v[i]] == 1 && 1 <= v[i] && v[i] <= n) {
            cout << v[i];
        }
        else {
            cout << res[id];
            id++;
            m[v[i]]--;
        }

        if(i == n-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
