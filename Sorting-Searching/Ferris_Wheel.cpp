/**
 *    author:  Rahkin
 *    created: 08/02/2022 02:45:21 
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
		int n, w;
		cin >> n >> w;
		int a[n];
		read(a)
		sort(a, a+n);
		int l = 0, r = n-1;
		int ans = 0;
		while (l<=r)
		{
			if (l==r)
			{
				ans++;
				break;
			}
			if (a[r]+a[l]<=w)
			{
				ans++;
				r--;
				l++;
			}
			else
			{
				r--;
				ans++;
			}
		}
		cout << ans;
	}

	return 0;

}