#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=200010;

int n,m,cnt,head[N],fa[N];
struct Node{ int l,r;}node[N];
struct Edge{
  int to,nxt;
}edge[N<<1];
inline void Add(int fo,int to){
  edge[++cnt]={to,head[fo]};
  head[fo]=cnt;
}

int tot;
inline void dfs(int pos,int fafa){
  node[pos].l=++tot;
  for(int i=head[pos];i;i=edge[i].nxt){
    int &to=edge[i].to;
    if(to^fafa) dfs(to,pos);
  }
  node[pos].r=++tot;
}

signed main(){
  IOS
  int t;
  cin>>t;
  while(t--){
    cin>>n>>m; cnt=tot=0;
    for(int i=1;i<=n;++i)
      head[i]=0,fa[i]=0,node[i]=node[0];
    for(int i=1;i<n;++i){
      int x,y;
      cin>>x>>y;
      fa[x]=y;
      Add(x,y);
      Add(y,x);
    }
    int ori=1;
    while(fa[ori]) ori=fa[ori];
    dfs(ori,ori);
    while(m--){
      int x,y;
      cin>>x>>y;
      if(node[x].l>=node[y].l&&node[x].r<=node[y].r)
        cout<<"Yes"<<'\n';
      else cout<<"No\n";
    }
  }
  return 0;
}