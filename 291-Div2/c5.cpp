#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct Trie
{
	Trie *next[3];
	bool end;

	Trie()
	{
		fill(next,next+3,(Trie *)0);
	}

	void insert(string s,int i)
	{
		if(i == s.size()) 
		{
			this->end = true;
			return;
		}

		if(this->next[s[i]-'a'] == NULL)
		{
			this->next[s[i]-'a'] = new Trie();
		}

		this->next[s[i]-'a']->insert(s,i+1);
	}

	bool find(string s,int i,int cnt)
	{
		if(cnt > 1) return false;

		if(i == s.size())
		{
			if(cnt == 1 && this->end) return true;
			else return false;
		}

		rep(j,3)
		{
			if(this->next[j] != NULL)
			{
				if(s[i]-'a' == j) 
				{
					if(this->next[j]->find(s,i+1,cnt)) return true;
				}
				else 
				{
					if(this->next[j]->find(s,i+1,cnt+1)) return true;
				}
			}
		}

		return false;
	}
};

int main()
{
	int n,m;
	cin >> n >> m;


	Trie *trie = new Trie();
	rep(i,n)
	{
		string s;
		cin >> s;
		
		trie->insert(s,0);
	}

	rep(i,m)
	{
		string s;
		cin >> s;

		if(trie->find(s,0,0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
	
}	
