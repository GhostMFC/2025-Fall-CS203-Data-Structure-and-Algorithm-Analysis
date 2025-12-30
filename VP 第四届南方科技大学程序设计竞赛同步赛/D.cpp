#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=55;

int num;
char s[N][1005];
struct Node{
  int nxt[26],cnt;
}node[N*1005];

signed main(){
  IOS
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;++i){
    int pos=0;
    for(int j=1;j<=m;++j){
      char ch;
      cin>>ch; s[i][j]=ch;
      if(node[pos].nxt[ch-'a'])
        pos=node[pos].nxt[ch-'a'];
      else
        pos=node[pos].nxt[ch-'a']=++num;
      node[pos].cnt++;
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i){
    int pos=0;
    for(int j=1;j<=m;++j){
      char ch=s[i][j];
      pos=node[pos].nxt[ch-'a'];
      if(node[pos].cnt==1){
        ans+=j;
        break;
      }
    }
  }
  cout<<ans<<'\n';

  return 0;
}