#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--){
        int r, g, b, w, cnt = 0;
        cin >> r >> g >> b >> w;
        if(r % 2 == 0) cnt++;
        if(g % 2 == 0) cnt++;
        if(b % 2 == 0) cnt++;
        if(w % 2 == 0) cnt++;
        
        if(cnt > 2 || cnt == 0) cout << "Yes" << endl;
        else if(cnt == 2) cout << "No" << endl;
        else if(cnt == 1 && r > 0 && g > 0 && b > 0) cout << "Yes" << endl;
        else  cout << "No" << endl;
    }
}