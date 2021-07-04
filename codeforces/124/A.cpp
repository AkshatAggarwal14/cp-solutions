#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,a,b;
    cin>>n>>a>>b;
    cout<<n+1-max(a+1,n-b);
    return 0;
}