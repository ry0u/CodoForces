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
    int t,s,q;
    cin >> t >> s >> q;

    int time = s;
    int ans = 0;
    while(t > time) {
        ans++;
        time += (q-1) * time;
    }

    cout << ans << endl;

    return 0;
}
