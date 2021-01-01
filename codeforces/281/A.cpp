#include<iostream>

int main(){
    char a[1000];
    std::cin>>a;
    if(a[0]<=122 && a[0]>=97){
        a[0]=a[0]-32;
    }
    std::cout<<a;
    return 0;
}
