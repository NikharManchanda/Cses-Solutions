/**
 *    author:  Rahkin
 *    created: 08/02/2022 04:00:06 
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
#define show1(A)          for (auto I: (A)) cout << I; cout << '\n';
#define sz(x)             (int)((x).size())
#define ios               {ios_base::sync_with_stdio(false);cin.tie(nullptr);}

const int mod = 1e9+7;
const int mod2 = 998244353;
const int inf = 1e18;
/*--------------------------------------------------------*/

const int N = 1e5+5;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

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
		int n, m;
		cin >> n >> m;
		vector<vector<char>> c(n, vector<char>(m));
		vector<vector<int> > vis(n, vector<int>(m, 0));
		vector<vector<int> > time(n, vector<int>(m, inf));
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin >> c[i][j];
				time[i][j] = inf;
			}
		}
		pair<int, int> start;
		queue<pair<pair<int, int>, int> > q;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (c[i][j]=='M')
				{
					q.push({{i, j}, 0});
					time[i][j] = min(time[i][j], 0LL);
				}
				if (c[i][j]=='A')
				{
					start = {i, j};
				}
			}
		}
		auto ok = [&](int i, int j)
		{
			return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && c[i][j]!='#';
		};
		while (!q.empty())
		{
			pair<pair<int, int>, int> cur = q.front();
			q.pop();
			int ctime = cur.sc;
			for (int i = 0; i<4; i++)
			{
				int nx = cur.fr.fr+dx[i], ny = cur.fr.sc+dy[i];
				if (ok(nx, ny))
				{
					q.push({{nx, ny}, ctime+1});
					time[nx][ny] = min(time[nx][ny], ctime+1);
					vis[nx][ny] = 1;
				}
			}
		}
		queue<array<int, 4>> bfs;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				vis[i][j] = 0;
		vis[start.fr][start.sc] = 1;
		bfs.push({start.fr, start.sc, -1, 0});
		// i, j , par, time
		pair<pair<int, int>, char> par[n][m];
		par[start.fr][start.sc] = {{-1, -1}, '@'};
		vector<char> ans;
		string s = "DRUL";
		map<int, char> mp;
		for (int i = 0; i<sz(s); i++)
			mp[i] = s[i];
		pair<int, int> idx;
		int f = 0;
		while (!bfs.empty())
		{
			array<int, 4> cur = bfs.front();
			bfs.pop();
			int ctime = cur[3];
			if (cur[0]==0 || cur[0]==n-1 || cur[1]==0 || cur[1]==m-1)
			{
				f = 1;
				idx = {cur[0], cur[1]};
				break;
			}
			for (int i = 0; i<4; i++)
			{
				int ptime = ctime+1;
				int nx = cur[0]+dx[i], ny = cur[1]+dy[i];
				if (ok(nx, ny))
				{
					if (time[nx][ny]>ptime)
					{
						vis[nx][ny] = 1;
						bfs.push({nx, ny, i, ptime});
						par[nx][ny] = {{cur[0], cur[1]}, mp[i]};
					}
				}
			}
		}
		if (f)
		{
			yes;
			while (idx!=start)
			{
				ans.pb(par[idx.fr][idx.sc].sc);
				idx = par[idx.fr][idx.sc].fr;
			}
			cout << sz(ans) << nl;
			reverse(all(ans));
			show1(ans)
		}
		else
			no;
	}

	return 0;

}