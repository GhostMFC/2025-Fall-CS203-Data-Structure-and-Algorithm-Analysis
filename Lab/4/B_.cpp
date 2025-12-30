#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n;
struct Node{ char ch; Node *l,*r;};

inline Node *del(Node **x){
  Node *pre=(*x)->l,*nxt=(*x)->r;
  pre->r=nxt,nxt->l=pre;
  delete *x;
  return nxt;
}

inline Node *CreateNode(char ch){
  Node *newnode=new Node;
  newnode->ch=ch,newnode->l=nullptr,newnode->r=nullptr;
  return newnode;
}

inline void ins(Node **x,Node **newnode){
  Node *pre=(*x)->l;
  pre->r=*newnode,(*x)->l=*newnode;
  (*newnode)->l=pre,(*newnode)->r=*x;
}

signed main(){
  IOS
  int T;
  cin>>T;

  Node *head=CreateNode(0),*tail=CreateNode(0);
  head->r=tail,tail->l=head;
  while(T--){
    cin>>n;
    // if(n==20){
    //   while(n&&(tail->l)!=head){
    //     cout<<tail->ch<<' ';
    //     --n;
    //   } return 0;
    // }
    while((tail->l)!=head){
      Node *todel=tail->l;
      del(&todel);
    }
    bool tag=false;
    Node *pos=tail;
    while(n--){
      char ch;
      cin>>ch;
      if(ch=='r') tag=true;
      else if(ch=='I'){
        pos=head->r;
      } else if(ch=='H'){
        if(pos->l!=head) pos=pos->l;
      } else if(ch=='L'){
        if(pos!=tail) pos=pos->r;
      } else if(ch=='x'){
        if(pos!=tail) pos=del(&pos);
      } else{
        if(pos==tail){
          Node *newnode=CreateNode(ch);
          ins(&tail,&newnode);
          if(tag) pos=tail->l;
        } else if(tag){
          pos->ch=ch;
        } else{
          Node *newnode=CreateNode(ch);
          ins(&pos,&newnode);
        }
        tag=false;
      }
    }
    pos=head->r;
    while(pos!=tail) cout<<pos->ch,pos=pos->r;
    cout<<'\n';
  }
  return 0;
}
/*
1
10
r60xxxxHx4

*/