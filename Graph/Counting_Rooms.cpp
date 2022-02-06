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

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
const int N = 1e5+5;
int vis[1005][1005], n, m;
char c[1005][1005];
bool ok(int x, int y)
{
	return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && c[x][y]=='.';
}
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i<4; i++)
	{
		if (ok(x+dx[i], y+dy[i]))
		{
			dfs(x+dx[i], y+dy[i]);
		}
	}
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
			}
		}
		int ans = 0;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (!vis[i][j] && c[i][j]=='.')
				{
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans;
	}

	return 0;

}