#include <iostream>
#include <vector>
#include <string>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010,K=105;

struct Edge{ int to,nxt;}edge[N<<1];
int n,m,k,c,dis[N][K],col[N],head[N],cnt;
inline void Add(int fo,int to){
  edge[++cnt]={to,head[fo]};
  head[fo]=cnt;
}

inline void Swap(int &a,int &b)
{ int tmp=a; a=b; b=tmp;}
inline void quickSel(int arr[],int l,int r,int t){
  if(l>=r) return ;
  int v=(rand()%(r-l+1)+l);
  Swap(arr[l],arr[v]);
  int pivot=arr[l]; int it=l,i=l+1,gt=r;
  while(i<=gt){
    if(arr[i]<pivot){
      Swap(arr[i],arr[it]);
      ++i; ++it;
    } else if(arr[i]>pivot){
      Swap(arr[i],arr[gt]);
      --gt;
    } else ++i;
  }
  if(t<it) quickSel(arr,l,it-1,t);
  else if(t>gt) quickSel(arr,gt+1,r,t);
}

int q[N],hd,rr;
inline void solve(int color){
  hd=0,rr=0;
  for(int i=1;i<=n;++i)
    if(col[i]==color){
      q[++rr]=i;
      dis[i][color]=0;
    } else dis[i][color]=1e9;
  while(hd<rr){
    int p=q[++hd];
    for(int i=head[p];i;i=edge[i].nxt){
      int &to=edge[i].to;
      if(dis[to][color]>dis[p][color]+1){
        dis[to][color]=dis[p][color]+1;
        q[++rr]=to;
      }
    }
  }
}

signed main(){
  IOS
  cin>>n>>m>>k>>c;
  for(int i=1;i<=n;++i) cin>>col[i];
  for(int i=1;i<=m;++i){
    int u,v;
    cin>>u>>v;
    Add(u,v); Add(v,u);
  }

  for(int i=1;i<=k;++i) solve(i);
  for(int i=1;i<=n;++i){
    // for(int j=1;j<=k;++j)
    //   cout<<dis[i][j]<<' ';
    // cout<<'\n';
    quickSel(dis[i],1,k,c);
    ll res=0;
    for(int j=1;j<=c;++j)
      res+=dis[i][j];
    cout<<res<<' ';
  }

  return 0;
}