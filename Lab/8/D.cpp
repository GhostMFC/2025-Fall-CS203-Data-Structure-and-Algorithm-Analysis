#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct Node{
  int x,num;
  Node *l,*r;
  bool operator<(const Node& o) const{
    if(x!=o.x) return x<o.x;
    return num<o.num;
  }
};

inline Node *CreateNode(int x,int num){
  Node *newnode=new Node;
  newnode->x=x,newnode->num=num;
  newnode->l=newnode->r=nullptr;
  return newnode;
}

inline void InsertNode(Node **x,Node **tail){//left insert
  Node *prev=(*tail)->l;
  prev->r=*x,(*x)->l=prev;
  (*tail)->l=*x,(*x)->r=*tail;
}

inline void DeleteNode(Node **x){
  Node *prev=(*x)->l,*next=(*x)->r;
  (*x)->num=-1;
  // delete *x; //caveat: may lead to segmentation fault?
  prev->r=next,next->l=prev;
}  

const int N=500010;

Node *p[N];
int n,a[N],len;

inline void Push(Node *newNode){
  p[++len]=newNode;
  int pos=len;
  while(pos>1&&*p[pos]<*p[pos/2]){
    swap(p[pos],p[pos/2]);
    pos>>=1;
  }  
}  

inline Node* Pop(){
  Node* res=p[1];
  swap(p[1],p[len]);
  --len; int pos=1;
  while((pos<<1)<=len){
    int child=(pos<<1);
    if(child+1<=len&&!(*p[child]<*p[child|1]))
    child=child|1;
    if(*p[pos]<*p[child]) break;
    swap(p[pos],p[child]);
    pos=child;
  } return res;  
}    

signed main(){
  IOS
  cin>>n;
  Node *head=CreateNode(-1,-1),*rear=CreateNode(-1,-1);
  head->r=rear,rear->l=head;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    Node *newNode=CreateNode(a[i],i);
    InsertNode(&newNode,&rear);
    Push(newNode);
  }
  for(int i=1;i<n;++i){
    Node* mn=Pop();
    while(mn->num==-1) mn=Pop();
    int val,num=mn->num;
    if(mn->r==rear){
      val=mn->l->x;
      DeleteNode(&(mn->l));
    } else if(mn->l==head){
      val=mn->r->x;
      DeleteNode(&(mn->r));
    } else{
      int p=mn->l->x,q=mn->r->x;
      p=(p^(mn->x))+1,q=(q^(mn->x))+1;
      if(p>=q){
        val=mn->l->x;
        DeleteNode(&(mn->l));
      } else{
        val=mn->r->x;
        DeleteNode(&(mn->r));
      }
    }
    val=(val^(mn->x))+1;
    Node *newNode=CreateNode(val,num);
    InsertNode(&newNode,&mn);
    DeleteNode(&mn);
    Push(newNode);
  }
  Node *ans=Pop();
  while(ans->num==-1) ans=Pop();
  cout<<(ans->x)<<'\n';

  return 0;
}