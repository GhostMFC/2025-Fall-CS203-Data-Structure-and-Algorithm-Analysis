#include <iostream>
#include <string>
#include <cstring>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1005;

char s[N];

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>s+1;
    int n=1;
    while(s[n+1]) ++n;
    cout<<(n+1)*n/2<<'\n';
  }
  return 0;
}