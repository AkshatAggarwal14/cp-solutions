#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool primelikefunc(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

 
int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll sq = sqrt(n);
        if(sq*sq==n&&primelikefunc(sq)==true&&n!=1){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
}    