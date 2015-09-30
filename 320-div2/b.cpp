#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool used[1000];

int main() {
    int n;
    cin >> n;

    priority_queue<pair<int, pair<int,int> > > que;
    rep(i,n*2) {
        rep(j,i) {
            int x;
            cin >> x;

            que.push(mp(x,mp(j,i)));
        }
    }

    memset(used,0,sizeof(used));
    vector<int> v(2*n);
    while(que.size()) {
        int cnt = que.top().first;
        pair<int,int> id = que.top().second;

        que.pop();

        if(used[id.first] || used[id.second]) continue;

        used[id.first] = true;
        used[id.second] = true;

        v[id.first] = id.second + 1;
        v[id.second] = id.first + 1;
    }

    rep(i,v.size()) {
        cout << v[i];

        if(i == v.size()-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
