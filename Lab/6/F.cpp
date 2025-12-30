#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=500010,mod=456791,mod2=499787;

int n;
char mp[26],s[N];
ll _26[N][2],sufl[N][2],sufr[N][2];

inline void solve(){
  int ans=n;
  for(int i=(n+1)/2;i<n;++i){
    ll res=n-i;
    ll l[2]={sufl[res][0],sufl[res][1]};
    ll r[2]={(sufr[n][0]-sufr[i][0]*_26[n-i][0]%mod+mod)%mod,
          (sufr[n][1]-sufr[i][1]*_26[n-i][1]%mod2+mod2)%mod2};
    if(l[0]==r[0]&&l[1]==r[1]){
      ans=i;
      break;
    }
  }
  cout<<ans<<'\n';
}

signed main(){
  IOS
  for(int i=0;i<26;++i) cin>>mp[i];
  cin>>s+1;
  while(s[n+1]) ++n;
  _26[0][0]=_26[0][1]=1;
  for(int i=1;i<=n;++i){
    _26[i][0]=_26[i-1][0]*26%mod;
    _26[i][1]=_26[i-1][1]*26%mod2;
    sufl[i][0]=(sufl[i-1][0]*26+s[i])%mod;
    sufl[i][1]=(sufl[i-1][1]*26+s[i])%mod2;
    sufr[i][0]=(sufr[i-1][0]*26+mp[s[i]-'a'])%mod;//right side
    sufr[i][1]=(sufr[i-1][1]*26+mp[s[i]-'a'])%mod2;
  }
  solve();
  return 0;
}