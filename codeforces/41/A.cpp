#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string t,s;
    cin>>t>>s;
    reverse(s.begin(),s.end());
    if(t==s)cout<<"YES";
    else cout<<"NO";
    return 0;
}