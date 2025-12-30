#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1000010;

#define int ll

int rec[N];
int n,a[N],tmp[N],ans[N],res[N];

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid); merge(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(i<=mid&&j<=r){
    if(a[i]<=a[j]) tmp[k++]=a[i++];
    else tmp[k++]=a[j++];
  }
  while(i<=mid) tmp[k++]=a[i++];
  while(j<=r) tmp[k++]=a[j++];
  for(int p=l;p<=r;p++) a[p]=tmp[p];
}

inline bool check(int x){
  int orix=x;
  while(x>2&&a[x]==a[x-1]&&!rec[x]) x--;
  if(rec[x]==1) return false;
  else if(rec[x]==2) return true;
  ans[1]=a[1]; ans[2]=a[x];
  int l=2,r=x+1;
  for(int i=3;i<=n;++i){
    if(ans[i-1]>=a[x]&&ans[i-2]>=a[x]){
      if(l<x) ans[i]=a[l++];
      else if(r<=n) ans[i]=a[r++];
      else return false;
    } else{//only one bigger than or equal to x
      if(r<=n) ans[i]=a[r++];
      else return false;
    }
    // cout<<x<<' '<<ans[i]<<'\n';
  }
  if((ans[n]>=ans[2]||ans[2]==ans[1])&&((ans[n]>=a[x])+(ans[n-1]>=a[x])+(ans[1]==a[x]))>1){
    rec[x]=2;
    for(int i=1;i<=n;i++) res[i]=ans[i];
  } rec[x]=1;
  for(int i=x+1;i<=orix;i++) rec[i]=rec[x];
  return (ans[n]>=ans[2]||ans[2]==ans[1])&&((ans[n]>=a[x])+(ans[n-1]>=a[x])+(ans[1]==a[x]))>1;
}

signed main(){
  IOS
  // freopen("input.txt", "r", stdin);
  // freopen("E.txt", "w", stdout);
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  merge(1,n);
  int l=2,r=n;
  while(l<r){
    int mid=(l+r+1)>>1;
    if(check(mid)) l=mid;
    else r=mid-1;
  }
  check(l);
  cout<<a[l]<<'\n';
  for(int i=1;i<=n;i++) cout<<res[i]<<" ";
  cout<<'\n';
  return 0;
}