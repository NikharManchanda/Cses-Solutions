// Problem: Array Description
// Time: 02/02/2022 15:17:52
// Time Limit: 1000 ms
// Memory Limit: 512 mb
// My CLI Parser Github Link: https://github.com/NikharManchanda/Cp-Test-Case-Checker-and-Parser
// Author: Rahkin

// Sit Down Bitch, Be humble

#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------*/
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//        tree_order_statistics_node_update> ordered_set;
/*------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 42
#endif
/*------------------------------------------------------------------*/
#define int               long long
#define rev               greater<int>()
/*------------------------------------------------------------------*/
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
#define imin              INT_MIN
#define imax              INT_MAX
#define lmin              LLONG_MIN
#define lmax              LLONG_MAX
#define Yes               cout<<"Yes\n"
#define No                cout<<"No\n"
#define YES               cout<<"YES\n"
#define NO                cout<<"NO\n"
#define yes               cout<<"yes\n"
#define no                cout<<"no\n"
#define read(A) for (auto &I: (A)) cin>>I;
#define show(A) for (auto I: (A)) cout << I << " "; cout << '\n';
#define sz(x)             (int)((x).size())

const double Pi = acos(-1.0);
const int mod = 1e9+7;
const int mod2 = 998244353;

const int N1 = 2e5+5;
const int N2 = 2e6+5;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
/*----------------------------------------------------------*/
void setIO(const string& s)
{
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
void input()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}
void local()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/*--------------------------------------------------------*/

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	input();

	int t = 1;
//	cin >> t;
	for (int test = 1; test<=t; test++)
	{
		int n, m;
		cin >> n >> m;
		int a[n];
		read(a);
		vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
		if (a[0]==0)
		{
			for (int j = 1; j<=m; j++)
				dp[0][j] = 1;
		}
		else
		{
			dp[0][a[0]] = 1;
		}
		for (int i = 1; i<n; i++)
		{
			if (a[i]==0)
			{
				for (int j = 1; j<=m; j++)
				{
					int sum = 0;
					sum += dp[i-1][j];
					sum %= mod;
					if (j>=1)
					{
						sum += dp[i-1][j-1];
						sum %= mod;
					}
					if (j+1<=m)
					{
						sum += dp[i-1][j+1];
						sum %= mod;
					}
					dp[i][j] = sum;
				}
			}
			else
			{
				int sum = 0;
				sum += dp[i-1][a[i]];
				sum %= mod;
				if (a[i]>=1)
				{
					sum += dp[i-1][a[i]-1];
					sum %= mod;
				}
				if (a[i]+1<=m)
				{
					sum += dp[i-1][a[i]+1];
					sum %= mod;
				}
				dp[i][a[i]] = sum;
			}
		}
		int ans = 0;
		if (a[n-1]==0)
		{
			for (int j = 1; j<=m; j++)
			{
				ans += dp[n-1][j];
				ans %= mod;
			}
		}
		else
		{
			ans = dp[n-1][a[n-1]];
		}
		cout << ans;
	}

	return 0;

}