#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,m,a[N];
struct Node{
  int l,r;
}node[N];

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m; a[n+1]=n+1;
    for(int i=1;i<=n;++i)
      cin>>a[i],++a[i];
    for(int i=1;i<=n;++i)
      node[a[i]].l=a[i-1],node[a[i]].r=a[i+1];
    node[0].r=a[1],node[n+1].l=a[n];
    while(m--){
      int l1,r1,l2,r2;
      cin>>l1>>r1>>l2>>r2;
      ++l1,++r1,++l2,++r2;
      if(node[r1].r==l2){
        // cout<<l1<<' '<<r1<<'\n';
        node[l2].l=node[l1].l;
        node[l1].l=r2;
        node[r1].r=node[r2].r;
        node[r2].r=l1;
        node[node[l2].l].r=l2,
        node[node[r1].r].l=r1;
        // cout<<node[node[l2].l].r<<'\n';
      } else if(node[r2].r==l1){
        node[l1].l=node[l2].l;
        node[l2].l=r1;
        node[r2].r=node[r1].r;
        node[r1].r=l2;
        node[node[l1].l].r=l1,
        node[node[r2].r].l=r2;
      } else{
        node[node[l1].l].r=l2;
        node[node[l2].l].r=l1;
        node[node[r1].r].l=r2;
        node[node[r2].r].l=r1;
        swap(node[l1].l,node[l2].l);
        swap(node[r1].r,node[r2].r);
      }
      // int pos=node[0].r;
      // while(pos<=n) cout<<pos-1<<' ',pos=node[pos].r;
      // cout<<'\n';
    }
    int pos=node[0].r;
    while(pos<=n) cout<<pos-1<<' ',pos=node[pos].r;
    cout<<'\n';
  }

  return 0;
}