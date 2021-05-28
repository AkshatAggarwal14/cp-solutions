#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        long long int n, m, g = 0,p, f;
 
        scanf("%lld", &n);
        for (long long int i = 1; i <=cbrt(n); i++)
        {
            p = n-(i*i*i);
            f = cbrt(p);
            if ((p == (f*f*f)) && (p>0))
            {
                cout<<"YES\n";
                g++;
                break;
            }
        }
        if ((g == 0))
        {
            cout<<"NO\n";
        }
    }
    return 0;
}