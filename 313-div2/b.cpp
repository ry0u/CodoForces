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
    int x,y;
    cin >> x >> y;

    if(x > y) swap(x,y);

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if(a > b) swap(a,b);
    if(c > d) swap(c,d);

    bool flag = false;

    int nx,ny;
    nx = a + c;
    ny = max(b,d);

    if(min(nx,ny) <= x && max(nx,ny) <= y) flag = true;

    nx = a + d;
    ny = max(b,c);

    if(min(nx,ny) <= x && max(nx,ny) <= y) flag = true;

    nx = b + c;
    ny = max(a,d);

    if(min(nx,ny) <= x && max(nx,ny) <= y) flag = true;

    nx = b + d;
    ny = max(a,c);

    if(min(nx,ny) <= x && max(nx,ny) <= y) flag = true;

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
