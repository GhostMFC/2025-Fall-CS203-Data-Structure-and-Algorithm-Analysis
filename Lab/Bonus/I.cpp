#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,g,l;
struct Node{ int a,b;}gain[N],loss[N];

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n; g=l=0;
    for(int i=1;i<=n;++i){
      int a,b;
      cin>>a>>b;
      if(a<=b) gain[++g]={a,b};
      else loss[++l]={a,b};
    }
    ll open=0,ans=0;
    for(int i=1;i<=g;++i){
      if(open>=gain[i].a) open-=gain[i].a;
      else ans+=(gain[i].a-open),open=0;
      open+=gain[i].b;
    }
    for(int i=1;i<=l;++i){
      if(open>=loss[i].a) open-=loss[i].a;
      else ans+=(loss[i].a-open),open=0;
      open+=loss[i].b;
    }
    cout<<ans+open<<'\n';
  }
  return 0;
}