#include<iostream>
int main(){
    long int n;
    std::cin>>n;
    std::cout<<(n%5==0?n/5:n/5+1);        
    return 0;
}