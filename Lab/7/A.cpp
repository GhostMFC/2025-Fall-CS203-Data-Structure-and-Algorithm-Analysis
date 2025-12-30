#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1000010;

int _in[N];

signed main(){
  IOS
  int n;
  cin>>n;
  for(int i=1,u,v;i<n;++i){
    cin>>u>>v;
    _in[u]++,_in[v]++;
  }
  for(int i=2;i<=n;++i)
    if(_in[i]==1)
      cout<<i<<' ';
  cout<<'\n';

  return 0;
}