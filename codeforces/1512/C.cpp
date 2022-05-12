#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll temp1 = a, temp2 = b;
    string s;
    cin >> s;
    ll i = 0, j = s.length() - 1, flag = 0;

    a -= count(s.begin(), s.end(), '0'); //Subtract the 0 and 1 already
    b -= count(s.begin(), s.end(), '1');

    for (ll i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            if (s[i] == '?')
            {
                s[i] = s[j];
                (s[j] == '0') ? a-- : b--;
            }
            else if (s[j] == '?')
            {
                s[j] = s[i];
                (s[i] == '0') ? a-- : b--;
            }
        }
    }

    //??????0????????

    for (ll i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if (s[i] == s[j] && s[i] == '?')
        {
            if (a >= 2)
            {
                s[i] = s[j] = '0';
                a -= 2;
            }
            else if (b >= 2)
            {
                s[i] = s[j] = '1';
                b -= 2;
            }
        }
        else if (s[i] != s[j] && s[i] != '?' && s[j] != '?')
        {
            flag = 1;
            break;
        }
    }

    if (flag) //if 0 and 1 are in palindrome positions to each other, thus not possible, EXAMPLE: 0??1
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        if ((temp1 + temp2) % 2 != 0) //if odd string length mid element is still remaining
        {
            ll mid = (temp2 + temp1) / 2;
            if (s[mid] == '?')
                (a > 0) ? s[mid] = '0' : s[mid] = '1';
        }
        if (count(s.begin(), s.end(), '1') == temp2 && count(s.begin(), s.end(), '0') == temp1)
            cout << s << endl;
        else // as in case 0's=3,1's=3 ??????
            cout << -1 << endl;
    }
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
