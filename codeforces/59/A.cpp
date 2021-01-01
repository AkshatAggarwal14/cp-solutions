#include<iostream>

int main()
{
    char t[100];
    std::cin>>t;
    int c1=0,c2=0;
    for(int i =0;t[i]!='\0';i++){
        if(t[i]>=97 && t[i]<=122){//small
            c1++;
        }
        if(t[i]>=65 && t[i]<=90){//capital
            c2++;
        }
    }
    //std::cout<<c1<<" "<<c2<<"\n";
    if(c1>=c2){
        for(int i=0;t[i]!='\0';i++){
            if(t[i]>=65 && t[i]<=90){
                t[i]+=32;
            }
        }
    }
    else if(c2>c1){
        for(int i=0;t[i]!='\0';i++){
            if(t[i]>=97 && t[i]<=122){
                t[i]-=32;
            }
        }
    }
    std::cout<<t;
}