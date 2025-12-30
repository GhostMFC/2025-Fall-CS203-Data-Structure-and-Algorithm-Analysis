#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=10;

int n,m;
bool invalid[1<<N];
ll a[N][N],dp[N][1<<N];

inline void solve(){
  int base=(1<<m)-1;
  for(int mask=0;mask<=base;++mask){
    bool tag=false;
    tag|=mask&(mask<<1);
    if(tag){
      dp[1][mask]=-1,invalid[mask]=true;
      continue;
    }
    ll res=0;
    for(int i=0;i<m;++i)
      if(mask&(1<<i))
        res+=a[1][i+1];
    dp[1][mask]=res;
  }
  ll ans=0;
  for(int i=2;i<=n;++i){
    for(int tmp=0;tmp<=base;++tmp)
      dp[i][tmp]=0;
    for(int pre=0;pre<=base;++pre)
      for(int cur=0;cur<=base;++cur){
        if(invalid[pre]||invalid[cur]) continue;
        if(invalid[pre|cur]) continue;
        bool tag=(pre&cur);
        if(tag) continue;
        ll res=0;
        for(int j=0;j<m;++j)
          if(cur&(1<<j))
            res+=a[i][j+1];
        dp[i][cur]=max(dp[i][cur],dp[i-1][pre]+res);
        ans=max(ans,dp[i][cur]);
      }
  }
  cout<<ans<<'\n';
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
        cin>>a[i][j];
    solve();
  }
  return 0;
}