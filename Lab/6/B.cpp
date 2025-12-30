#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1000010;

char s[N];
int nxt[N];

signed main(){
  IOS
  cin>>s+1;
  int len=1;
  while(s[len+1]) ++len;
  nxt[1]=0;
  int k=0;
  for(int i=2;i<=len;++i){
    while(k&&s[k+1]!=s[i])
      k=nxt[k];
    if(s[k+1]==s[i])
      nxt[i]=++k;  
  }
  for(int i=1;i<=len;++i)
    cout<<nxt[i]<<'\n';
  return 0;
}