#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,len;
struct Node{
  char ch;
  int l,r;
}node[N];

inline void del(int x){
  node[node[x].l].r=node[x].r;
  node[node[x].r].l=node[x].l;
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n; len=1;
    node[0].r=1,node[1].r=1,node[1].l=0;
    int pos=0; bool tag=false;
    while(n--){
      // int pos1=node[0].r;
      // while(pos1!=1) cout<<node[pos1].ch,pos1=node[pos1].r;
      // cout<<'\n';
      char ch;
      cin>>ch;
      if(ch=='r') tag=true;
      else if(ch=='I'){
        pos=node[0].r;
      } else if(ch=='H'){
        if(node[pos].l) pos=node[pos].l;
      } else if(ch=='L'){
        pos=node[pos].r;
      } else if(ch=='x'){
        if(pos>1) del(pos);
        pos=node[pos].r;
      } else{
        if(!pos) pos=1;//no length
        if(pos==1){
          node[++len].ch=ch;
          node[len].l=node[1].l;
          node[node[1].l].r=len;
          node[len].r=1,node[1].l=len;
          if(tag) pos=len;
        } else if(tag){
          node[pos].ch=ch;
        } else{
          node[++len].ch=ch;
          node[len].l=node[pos].l,node[len].r=pos;
          node[node[len].l].r=len,node[pos].l=len;
        }
        tag=false;
      }
    }
    pos=node[0].r;
    while(pos!=1) cout<<node[pos].ch,pos=node[pos].r;
    cout<<'\n';
  }
  return 0;
}
/*
1
10
r60xxxxHx4

*/