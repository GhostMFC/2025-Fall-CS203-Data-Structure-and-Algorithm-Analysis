#include <iostream>
#include <string>
#include <cstring>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=500010;

int tot[N];

signed main(){
  IOS
  string t;
  cin>>t;
  int len=t.size();
  for(int i=1;i<=len;++i)
    tot[i]+=tot[i-1]+(t[i-1]=='b');

  int ans=1e9;
  for(int i=0;i<=len;++i)
    ans=min(ans,i-tot[i]+tot[len]-tot[i]);
  cout<<ans<<'\n';
  return 0;
}