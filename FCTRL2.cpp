#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector <int> fact;
        fact.push_back(1);
        int m = fact.size();
        for(int i = 2 ; i <= n ; i++)
        {
            int temp = 0;
            for(int j = 0 ; j < m ; j++)
            {
                int x = temp + (fact[j]*i);
                fact[j] = x % 10;
                temp = x / 10;
            }
            while (temp > 0)
            {
                fact.push_back(temp % 10);
                temp /= 10;
            }
            m = fact.size();
        }
        for(int i = fact.size()-1 ; i >= 0 ; i--)
            cout << fact[i];
        cout << endl;
    }
    return 0;
}
