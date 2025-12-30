#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,p,q,a[N],b[N],ans[N];

signed main(){
  IOS
  cin>>n>>p>>q;
  for(int i=1;i<=p;++i) cin>>a[i];
  for(int j=1;j<=q;++j) cin>>b[j];
  int ha=1,hb=1,time=0;
  while(ha<=p||hb<=q){
    ++time;
    while(ha<=p&&ans[a[ha]]) ++ha;
    while(hb<=q&&ans[b[hb]]) ++hb;
    ans[a[ha]]=ans[b[hb]]=time;
  }
  for(int i=1;i<=n;++i)
    cout<<ans[i]<<' ';

  return 0;
}