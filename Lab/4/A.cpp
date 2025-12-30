#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1000010;

int n,m,len;
struct Node{
  ll co,ex;
}A[N],B[N],tmp[N<<1];

inline void merge(Node arr[],int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(arr,l,mid); merge(arr,mid+1,r);
  int i=l,j=mid+1,k=l;
  while(i<=mid&&j<=r){
    if(arr[i].ex<=arr[j].ex) tmp[k++]=arr[i++];
    else tmp[k++]=arr[j++];
  }
  while(i<=mid) tmp[k++]=arr[i++];
  while(j<=r) tmp[k++]=arr[j++];
  for(int p=l;p<=r;p++) arr[p]=tmp[p];
}

inline void solve(){
  merge(A,1,n);
  merge(B,1,m);
  int p1=1,p2=1;
  while(p1<=n&&p2<=m){
    tmp[++len]=tmp[0];
    if(A[p1].ex>B[p2].ex){
      tmp[len]=B[p2]; ++p2;
      while(p2<=m&&B[p2-1].ex==B[p2].ex)
        tmp[len].co+=B[p2].co,++p2;
    } else if(A[p1].ex<B[p2].ex){
      tmp[len]=A[p1]; ++p1;
      while(p1<=n&&A[p1-1].ex==A[p1].ex)
        tmp[len].co+=A[p1].co,++p1;
    } else{
      tmp[len].ex=A[p1].ex;
      tmp[len].co=A[p1].co+B[p2].co;
      ++p1,++p2;
      while(p1<=n&&A[p1-1].ex==A[p1].ex)
        tmp[len].co+=A[p1].co,++p1;
      while(p2<=m&&B[p2-1].ex==B[p2].ex)
        tmp[len].co+=B[p2].co,++p2;
    }
  }
  while(p1<=n){
    tmp[++len]=tmp[0];
    tmp[len]=A[p1++];
    while(p1<=n&&A[p1-1].ex==A[p1].ex)
      tmp[len].co+=A[p1].co,++p1;
  }
  while(p2<=m){
    tmp[++len]=tmp[0];
    tmp[len]=B[p2++];
    while(p2<=m&&B[p2-1].ex==B[p2].ex)
      tmp[len].co+=B[p2].co,++p2;
  }
  cout<<len<<'\n';
  for(int i=len;i;--i)
    cout<<tmp[i].co<<' '<<tmp[i].ex<<'\n';
}

signed main(){
  IOS
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    cin>>A[i].co>>A[i].ex;
  for(int i=1;i<=m;++i)
    cin>>B[i].co>>B[i].ex;
  solve();
  return 0;
}