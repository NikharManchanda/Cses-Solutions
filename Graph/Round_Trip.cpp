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
#define show1(A)          for (auto I: (A)) cout << I; cout << '\n';
#define sz(x)             (int)((x).size())
#define ios               {ios_base::sync_with_stdio(false);cin.tie(nullptr);}

const int mod = 1e9+7;
const int mod2 = 998244353;
const int inf = 1e18;
/*--------------------------------------------------------*/

const int N = 1e5+5;
vector<int> adj[N];
int vis[N], parent[N];
int col[N], cycle_start, cycle_end;
bool dfs(int node, int par)
{
	col[node] = 1;
	parent[node] = par;
	for (auto x : adj[node])
	{
		if (!col[x])
		{
			bool ok = dfs(x, node);
			if (!ok)
				return 0;
		}
		else if (col[x]==1 && x!=par)
		{
			cycle_start = x;
			cycle_end = node;
			return 0;
		}
	}
	return 1;
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
		int n, m;
		cin >> n >> m;
		for (int i = 0; i<m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].pb(b), adj[b].pb(a);
		}
		int f = 0;
		for (int i = 1; i<=n; i++)
		{
			if (!col[i])
			{
				bool ok = dfs(i, -1);
				if (!ok)
				{
					f = -1;
					vector<int> ans;
					int cur = cycle_end;
					while (cur!=cycle_start)
					{
						ans.pb(cur);
						cur = parent[cur];
					}
					ans.pb(cycle_start);
					ans.pb(cycle_end);
					cout << sz(ans) << nl;
					show(ans);
					break;
				}
			}
		}
		if (!f)
			cout << "IMPOSSIBLE" << nl;
	}

	return 0;

}