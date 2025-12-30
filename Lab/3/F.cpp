#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=200010;

#define int ll

int n,p,q;
struct Node{
  int h,s;
}node[N],tmp[N];

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid); merge(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(i<=mid&&j<=r){
    if(node[i].h-node[i].s>=node[j].h-node[j].s) tmp[k++]=node[i++];
    else tmp[k++]=node[j++];
  }
  while(i<=mid) tmp[k++]=node[i++];
  while(j<=r) tmp[k++]=node[j++];
  for(int p=l;p<=r;p++) node[p]=tmp[p];
}

signed main(){
  IOS
  cin>>n>>p>>q;
  for(int i=1;i<=n;i++) cin>>node[i].h>>node[i].s;
  merge(1,n);
  int base=0;
  for(int i=1;i<=q;++i){
    if(node[i].h>node[i].s) base+=node[i].h;
    else base+=node[i].s;
  }
  for(int i=q+1;i<=n;++i) base+=node[i].s;
  int ans=0,_2=(1<<p);
  if(q){
    for(int i=1;i<=q;++i)
      ans=max(ans,node[i].h*_2-max(node[i].s,node[i].h));
    for(int i=q+1;i<=n;++i)
        ans=max(ans,node[i].h*_2-node[i].s-max(node[q].h,node[q].s)+node[q].s);
  }
  cout<<ans+base<<'\n';
  return 0;
}