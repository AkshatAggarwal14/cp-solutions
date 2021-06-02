#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin>>a;
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=1;i<a.length();i++)
    {
        if(a[i]!=a[i-1])ans++;
    }
    if(ans&1)
    cout<<"CHAT WITH HER!"<<endl;
    else cout<<"IGNORE HIM!"<<endl;
    return 0;
}