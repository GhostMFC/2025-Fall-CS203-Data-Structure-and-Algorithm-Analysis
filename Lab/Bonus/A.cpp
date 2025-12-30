#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=30005;

int n;
ll k,a[N],b[N];

inline bool check(ll x){
  for(int i=1;i<=n;++i) b[i]=a[i];
  ll res=0;
  for(int i=1;i<=n;++i){
    res+=b[i]/x;
    b[i]%=x;
    if(b[i]+b[i+1]>=x) b[i+1]+=b[i];
  }
  return res>=k;
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>k;
    for(int i=1;i<=n;++i)
      cin>>a[i];
    ll l=0,r=1e18;
    while(l<r){
      ll mid=(l+r+1)>>1;
      if(check(mid)) l=mid;
      else r=mid-1;
    }
    cout<<l*k<<'\n';
  }
  return 0;
}