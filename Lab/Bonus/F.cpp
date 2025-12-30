#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

inline int lowbit(int x)
{ return x&(-x);}

signed main(){
  IOS
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    //x xor a > b
    // int ans=(a^b)+lowbit(b+lowbit(b));
    int ans=0;
    for(int i=30;i>=0;--i){
      if((ans^a)>b) break; 
      int o=(1<<i);
      if(b&o){
        if(a&o) continue;
        else ans|=o;
      }
    }
    if((ans^a)==b){
      int p=lowbit(b^((1<<30)-1));//lowest 0 to 1
      ans&=(((1<<30)-1)^(p-1));
      ans+=p;
    }
    cout<<ans<<'\n';
  }
  return 0;
}