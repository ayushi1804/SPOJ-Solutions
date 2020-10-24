#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f first
#define s second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long int ll;

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
    	int n;
    	cin >> n;
    	int a[n],s[n],o[n];
    	for(int i = 0; i < n ; ++i)
    		cin >> a[i] >> s[i] >> o[i];
    	int cycRep = a[0]+s[0];
    	for(int i = 1; i < n; ++i)
    		cycRep = (cycRep*(a[i]+s[i]))/__gcd(cycRep,(a[i]+s[i]));
    	bool isPossible = false;
    	for(int i = 0; i < cycRep; ++i)
    	{
    		bool allSleep = true;
    		for(int i = 0; allSleep && i < n; ++i)
    			if(o[i] < a[i])
    				allSleep = false;
    		if(allSleep)
    		{
    			cout << i << endl;
    			isPossible = true;
    			break;
    		}
    		for(int i = 0; i < n; ++i)
    			o[i] = (o[i]+1)%(a[i]+s[i]);
    	}
    	if(!isPossible)
    		cout << "Foxen are too powerful" << endl;
    }
    #ifndef ONLINE_JUDGE
    clock_t stop_s = clock();
    cout << "Time Elapsed: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000 << " ms" << endl;
    #endif
    return 0;
}
