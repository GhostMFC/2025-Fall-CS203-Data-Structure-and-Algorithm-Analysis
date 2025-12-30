#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=300010;

int n,ans[N],mp[N],len;
struct Node{
  int x,l,r,num;
}node[N],tmp[N];

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid); merge(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(i<=mid&&j<=r){
    if(node[i].x<=node[j].x) tmp[k++]=node[i++];
    else tmp[k++]=node[j++];
  }
  while(i<=mid) tmp[k++]=node[i++];
  while(j<=r) tmp[k++]=node[j++];
  for(int p=l;p<=r;p++) node[p]=tmp[p];
}

inline void del(int pos){
  node[node[pos].r].l=node[pos].l;
  node[node[pos].l].r=node[pos].r;
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n; len=0;
    for(int i=1;i<=n;++i)
      cin>>node[i].x,node[i].num=i;
    merge(1,n);
    for(int i=1;i<=n;++i){
      node[i].l=i-1,node[i].r=i+1;
      mp[node[i].num]=i;
    } node[0].r=1,node[n+1].l=n;
    int mid=(n+1)/2;
    if(n%2==0) del(n);

    ans[++len]=node[mid].x;
    for(int i=n;i>1;i-=2){
      int p1=mp[i],p2=mp[i-1];
      if(p1>mid&&p2>mid) mid=node[mid].l;
      else if(p1<mid&&p2<mid) mid=node[mid].r;
      else if((p1>mid&&p2<mid)||(p1<mid&&p2>mid)) void();
      else{//mid will be del
        if(p1>mid||p2>mid)
          mid=node[mid].l;
        else mid=node[mid].r;
      }
      del(p1),del(p2);
      ans[++len]=node[mid].x;
    }
    for(int i=len;i;--i) cout<<ans[i]<<' ';
    cout<<'\n';
  }
  return 0;
}
/*
1
7
5 2 3 8 1 7 0

5 3 3 3
*/