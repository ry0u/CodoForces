#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <complex>
#include <numeric>
#include <map>
#include <time.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,ull> piu;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pii,ll> ppl;
typedef pair<ll,pii> plp;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;
typedef pair<double,pii> pdp;
typedef pair<double,double> pdd;
typedef pair<pdd,double> pd3;
typedef vector<int> vec;
typedef vector<vec> mat;
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define repn(i,a,n) for (int (i) = (a); (i) < (n); (i)++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define SORT(x) sort((x).begin(),(x).end())
#define SORTN(x,n) sort((x),(x)+(n))
#define ERASE(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define COUNT(x,c) count((x).begin(),(x).end(),(c))
#define REMOVE(x,c) (x).erase(remove((x).begin(),(x).end(),(c)),(x).end())
#define REVERSE(x) reverse((x).begin(),(x).end())
#define FORIT(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))-(x).begin()
#define lb(x,a) lower_bound((x).begin(),(x).end(),(a))
#define LBN(x,a,n) lower_bound((x),(x)+(n),(a))-(x)
#define lbN(x,a,n) lower_bound((x),(x)+(n),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))-(x).begin()
#define ub(x,a) upper_bound((x).begin(),(x).end(),(a))
#define BS(x,a) binary_search((x).begin(),(x).end(),(a))
#define BS2(x,n,a) binary_search((x),(x)+(n),(a))
#define NB(x) (((x)&~((x)+((x)&-(x))))/((x)&-(x))>>1)|((x)+((x)&-(x)))
#define NP(x) next_permutation((x).begin(),(x).end())
#define MM(x,p) memset((x),(p),sizeof(x))
#define SQ(x) (x)*(x)
#define SC(c1,c2) strcmp(c1,c2)==0
#define mp make_pair
#define INF (1<<29)
#define INFL (1LL<<61)
#define fi first
#define se second
#define MOD 99739973LL
#define EPS 1e-8
#define MIN(x,a) x=min(x,a)
#define MAX(x,a) x=max(x,a)
#define madd(x,a) x=(x+a)%MOD
#define msub(x,a) x=(x+MOD-a)%MOD
#define OUTPUT(x) rep(i,x.size())printf("%d%c",x[i],i+1==x.size()?'\n':' ');

int N,M;
string s;
set<ull> st[300];
ull P=100000007;
ull pw[300];
vector<string> ss[600000];

int main()
{
    scanf("%d%d",&N,&M);
    pw[0]=1;
    repn(i,1,300)pw[i]=pw[i-1]*P;
    rep(i,N)
    {
        cin>>s;int n=s.size();
        if(n>300000)continue;
        if(n<300)
        {
            ull tt=0;
            rep(j,n)tt+=s[j]*pw[j];
            st[n].insert(tt);
        }
        else ss[n].pb(s);
    }
    rep(i,M)
    {
        cin>>s;int n=s.size();
        if(n<300)
        {
            ull tt=0;
            rep(j,n)tt+=s[j]*pw[j];
            bool f=false;
            rep(j,n)
            {
                ull nt=tt;
                tt-=s[j]*pw[j];
                rep(k,3)if(s[j]!='a'+k)
                {
                    if(st[n].count(tt+pw[j]*('a'+k)))f=true;
                }
                tt+=s[j]*pw[j];
            }
            if(f)puts("YES");
            else puts("NO");
        }
        else
        {
            bool f=false;
            rep(j,ss[n].size())
            {
                int cc=0;
                rep(k,n)
                {
                    if(ss[n][j][k]!=s[k])cc++;
                    if(cc>1)break;
                }
                if(cc==1)f=true;
                if(f)break;
            }
            if(f)puts("YES");
            else puts("NO");
        }
    }
}
