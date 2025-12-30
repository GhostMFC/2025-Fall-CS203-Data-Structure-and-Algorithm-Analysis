#include <iostream>
using namespace std;

const int N=1005;

int n,T;
int a[N],b[N];

signed main(){
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  cin>>T;
  for(int i=1;i<=T;++i) cin>>b[i];
  for(int i=1;i<=T;++i){
    bool ok=false;
    for(int j=1;j<=n;++j)
      if(b[i]==a[j]){
        ok=true;
        break;
      }
    cout<<(ok?"yes":"no")<<'\n';
  }
  
  return 0;
}