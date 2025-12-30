#include <iostream>
#include <string>
#define inf 0x3f3f3f3f
template <typename T> inline void sMin(T &xx,T yy){xx=(xx<yy)?xx:yy;}
template <typename T> inline void sMax(T &xx,T yy){xx=(xx>yy)?xx:yy;}
using namespace std;

const int N=200010;

int n,a[N];

signed main(){
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--){
    cin>>n;
    int ans=-inf,mx=-inf;
    for(int i=1;i<=n;++i){
      cin>>a[i];
      sMax(ans,mx-a[i]);
      sMax(mx,a[i]);
    }
    cout<<ans<<'\n';
  }
  return 0;
}