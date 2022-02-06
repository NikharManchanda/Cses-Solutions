/**
 *    author:  Rahkin
**/
#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 42
#endif
/*------------------------------------------------------------------*/
#define int               long long
#define nl                "\n"
#define pb                push_back
#define pf                push_front
#define all(x)            (x).begin(),(x).end()
#define rall(x)           (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define fr                first
#define sc                second
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define fix(prec)         {cout << setprecision(prec) << fixed;}
#define lcm(a, b)         (((a) * (b)) / __gcd(a, b))
#define yes               cout<<"YES\n"
#define no                cout<<"NO\n"
#define read(A)           for (auto &I: (A)) cin>>I;
#define show(A)           for (auto I: (A)) cout << I << " "; cout << '\n';
#define sz(x)             (int)((x).size())
#define ios               {ios_base::sync_with_stdio(false);cin.tie(nullptr);}

const int mod = 1e9+7;
const int mod2 = 998244353;
const int inf = 1e18;
/*--------------------------------------------------------*/

const int N = 1e3+5;
int n, m;
char c[N][N];
pair<pair<int, int>, char> par[N][N];
int vis[N][N];
pair<int, int> st, ed;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
bool ok(int x, int y)
{
	return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && c[x][y]!='#';
}
signed main()
{
	ios

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int t = 1;
//	cin >> t;
	for (int test = 1; test<=t; test++)
	{
		cin >> n >> m;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin >> c[i][j];
				if (c[i][j]=='A')
					st = {i, j};
			}
		}
		queue<pair<int, int> > q;
		q.push(st);
		map<int, char> mp;
		mp[0] = 'D', mp[1] = 'R', mp[2] = 'U', mp[3] = 'L';
		vis[st.fr][st.sc] = 1;
		par[st.fr][st.sc] = {{-1, -1}, '@'};
		int f = 0;
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (c[cur.fr][cur.sc]=='B')
			{
				yes;
				f = 1;
				ed = cur;
				break;
			}
			for (int i = 0; i<4; i++)
			{
				if (ok(cur.fr+dx[i], cur.sc+dy[i]))
				{
					q.push({cur.fr+dx[i], cur.sc+dy[i]});
					par[cur.fr+dx[i]][cur.sc+dy[i]] = {cur, mp[i]};
					vis[cur.fr+dx[i]][cur.sc+dy[i]] = 1;
				}
			}
		}
		if (f==0)
		{
			no;
		}
		else
		{
			string ans;
			while ((par[ed.fr][ed.sc].fr.fr)!=-1 && (par[ed.fr][ed.sc].fr.sc)!=-1)
			{
				ans.pb(par[ed.fr][ed.sc].sc);
				ed = par[ed.fr][ed.sc].fr;
			}
			cout << sz(ans) << nl;
			reverse(all(ans));
			for (int i = 0; i<sz(ans); i++)
			{
				cout << ans[i];
			}
		}
	}

	return 0;

}