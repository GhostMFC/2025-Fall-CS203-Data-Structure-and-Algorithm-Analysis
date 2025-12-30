#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1005;

int n,pre[N],in[N],pos=1,tag[N];
struct Node{int lch,rch;}node[N];

inline void build(int root,int l,int r){//l,r correspond to in-order
  // cout<<pos<<' '<<root<<' '<<l<<' '<<r<<'\n';
  if(l>=r) return ;
  int nxt=in[pre[pos+1]];
  if(nxt>r||nxt<l) return ;//actually only > r is possible
  if(nxt<in[root]){
    node[root].lch=pre[++pos];
    build(pre[pos],l,in[root]-1);//left tree
  }
  nxt=in[pre[pos+1]];
  // cout<<root<<' '<<l<<' '<<r<<' '<<nxt<<'\n';
  if(nxt>r||nxt<l) return ;
  node[root].rch=pre[++pos];
  build(pre[pos],in[root]+1,r);
}

inline void dfs(int pos){
  if(node[pos].lch) dfs(node[pos].lch);
  if(node[pos].rch) dfs(node[pos].rch);
  cout<<pos<<' ';
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n; pos=1;
    for(int i=1;i<=n;++i) cin>>pre[i],node[i]=node[0];
    for(int i=1;i<=n;++i){
      cin>>tag[i];
      in[tag[i]]=i;//in-order position
    } pre[n+1]=0;
    build(pre[1],1,n);
    dfs(pre[1]);
    cout<<'\n';
    // cout<<"\n------------\n";
    // for(int i=1;i<=n;++i)
    //   cout<<node[i].lch<<' '<<node[i].rch<<'\n';
  }
  return 0;
}