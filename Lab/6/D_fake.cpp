#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=200010,hash0=1e9+7,hash1=1e9+9;

int len;
char s[N];
ll _26[N][2],suf[N][2];

signed main(){
  IOS
  int T;
  cin>>T;
  _26[1][0]=_26[1][1]=26;
  for(int i=2;i<=200000;++i)
    _26[i][0]=_26[i-1][0]*26%hash0,_26[i][1]=_26[i-1][1]*26%hash1;
  while(T--){
    cin>>s+1; len=0;
    for(len=1;s[len];++len){
      suf[len][0]=(suf[len-1][0]*26+s[len])%hash0;
      suf[len][1]=(suf[len-1][1]*26+s[len])%hash1;
    } --len;
    int ans=len;
    for(int i=1;i<len;++i){
      bool tag=true;
      ll hs[2]={suf[i][0]*_26[len-i][0]%hash0,suf[i][1]*_26[len-i][1]%hash1};
      // cout<<i<<": "<<hs[0]<<' '<<hs[1]<<'\n';
      for(int j=i+1;j+i-1<=len;j+=i){//j~j+i-1
        ll hs0=_26[len-i][0]*((suf[j+i-1][0]-suf[j-1][0]*_26[i][0]%hash0)+hash0)%hash0;
        ll hs1=_26[len-i][1]*((suf[j+i-1][1]-suf[j-1][1]*_26[i][1]%hash1)+hash1)%hash1;
        if(hs0!=hs[0]||hs1!=hs[1]) tag=false;
        // cout<<i<<" "<<j<<": "<<hs0<<' '<<hs1<<'\n';
      }
      int res=len%i;
      if(res){
        int l=len-res+1,r=len;
        ll hs0=_26[len-res][0]*((suf[r][0]-suf[l-1][0]*_26[r-l+1][0]%hash0)+hash0)%hash0;
        ll hs1=_26[len-res][1]*((suf[r][1]-suf[l-1][1]*_26[r-l+1][1]%hash1)+hash1)%hash1;
        hs[0]=suf[res][0]*_26[len-res][0]%hash0;
        hs[1]=suf[res][1]*_26[len-res][1]%hash1;
        if(hs0!=hs[0]||hs1!=hs[1]) tag=false;
      } else ans=tag?0:ans;
      if(tag) ans=min(ans,i-res);
    }
    cout<<ans<<'\n';
  }

  return 0;
}