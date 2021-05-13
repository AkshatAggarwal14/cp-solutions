#include<stdio.h>
int main()
{
    long long int n,x, count=0;
    scanf("%lld", &n);
    while(n)
    {
        x=n%10;
        if(x==4 || x==7)
           count++;
        n/=10;
    }
 
    if(count==4 || count==7)
        printf("YES");
    else
        printf("NO");
 
    return 0;
 
}