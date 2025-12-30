#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

char s[N];
int len,nxt[N];

signed main(){
  IOS
  cin>>s+1;
  len=1;
  while(s[len+1]) ++len;
  int k=0;
  for(int i=2;i<=len;++i){
    while(k&&s[k+1]!=s[i]) k=nxt[k];
    if(s[k+1]==s[i]) nxt[i]=++k;
  }
  for(int i=1;i<=len;++i){
    for(int j=0;j<26;++j){
      int p=i-1;
      while(p&&s[p+1]!=char('a'+j))
        p=nxt[p];
      if(s[p+1]==char('a'+j))
        ++p;
      cout<<p<<' ';
    }
    cout<<'\n';
  }

  return 0;
}