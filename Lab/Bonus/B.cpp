#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=2005;
const ll mod=998244353;

ll fac[N],facn[N];

inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}

inline ll bit_length(ll x){
  ll res=0;
  while(x) x>>=1,++res;
  return res;
}

inline ll comb(ll x,ll y){
  return fac[x]*facn[y]%mod*facn[x-y]%mod;
}

inline ll solve(int n){
  if(n<=1) return 1;
  ll h=bit_length(n+1)-2;
  ll b=(1<<h)-1;
  ll r=n-1-(b<<1);
  ll r1=r-(r/(b+1))*(r-b-1);
  ll r2=r-r1;
  return comb(n-1,b+r1)*solve(b+r1)%mod*solve(b+r2)%mod;
}

signed main(){
  IOS
  int n;
  fac[0]=facn[0]=1;
  for(int i=1;i<=2000;++i)
    fac[i]=fac[i-1]*i%mod;
  facn[2000]=q_Pow(fac[2000],mod-2,mod);
  for(int i=1999;i>=0;--i)
    facn[i]=facn[i+1]*(i+1)%mod;
  cin>>n;
  cout<<solve(n);
  return 0;
}