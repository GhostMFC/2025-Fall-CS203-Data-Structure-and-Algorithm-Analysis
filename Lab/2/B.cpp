#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,a[N];

signed main(){
  IOS
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  int q;
  cin>>q;
  while(q--){
    int x;
    cin>>x;
    int l=1,r=n;
    while(l<r){
      int mid=(l+r)>>1;
      if(a[mid]>=x) r=mid;
      else l=mid+1;
    }
    cout<<(a[l]==x?"YES":"NO")<<'\n';
  }

  return 0;
}