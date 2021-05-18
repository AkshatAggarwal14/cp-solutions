#include <iostream>
using namespace std;
int main()
{
    unsigned long long n, m, a, temp = 1;
    cin>>n>>m>>a;
    if (n%a == 0)
        temp *= n/a;
    else
        temp *= (n/a + 1);
    if (m%a == 0)
        temp *= m/a;
    else
        temp *= (m/a + 1);
    cout<<temp;
    return 0;
}