#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f first
#define s second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long int ll;

ll dp[201][201];
pii arr[201];

ll ways(int n, int m)
{
	if(dp[n][m] != -1)
		return dp[n][m];
	if(m == 0 && n != 0)
		return dp[n][m] = 0;
	if(n == 0)
	{
		if(m > 0)
			return dp[n][m] = 0;
		return dp[n][m] = 1;
	}
	ll ans = 0;
	for(int i = arr[n].f ; i <= min(m,arr[n].s) ; ++i)
		ans = (ans+ways(n-1,m-i))%mod;
	return dp[n][m] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    clock_t start_s = clock();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	memset(dp,-1,sizeof(dp));
    	int n,m;
    	cin >> n >> m;
    	for(int i = 1 ; i <= n ; ++i)
    		cin >> arr[i].f >> arr[i].s;
    	cout << ways(n,m) << endl;
    }
    #ifndef ONLINE_JUDGE
    clock_t stop_s = clock();
    cout << "Time Elapsed: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " sec" << endl;
    #endif
    return 0;
}
