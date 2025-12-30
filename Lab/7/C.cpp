#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N=1005;
 
int n,a[N],tag[N],fa[N];
struct Node{int lch,rch;}node[N];
 
inline void dfs(int pos){
  if(node[pos].lch) dfs(node[pos].lch);
  if(node[pos].rch) dfs(node[pos].rch);
  cout<<pos<<' ';
}
 
inline void init(){
  for(int i=1;i<=1000;++i)
    tag[i]=0,fa[i]=0,node[i]=node[0];
}
 
signed main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n;
    init();
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
      int x;
      cin>>x;
      tag[x]=i;
    }
    int cur=a[1],rtt=0; fa[a[1]]=a[1];
    for(int i=2;i<=n;++i){
      if(tag[a[i]]<tag[cur]){
        node[cur].lch=a[i];
        ++rtt;
      } else{
        while(rtt&&cur!=a[1]&&tag[fa[cur]]<tag[a[i]]){
          if(cur==node[fa[cur]].lch) --rtt;
          cur=fa[cur];
        }
        // cout<<i<<' '<<cur<<'\n';
        node[cur].rch=a[i];
      }
      fa[a[i]]=cur;
      cur=a[i];
      // cout<<i<<' '<<cur<<'\n';
    }
    // for(int i=1;i<=n;++i) cout<<fa[i]<<' '; cout<<'\n';
    dfs(a[1]);
    cout<<'\n';
  }
  return 0;
}
/*
1
6
1 2 3 4 5 6
3 2 4 1 6 5
 
3 4 2 6 5 1
-----
1
7
2 1 7 4 3 5 6
1 2 3 4 5 6 7

7 6 5 4 3 2 1 
*/