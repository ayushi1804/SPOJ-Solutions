#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll findMinPath(int i, int j, int** graph, int n, ll** dp)
{
    if(j < 0 || j >= 3 || i >= n)
        return INT_MAX;
    if(i == n-1 && j == 1)
        return graph[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    ll opt1 = graph[i][j] + findMinPath(i+1,j-1,graph,n,dp);
    ll opt2 = graph[i][j] + findMinPath(i+1,j,graph,n,dp);
    ll opt3 = graph[i][j] + findMinPath(i+1,j+1,graph,n,dp);
    ll opt4 = graph[i][j] + findMinPath(i,j+1,graph,n,dp);
    dp[i][j] = min(min(opt1,opt2),min(opt3,opt4));
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 0;
    while(++t)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        int** graph = new int*[n];
        ll** dp = new ll*[n];
        for(int i = 0 ; i < n ; i++)
        {
            graph[i] = new int[3];
            dp[i] = new ll[3];
            for(int j = 0 ; j < 3 ; j++)
            {
                cin >> graph[i][j];
                dp[i][j] = -1;
            }
        }
        cout << t << ". " << findMinPath(0,1,graph,n,dp) << endl;
        for(int i = 0 ; i < n ; i++)
        {
            delete[] dp[i];
            delete[] graph[i];
        }
        delete[] dp;
        delete[] graph;
    }
    return 0;
}
