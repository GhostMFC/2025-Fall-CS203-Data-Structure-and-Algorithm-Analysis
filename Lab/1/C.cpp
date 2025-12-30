#include <iostream>
#include <string>
using namespace std;

const int N=15;

int mp[100];

struct Node{
  string s;
  int val;
}node[N];

signed main(){
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  //E>S>W>N>B>F>Z
  mp['Z']=1,mp['F']=2,mp['B']=3,mp['N']=4,mp['W']=5,mp['S']=6,mp['E']=7,mp['Y']=10,mp['T']=100;
  while(T--){
    for(int i=1;i<=13;++i){
      cin>>node[i].s;
      node[i].val=mp[node[i].s[0]]+(node[i].s.length()==2?(node[i].s[0]=='W'?995:0)+'9'-node[i].s[1]:0);
    }
    // for(int i=1;i<=13;++i) cout<<node[i].val<<' '; cout<<'\n';

    for(int i=1;i<=13;++i)
      for(int j=i+1;j<=13;++j)
        if(node[i].val<node[j].val)
          swap(node[i],node[j]);

    for(int i=1;i<=13;++i) cout<<node[i].s<<' ';
    cout<<'\n';
  }
  
  return 0;
}