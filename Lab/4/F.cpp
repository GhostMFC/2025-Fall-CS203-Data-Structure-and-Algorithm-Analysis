#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

bool vis[N];
int n,q[N],len,init;
struct Node{
  int x,l,r;
}node[N];

inline void del(int x){
  node[node[x].r].l=node[x].l;
  node[node[x].l].r=node[x].r;
}

signed main(){
  // freopen("F.in","r",stdin);
  // freopen("F.txt","w",stdout);
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n;
    node[0].r=1,node[n+1].l=n,node[n+1].x=1e9;
    for(int i=1;i<=n;++i)
      cin>>node[i].x,node[i].l=i-1,node[i].r=i+1,vis[i]=false;
    init=len=0;
    for(int i=1;i<n;++i){
      if(node[i].x>node[i+1].x){
        q[++len]=i;
        while(node[i+1].x>node[i+2].x)
          ++i;
      }
    }
    while(init<len){
      int pos=q[++init];
      if(!pos||pos>n||vis[pos]) continue;
      if(node[node[pos].r].x>=node[pos].x) continue;
      vis[pos]=true;
      del(pos);
      // cout<<pos<<' ';
      while(node[node[pos].r].x<node[pos].x){
        pos=node[pos].r;
        del(pos); vis[pos]=true;
      }
      // cout<<pos<<'\n';
      pos=node[pos].r;
      if(!pos||pos>n) continue;
      if(node[node[pos].l].x>node[pos].x){
        while(pos>1&&node[node[pos].l].x>node[pos].x)
          pos=node[pos].l;
        q[++len]=pos;
      }
    }

    int pos=node[0].r;
    while(pos<=n) cout<<node[pos].x<<' ',pos=node[pos].r;
    cout<<'\n';
  }

  return 0;
}
/*
1
9
93831 88951 955 56042 77070 6004173 54673 64526 88986

56042 88986
*/