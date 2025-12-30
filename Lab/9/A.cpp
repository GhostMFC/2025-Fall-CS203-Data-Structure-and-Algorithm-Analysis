#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=505;

int n,m;
bool mp[N][N];

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        mp[i][j]=false;
    while(m--){
      int x,y;
      cin>>x>>y;
      mp[x][y]=1;
    }
    for(int i=1;i<=n;++i){
      for(int j=1;j<=n;++j)
        cout<<mp[i][j]<<' ';
      cout<<'\n';
    }
  }

  return 0;
}