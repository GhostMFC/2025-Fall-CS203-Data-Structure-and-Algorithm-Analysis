#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,len,init;
struct Node{
  int x;
  Node *l,*r;
}*q[N<<1];

inline Node *CreateNode(int x){
  Node *newnode=new Node;
  newnode->x=x;
  newnode->l=newnode->r=nullptr;
  return newnode;
}

inline void InsertNode(Node **x,Node **tail){
  Node *prev=(*tail)->l;
  prev->r=*x,(*x)->l=prev;
  (*tail)->l=*x,(*x)->r=*tail;
}

inline void DeleteNode(Node **x){
  Node *prev=(*x)->l,*next=(*x)->r;
  (*x)->x=-1;
  prev->r=next,next->l=prev;
}

signed main(){
  // freopen("F.in","r",stdin);
  // freopen("F.txt","w",stdout);
  IOS
  int T;
  cin>>T;
  Node *head=CreateNode(-1),*tail=CreateNode(1e9);
  head->r=tail,tail->l=head;
  while(T--){
    cin>>n;
    while(tail->l!=head){
      Node *todel=tail->l;
      DeleteNode(&todel);
    }
    for(int i=1;i<=n;++i){
      int x;
      cin>>x;
      Node *newnode=CreateNode(x);
      InsertNode(&newnode,&tail);
    }
    init=len=0;
    Node *pos=head->r;
    while(pos!=tail){
      if(pos->x>pos->r->x){
        q[++len]=pos;
        pos=pos->r;
        while(pos->x>pos->r->x)
          pos=pos->r;
      } pos=pos->r;
    }
    while(init<len){
      pos=q[++init];
      // cout<<pos->x<<'\n';
      if(pos->x==-1) continue;
      if(pos->x<=pos->r->x) continue;
      while(pos->x>pos->r->x){
        Node *todel=pos;
        pos=pos->r;
        DeleteNode(&todel);
      }
      Node *l=pos->l,*r=pos->r;
      DeleteNode(&pos);
      if(l->x>r->x) q[++len]=l;
      // pos=head->r;
      // while(pos!=tail) cout<<pos->x<<' ',pos=pos->r;
      // cout<<'\n';
    }
    pos=head->r;
    while(pos!=tail) cout<<pos->x<<' ',pos=pos->r;
    cout<<'\n';
  }
  return 0;
}
/*
1
9
93831 88951 955 56042 77070 6004173 54673 64526 88986

56042 88986
---
1
30
24609 99841 32665 83281 43932 88436 98235 91569 57040 28396
25122 28097 559 94397 59618 6061 82113 77096 32764 34801
9675 83552 19831 81119 10975 19290 69231 43666 16721 20466 

*/