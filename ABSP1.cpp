#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long int sum = 0;
        long long int arr[n];
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];
        for(int i = 1 ; i <= n/2 ; i++)
        {
            long long int diff = arr[i] - arr[i-1];
            sum += (((i*n)-(i*i))*diff);
            //cout << ((i*n)-(i*i)) << endl;
        }
        for(int i = (n/2)+1 ; i < n ; i++)
        {
            long long int diff = arr[i] - arr[i-1];
            sum += ((((n-i)*n)-((n-i)*(n-i)))*diff);
            //cout << (((n-i)*n)-((n-i)*(n-i))) << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
