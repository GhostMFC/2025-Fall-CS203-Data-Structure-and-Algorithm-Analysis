#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1000010;

ll n,a[N],c;

signed main(){
  IOS
  cin>>n>>c;
  for(int i=1;i<=n;++i)
    cin>>a[i];
  sort(a+1,a+1+n);

  for(int i=1;i<=n;++i){
    if(a[i]<c) c+=a[i];
    else break;
  }
  cout<<c<<'\n';

  return 0;
}