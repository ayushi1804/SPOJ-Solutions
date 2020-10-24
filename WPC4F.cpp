#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[20][3];
ll dp[20][3];

ll MinEner(int tur, int state, int n)
{
	if(state < 0 || state > 2)
		return INT_MAX;
	if(dp[tur][state] != -1)
		return dp[tur][state];
	if(tur == n-1)
		return arr[tur][state];
	ll ans = INT_MAX;
	for(int i = 0 ; i < 3 ; i++)
		if(i != state)
			ans = min(ans,MinEner(tur+1,i,n));
	return dp[tur][state] = ans+arr[tur][state];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	memset(dp,-1,sizeof(dp));
    	int n;
    	cin >> n;
    	for(int i = 0 ; i < n ; ++i)
    		for(int j = 0 ; j < 3 ; ++j)
    			cin >> arr[i][j];
    	cout << min(min(MinEner(0,0,n),MinEner(0,1,n)),MinEner(0,2,n)) << endl;
    }
    return 0;
}
