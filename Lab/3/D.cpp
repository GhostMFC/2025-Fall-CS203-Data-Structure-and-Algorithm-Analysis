#include <iostream>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1000010;

int a[N];

signed main(){
  IOS
  int n,k;
  cin>>n>>k;
  for(register int i=1;i<=n;i++){
    int x;
    cin>>x;
    ++a[x];
  }
  for(register int i=1;i<=1000000;++i) a[i]+=a[i-1];
  int l=0,r=1000000;
  while(l<r){
    int mid=(l+r)>>1;
    if(a[mid]>=k) r=mid;
    else l=mid+1;
  } cout<<l<<'\n';

  return 0;
}