#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define inf 2147483647
using namespace std;

const int N=500010;

int l,n,m,a[N];

inline bool check(int x){
  int tot=0,lst=0;
  for(int i=1;i<=n+1;++i){
    if(a[i]-a[i-1]>x) return false;
    if(a[i]-lst>x){
      lst=a[i-1];
      ++tot;
    }
  }
  // cout<<x<<' '<<tot<<' '<<m<<'\n';
  return tot<m;
}

signed main(){
  while(scanf("%d %d %d",&l,&n,&m)!=EOF){
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    a[n+1]=l,a[n+2]=inf;
    int L=1,R=1e9;
    while(L<R){
      int mid=(L+R)>>1;
      if(check(mid)) R=mid;
      else L=mid+1;
    }
    cout<<L<<'\n';
  }

  return 0;
}