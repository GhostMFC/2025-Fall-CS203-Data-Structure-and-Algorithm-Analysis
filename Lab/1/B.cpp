#include <iostream>
#include <string>
using namespace std;

const int N=100010;

bool tag[N];

signed main(){
  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;++i){
    int x;
    cin>>x;
    tag[x]=true;
  }
  int T;
  cin>>T;
  while(T--){
    int x;
    cin>>x;
    cout<<(tag[x]?"yes":"no")<<'\n';
  }
  
  return 0;
}