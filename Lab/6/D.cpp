#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=200010;

char s[N];
int nxt[N];

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>s+1;
    int len=1;
    while(s[len+1]) ++len;
    int pos=0; nxt[1]=0;
    for(int i=2;i<=len;++i){
      while(pos&&s[pos+1]!=s[i]) pos=nxt[pos];
      if(s[pos+1]==s[i]) nxt[i]=++pos;
      else nxt[i]=0;
    }
    int l=len-nxt[len];
    if(len%l==0){
      if(l!=len) cout<<0<<'\n';
      else cout<<len<<'\n';
    } else cout<<l-len%l<<'\n';
  }
  return 0;
}