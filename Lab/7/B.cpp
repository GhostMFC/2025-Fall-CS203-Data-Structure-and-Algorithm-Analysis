#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=500010;

int n,cnt,num,ans,head[N];
struct Edge{
  int v,w,nxt;
}edge[N<<1];
inline void Add(int u,int v,int w){
  edge[++cnt]={v,w,head[u]};
  head[u]=cnt;
}

inline void dfs(int u,int fa,int sum){
  bool tag=false;
  for(int i=head[u];i;i=edge[i].nxt)
    if(edge[i].v^fa){
      dfs(edge[i].v,u,sum+edge[i].w);
      tag=true;
    }
  if(!tag) ans+=(sum==num);
}

signed main(){
  IOS
  cin>>n>>num;
  for(int i=1,u,v,w;i<n;++i){
    cin>>u>>v>>w;
    Add(u,v,w),Add(v,u,w);
  } dfs(1,1,0);
  cout<<ans<<'\n';
  return 0;
}