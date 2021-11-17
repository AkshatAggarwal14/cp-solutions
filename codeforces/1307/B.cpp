#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int T; cin>>T;
  while (T--){
    int N,X;
    cin>>N>>X;
    set<int>a;
    int far=0; //largest favorite number
    for (int i=0;i<N;i++){
      int A;
      cin>>A;
      a.insert(A);
      far=max(far,A);
    }
    if (a.count(X)) //X is favorite number
      cout<<1<<endl;
    else
      cout<<max(2,(X+far-1)/far)<<endl; // ceil
  }
}