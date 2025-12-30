#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=300010;

int n,a[N],len;

inline void Push(int x){
  int res=0;
  a[++len]=x; int pos=len;
  while(pos>1&&a[pos/2]<a[pos]){
    swap(a[pos/2],a[pos]);
    pos>>=1; ++res;
  } cout<<res<<' ';
}

signed main(){
  IOS
  cin>>n;
  for(int i=1;i<=n;++i){
    int x;
    cin>>x;
    Push(x);
  }
  return 0;
}