#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int n,m;
struct Node{ int num; Node *l,*r;};
Node *mp[N];

inline Node *CreateNode(int num){
  Node *newnode=new Node;
  newnode->num=num;
  newnode->l=newnode->r=nullptr;
  return newnode;
}

inline void InsertNode(int num,Node **tail){
  Node *newnode=new Node;
  Node *prev=(*tail)->l;
  newnode->num=num,newnode->r=*tail,newnode->l=prev;
  prev->r=newnode,(*tail)->l=newnode;
  mp[num]=newnode;
}

signed main(){
  IOS
  int T;
  cin>>T;
  Node *head=CreateNode(0),*tail=CreateNode(1);
  head->r=tail,tail->l=head;
  while(T--){
    cin>>n>>m;
    while(tail->l!=head){
      Node *todel=tail->l;
      tail->l=tail->l->l;
      delete todel;
    } head->r=tail;
    for(int i=1;i<=n;++i){
      int x;
      cin>>x;
      InsertNode(x+2,&tail);
    }
    // Node *pos=head->r;
    // while(pos!=tail) cout<<pos->num<<' ',pos=pos->r;
    // cout<<'\n';
    
    while(m--){
      int l1,r1,l2,r2;
      cin>>l1>>r1>>l2>>r2;
      ++l1,++r1,++l2,++r2;
      ++l1,++r1,++l2,++r2;//from 2 to n+1;
      Node *nr1=mp[r1],*nl1=mp[l1],*nr2=mp[r2],*nl2=mp[l2];
      if(nr1->r==nl2){
        nl2->l=nl1->l;
        nl1->l=nr2;
        nr1->r=nr2->r;
        nr2->r=nl1;
        (nl2->l)->r=nl2;
        (nr1->r)->l=nr1;
      } else if(nr2->r==nl1){
        nl1->l=nl2->l;
        nl2->l=nr1;
        nr2->r=nr1->r;
        nr1->r=nl2;
        (nl1->l)->r=nl1;
        (nr2->r)->l=nr2;
      } else{
        (nl1->l)->r=nl2;
        (nl2->l)->r=nl1;
        (nr1->r)->l=nr2;
        (nr2->r)->l=nr1;
        swap(nl1->l,nl2->l);
        swap(nr1->r,nr2->r);
      }
      // Node *pos=head->r;
      // while(pos!=tail) cout<<pos->num<<' ',pos=pos->r;
      // cout<<'\n';
    }
    Node *pos=head->r;
    while(pos!=tail) cout<<pos->num-2<<' ',pos=pos->r;
    cout<<'\n';
  }

  return 0;
}