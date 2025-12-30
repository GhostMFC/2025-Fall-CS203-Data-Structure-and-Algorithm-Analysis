#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,a[N],fa[N];
struct Node{
  int l,r;
}node[N];

inline bool dfs(int pos,int val){
  // cout<<pos<<' '<<val<<'\n';
  if(val>n) return false;
  if(node[pos].l) if(!dfs(node[pos].l,val<<1)) return false;
  else if(node[pos].r) if(!dfs(node[pos].r,val<<1|1)) return false;
  return true;
}

signed main(){
  IOS
  int T,kase=0;
  cin>>T;
  while(T--){
    bool bg=false,sm=false;
    cin>>n; ++kase;
    for(int i=1;i<=n;++i) cin>>a[i],fa[i]=0,node[i]=node[0];
    bool _2=false;//is binary
    for(int i=1;i<n;++i){
      int x,y;
      cin>>x>>y;
      fa[y]=x;
      if(node[x].r){ _2=true; continue;}
      if(node[x].l) node[x].r=y;
      else node[x].l=y;
      if(a[x]>a[y]) bg=true;
      else if(a[x]<a[y]) sm=true;
    }
    cout<<"Case #"<<kase<<": ";
    if(_2||(bg&&sm)){ cout<<"NO\n"; continue;}//binary&&order
    int root=1;
    while(fa[root]) root=fa[root];
    cout<<(dfs(root,1)?"YES":"NO")<<'\n';
  }
  return 0;
}