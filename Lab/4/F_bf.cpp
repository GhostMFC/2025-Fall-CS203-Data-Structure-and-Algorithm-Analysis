#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,a[N],l[N],r[N];

inline void del(int x){
  l[r[x]]=l[x],r[l[x]]=r[x];
}

signed main(){
  freopen("F.in","r",stdin);
  freopen("bf.txt","w",stdout);
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n;
    l[n+1]=n,r[0]=1,a[n+1]=1e9;
    for(int i=1;i<=n;++i) cin>>a[i],l[i]=i-1,r[i]=i+1;
    bool tag=true;
    while(tag){
      tag=false;
      queue<pair<int,int>> q;
      int left=r[0],right;
      while(left<=n){
        right=r[left];
        if(right>n) break;
        if(a[right]<a[left]){
          while(a[r[right]]<a[right])
            right=r[right];
          q.push({left,right});
          left=right;
        } left=r[left];
      }

      while(q.size()){
        pair<int,int> v=q.front(); q.pop();
        left=v.first,right=v.second;
        // cout<<left<<' '<<right<<'\n';
        del(left);
        while(left!=right){
          left=r[left];
          del(left);
        } tag=true;
      }
    }
    int pos=r[0];
    while(pos<=n) cout<<a[pos]<<' ',pos=r[pos];
    cout<<'\n';
  }
}