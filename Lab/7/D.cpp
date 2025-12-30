#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1005;

int n,l[N],bst[N],len;

inline void insert(int x){
  bst[++len]=x; int pos=len;
  while(pos>1&&bst[pos>>1]>bst[pos]) swap(bst[pos>>1],bst[pos]),pos>>=1;
}
inline int pop_top(){
  swap(bst[1],bst[len]);
  --len; int pos=1;
  while((pos<<1)<=len){
    int child=pos<<1;
    if(child+1<=len&&bst[child+1]<bst[child]) ++child;//choose smaller one
    if(bst[pos]<=bst[child]) break;
    swap(bst[pos],bst[child]); pos=child;
  } return bst[len+1];
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n; len=0;
    for(int i=1;i<=n;++i) cin>>l[i],insert(l[i]);
    int ans=0;
    while(len>1){
      int sum=pop_top()+pop_top();
      ans+=sum; insert(sum);
      // cout<<sum<<'\n';
    } cout<<ans<<'\n';
  }
  return 0;
}