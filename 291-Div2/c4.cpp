#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int n,m;

struct Node
{
	Node *next[3];
	unsigned char end;
	Node()
	{
		next[0] = next[1] = next[2] = 0;
	}
};

void add(Node *v,string s,int i)
{
	if(!s[i])
	{
		v->end = 1;
		return;
	}

	if(!v->next[s[i]-'a']) v->next[s[i]-'a'] = new Node();
	add(v->next[s[i]-'a'],s,i+1);
}

int check(Node *v,string s,int i,int cnt)
{
	if(cnt > 1) return 0;

	if(!s[i])
	{
		return cnt && v->end;
	}

	rep(j,3)
	{
		if(v->next[j])
		{
			if(check(v->next[j],s,i+1,cnt + (j + 'a' != s[i]))) return 1;
		}
	}

	return 0;
}


int main()
{

	cin >> n >> m;

	Node *root = new Node();
	
	rep(i,n)
	{
		string s;
		cin >> s;

		add(root,s,0);
	}

	rep(i,m)
	{
		string s;
		cin >> s;

		if(check(root,s,0,0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
