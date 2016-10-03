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

struct edge {
    int from,to;
    int cost;

    edge(int t,int c) : to(t),cost(c) {}
    edge(int f,int t,int c) : from(f),to(t),cost(c) {}

    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

vector<edge> G[5005];
bool used[5005][5005];

int main() {
    int n,m;
    cin >> n >> m;

    memset(used,0,sizeof(used));
    vector<P> v;

    rep(i,m) {
        int a,b;
        cin >> a >> b;

        a--;
        b--;

        used[a][b] = true;
        used[b][a] = true;


        G[a].push_back(edge(b,1));
        G[b].push_back(edge(a,1));

        if(a > b) swap(a,b);
        v.push_back(P(a,b));
    }

    int ans = INF;
    rep(i,m) {
        rep(j,m) {
            if(i == j) continue;

            int s1 = v[i].first;
            int t1 = v[i].second;
            int s2 = v[j].first;
            int t2 = v[j].second;

            if(s1 == s2 && used[t1][t2]) {
                ans = min(ans, int(G[s1].size() + G[t1].size() + G[t2].size() - 6));
            }

            if(t1 == t2 && used[s1][s2]) {
                ans = min(ans, int(G[t1].size() + G[s1].size() + G[s2].size() - 6));
            }
        }
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;



    return 0;
}
