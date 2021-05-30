#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(string s)
{
    string str=s;
    reverse(str.begin(),str.end());
    if(s!=str)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       string str=s;
       string sr=s;
       ll n=s.size();
       ll count=0;
       int flag=1;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='a')
           {
               count++;
           }
       }
       if(count==n)
       {
           flag=0;
       }
       else if(count%2==0)
       {
           str=str+'a';
           if(!check(str))
           {
                sr='a'+sr;
                if(!check(sr))
                {
                    flag=0;
                }
                else
                {
                    s='a'+s;
                }
           }
           else
           {
               s=s+'a';
           }
       }
       else if(count%2!=0)
       {
            str+='a';
            if(check(str))
            {
                s+='a';
            }
            else
            {
                sr='a'+sr;
                if(!check(sr))
                {
                    flag=0;
                }
                else
                {
                    s='a'+s;
                }
            }
       }
       if(flag)
       {
           cout<<"YES"<<'\n';
           cout<<s<<'\n';
       }
       else
       {
           cout<<"NO"<<'\n';
       }
    }
}