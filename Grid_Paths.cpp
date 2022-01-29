// Time: 29/01/2022 22:36:01
// Url: https://cses.fi/problemset/task/1625
// Time Limit: 1000
// Memory Limit: 512
// User: Rahkin

#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
						 tree_order_statistics_node_update> ordered_set;
/*------------------------------------------------------------*/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V>& x)
{
	cerr << '{';
	__print(x.first);
	cerr << ',';
	__print(x.second);
	cerr << '}';
}
template<typename T>
void __print(const T& x)
{
	int f = 0;
	cerr << '{';
	for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
	cerr << "}";
}
void _print() { cerr << "]\n"; }
template<typename T, typename... V>
void _print(T t, V... v)
{
	__print(t);
	if (sizeof...(v)) cerr << ", ";
	_print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
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

template<typename T, typename T1> T amax(T& a, T1 b)
{
	if (b>a)a = b;
	return a;
}
template<typename T, typename T1> T amin(T& a, T1 b)
{
	if (b<a)a = b;
	return a;
}
/*----------------------------------------------------------*/
void setIO(const string& s)
{
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
void localIP()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}
void localOP()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
#endif
}
void localEr()
{
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}
/*--------------------------------------------------------*/

string s;
int ans;
bool vis[7][7];
bool e(int x, int y)
{
	return x<7 && x>=0 && y>=0 && y<7 && !vis[x][y];
}
void fun(int x, int y, int idx)
{
	int i = x;
	int j = y;
	if (x==6 && y==0)
	{
		if (idx==48)
			ans++;
		return;
	}
	vis[x][y] = 1;
	if (s[idx]=='?' || s[idx]=='R')
	{
		if (y+1<7 && !vis[x][y+1])
		{
			if (!(!e(i, j+2) && e(i-1, j+1) && e(i+1, j+1)))
				fun(x, y+1, idx+1);
		}
	}
	if (s[idx]=='?' || s[idx]=='L')
	{
		if (y>0 && !vis[x][y-1])
		{
			if (!(!e(i, j-2) && e(i-1, j-1) && e(i+1, j-1)))
				fun(x, y-1, idx+1);
		}
	}
	if (s[idx]=='?' || s[idx]=='U')
	{
		if (x>0 && !vis[x-1][y])
		{
			if (!(!e(i-2, j) && e(i-1, j-1) && e(i-1, j+1)))
				fun(x-1, y, idx+1);
		}
	}
	if (s[idx]=='?' || s[idx]=='D')
	{
		if (x<6 && !vis[x+1][y])
		{
			if (!(!e(i+2, j) && e(i+1, j-1) && e(i+1, j+1)))
				fun(x+1, y, idx+1);
		}

	}

	vis[x][y] = 0;

}
signed main()
{
	init();
	localIP();

	int t = 1;
//	cin >> t;
	for (int test = 1; test<=t; test++)
	{
		cin >> s;
		fun(0, 0, 0);
		cout << ans;
	}

	return 0;

}