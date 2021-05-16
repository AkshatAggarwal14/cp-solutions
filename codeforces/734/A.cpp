#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,a=0,d=0;cin>>n;
    char s[n];
    cin>>s;
    for(ll i=0;i<n;i++){
        if(s[i]=='A')a++;
        else if(s[i]=='D')d++;
    }
    if(a>d)cout<<"Anton";
    else if(a<d)cout<<"Danik";
    else cout<<"Friendship"; return 0;
    
}