#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1000010;

int n,m,k,x;
struct Node{
  int l,r;
}node[N];

signed main(){
  IOS
  cin>>n>>m>>k>>x;
  for(int i=1;i<=n;++i){
    for(int j=2;j<m;++j)
      node[(i-1)*m+j]={(i-1)*m+j-1,(i-1)*m+j+1};
    node[(i-1)*m+1].r=(i-1)*m+2;
    node[i*m].l=i*m-1;
  }

  while(k--){
    int a,b;
    cin>>a>>b; ++a,++b;
    node[node[b].l].r=node[a].r;
    node[node[a].r].l=node[b].l;
    node[a].r=b; node[b].l=a;
  }
  int p=x+1;
  while(node[p].l) p=node[p].l;
  while(p){
    cout<<p-1<<' ';
    p=node[p].r;
  }
  return 0;
}