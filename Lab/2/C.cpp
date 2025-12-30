#include <iostream>
#include <string>
#define inf 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int a[N];

signed main(){
  IOS
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;++i) cin>>a[i];
  a[n+1]=inf;
  while(q--){
    int x,y;
    cin>>x>>y;
    int L,R;
    int l=0,r=n+1;
    while(l<r){
      int mid=(l+r)>>1;
      if(a[mid]>x) r=mid;
      else l=mid+1;
    } L=l;
    l=0,r=n+1;
    while(l<r){
      int mid=(l+r+1)>>1;
      if(a[mid]<y) l=mid;
      else r=mid-1;
    } R=r;
    int ans=R-L+1;
    if(ans>0) cout<<"YES"<<' '<<ans<<'\n';
    else cout<<"NO"<<'\n';
  }

  return 0;
}