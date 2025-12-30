#pragma GCC optimize(2)
#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,len;
struct Node{
  Node* next;
  Node* prev;
  int co,ex;
};

inline Node* CreateNode(int co,int ex){
  Node* newnode=new Node;
  newnode->co=co,newnode->ex=ex;
  newnode->next=nullptr;
  newnode->prev=nullptr;
  return newnode;
}

inline void insertNode(Node **tail,Node **node){
  // Node *prevnode=(*tail)->prev;
  (*node)->next=*tail;
  (*node)->prev=((*tail)->prev);
  ((*tail)->prev)->next=*node;
  (*tail)->prev=*node;
}

signed main(){
  IOS
  cin>>n>>m;
  Node *tailA=CreateNode(-1,-1),*tailB=CreateNode(-1,-1);
  Node *headA=CreateNode(-1,-1),*headB=CreateNode(-1,-1);
  headA->next=tailA,headB->next=tailB;
  tailA->prev=headA,tailB->prev=headB;
  for(int i=1;i<=n;++i){
    int ex,co;
    cin>>co>>ex;
    Node *newnode=CreateNode(co,ex);
    insertNode(&tailA,&newnode);
  }
  for(int i=1;i<=m;++i){
    int ex,co;
    cin>>co>>ex;
    Node* newnode=CreateNode(co,ex);
    insertNode(&tailB,&newnode);
  }
  // Node *pos=headA->next;
  // while(pos!=tailA){
  //   cout<<pos->co<<' '<<pos->ex<<'\n';
  //   pos=pos->next;
  // } return 0;
  Node *head=CreateNode(-1,-1);
  Node *tail=CreateNode(-1,-1);
  head->next=tail,tail->prev=head;
  Node *pA=headA->next,*pB=headB->next;
  while(pA!=tailA||pB!=tailB){
    int co=0,ex=0;
    if(pA==tailA){
      co=pB->co,ex=pB->ex;
      pB=pB->next;
    } else if(pB==tailB){
      co=pA->co,ex=pA->ex;
      pA=pA->next;
    } else{
      ex=max(pA->ex,pB->ex);
      if(pA->ex==ex){
        co+=pA->co;
        pA=pA->next;
      }
      if(pB->ex==ex){
        co+=pB->co;
        pB=pB->next;
      }
    }
    ++len;
    Node *newnode=CreateNode(co,ex);
    insertNode(&tail,&newnode);
  }

  cout<<len<<'\n';
  head=head->next;
  while(head!=tail){
    cout<<head->co<<' '<<head->ex<<'\n';
    head=head->next;
  }

  return 0;
}