#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, P> IP;

struct edge {
	int from,to;
	int cost;

	edge(int t,int c) : to(t),cost(c) {}
	edge(int f,int t,int c) : from(f),to(t),cost(c) {}

	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

int n, m;
vector<edge> G[5005];
ll t;
int d[5005][5005], prev[5005][5005];

void dijkstra(int s, int n) {
	priority_queue<IP, vector<IP>, greater<IP> > que;

	rep(i, 5005) rep(j, 5005) {
		d[i][j] = INF;
		prev[i][j] = -1;
	}
	
	d[s][1] = 0;

	que.push(mp(0, mp(s, 1)));
	
	while(que.size()) {
		IP p = que.top(); que.pop();

		int cos = p.first;
		int v = p.second.first;
		int cnt = p.second.second;
		if(d[v][cnt] < cos) continue;
	
		rep(i, G[v].size()) {
			edge e = G[v][i];
			ll nc = ll(d[v][cnt]) + ll(e.cost);
			if(nc > t) continue;

			if(d[e.to][cnt+1] > nc) {
				d[e.to][cnt+1] = nc;
				prev[e.to][cnt+1] = v;
				que.push(mp(d[e.to][cnt+1], mp(e.to, cnt+1)));
			}
		}
	}
}

vector<int> get_path(int t, int cnt) {
	vector<int> path;
	for(;t!=-1;t=prev[t][cnt], cnt--) path.push_back(t);
	reverse(path.begin(),path.end());
	return path;
}

int main() {
	cin >> n >> m >> t;

	rep(i, m) {
		int a, b;
		ll c;
		cin >> a >> b >> c;

		a--; b--;
		G[a].push_back(edge(b, c));
		// G[b].push_back(edge(a, c));
	}

	dijkstra(0, n * n);

	for(int i = n; i > 0; i--) {
		if(d[n-1][i] == INF) continue;
		cout << i << endl;

		vector<int> ret = get_path(n-1, i);
		rep(j, ret.size()) {
			if(j) cout << " ";
			cout << ret[j] + 1;
		}
		cout << endl;
		break;
	}

	return 0;
}
