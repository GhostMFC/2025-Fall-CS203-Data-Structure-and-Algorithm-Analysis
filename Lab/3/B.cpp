#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=5000010;

#define int ll

int a[N],tmp[N];

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid); merge(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(i<=mid && j<=r){
    if(a[i]<=a[j]) tmp[k++]=a[i++];
    else tmp[k++]=a[j++];
  }
  while(i<=mid) tmp[k++]=a[i++];
  while(j<=r) tmp[k++]=a[j++];
  for(int p=l;p<=r;p++) a[p]=tmp[p];
}

signed main(){
  IOS
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  merge(1,n);
  cout<<a[(n+1)/2]+a[(n+2)/2]<<'\n';

  return 0;
}