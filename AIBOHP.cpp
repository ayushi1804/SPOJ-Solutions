#include <bits/stdc++.h>
using namespace std;

string s;
int dp[6101][6101];

int minPal(int l, int r)
{
	if(l >= r)
		return 0;
	if(dp[l][r] != -1)
		return dp[l][r];
	if(s[l] == s[r])
		return dp[l][r] = minPal(l+1,r-1);
	return dp[l][r] = 1+min(minPal(l,r-1),minPal(l+1,r));
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
    	cin >> s;
    	memset(dp,-1,sizeof(dp));
    	cout << minPal(0,s.length()-1) << endl;
    }
    return 0;
}
