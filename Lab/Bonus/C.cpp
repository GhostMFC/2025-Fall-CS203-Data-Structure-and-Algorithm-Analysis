#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1005;

ull a[N];
bool in[16][16];

signed main(){
  IOS
  int n,k,l=1,r=0;
  cin>>n>>k;
  while(n--){
    ull x=0;
    for(int i=0;i<16;++i)
      for(int j=0;j<16;++j){
        cin>>in[i][j];
        x=(x<<1)+in[i][j];
      }
    bool tag=false;
    for(int i=l;i<=r;++i){
      if(a[i]==x){
        for(int j=i;j<r;++j)
          a[j]=a[j+1];
        tag=true; --r;
        break;
      }
    }
    if(tag) a[++r]=x;
    else if(r-l+1<k) a[++r]=x;
    else ++l,a[++r]=x;
    cout<<(tag?"hit":"miss")<<'\n';
  }
  return 0;
}