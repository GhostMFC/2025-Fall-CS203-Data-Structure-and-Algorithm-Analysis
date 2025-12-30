#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=2000010;

int n,mp[N];
struct Node{
  ll x;
  int l,r,num;
}node[N],tmp[N];

inline void solve(){
  for(int i=1;i<n;++i){
    int pos=mp[i];
    node[node[pos].l].r=node[pos].r;
    node[node[pos].r].l=node[pos].l;
    ll res1=abs(node[node[pos].l].x-node[pos].x),
       res2=abs(node[node[pos].r].x-node[pos].x);
    cout<<min(res1,res2)<<' ';
  }
}

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid),merge(mid+1,r);
  int i=l,j=mid+1,idx=l;
  while(i<=mid&&j<=r){
    if(node[i].x<=node[j].x) tmp[idx++]=node[i++];
    else tmp[idx++]=node[j++];
  }
  while(i<=mid) tmp[idx++]=node[i++];
  while(j<=r) tmp[idx++]=node[j++];
  for(int k=l;k<=r;++k) node[k]=tmp[k];
}

signed main(){
  IOS
  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>node[i].x,node[i].num=i;
  merge(1,n);
  for(int i=1;i<=n;++i){
    node[i].l=i-1,node[i].r=i+1;
    mp[node[i].num]=i;
  } node[0].x=-1e18,node[n+1].x=1e18;
  solve();
  return 0;
}