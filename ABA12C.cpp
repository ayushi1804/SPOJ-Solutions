#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];
int cost[101];

int minCost(int n, int k, int currIdx)
{
	if(k == 0)
		return dp[n][k][currIdx] = 0;
	if(n == 0 || currIdx == 0 || k < 0)
		return INT_MAX;
	if(dp[n][k][currIdx] != -1)
		return dp[n][k][currIdx];
	if(cost[currIdx] == -1)
		return dp[n][k][currIdx] = minCost(n,k,currIdx-1);
	int opt1 = minCost(n-1,k-currIdx,currIdx), opt2 = minCost(n,k,currIdx-1);
	if(opt1 != INT_MAX)
		opt1 += cost[currIdx]; 
	return dp[n][k][currIdx] = min(opt1,opt2);
}

int main()
{
    #ifndef ONLINE_JUDGE
    clock_t start_s = clock();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--)
    {
    	memset(dp,-1,sizeof(dp));
    	int n,k;
    	cin >> n >> k;
    	for(int i = 1; i <= k; ++i)
    		cin >> cost[i];
    	int ans = minCost(n,k,k);
    	ans == INT_MAX ? cout << -1 << endl : cout << ans << endl;
    }
    #ifndef ONLINE_JUDGE
    clock_t stop_s = clock();
    cout << "Time Elapsed: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000 << " ms" << endl;
    #endif
    return 0;
}
