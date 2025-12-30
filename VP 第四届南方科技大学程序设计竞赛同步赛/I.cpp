#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1005;

int n,m;
int dis[N][N];
bool vis[N][N];
char mp[N][N];
struct Node{
  int x,y,val;
  bool operator<(const Node& o)const{
    return val<o.val;
  }
};

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

inline void solve(){
  memset(dis,0x3f,sizeof(dis));
  priority_queue<Node> pq;
  for(int i=1;i<=m;++i){
    dis[1][i]=!(mp[1][i]-'0');
    pq.push({1,i,-dis[1][i]});
  }
  while(pq.size()){
    Node c=pq.top();
    pq.pop();
    // cout<<c.x<<' '<<c.y<<' '<<-c.val<<'\n';
    if(vis[c.x][c.y]) continue;
    vis[c.x][c.y]=true;
    for(int i=0;i<4;++i){
      int tx=c.x+dx[i],ty=c.y+dy[i];
      if(tx<1||tx>n||ty<1||ty>m) continue;
      if(vis[tx][ty]) continue;
      int tmp=dis[c.x][c.y]+!(mp[tx][ty]-'0');
      if(tmp>=dis[tx][ty]) continue;
      dis[tx][ty]=tmp;
      pq.push({tx,ty,-dis[tx][ty]});
    }
  }
  int ans=1e9;
  for(int i=1;i<=m;++i)
    ans=min(ans,dis[n][i]);
  cout<<ans<<'\n';
}

signed main(){
  IOS
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      cin>>mp[i][j];
  solve();
  return 0;
}