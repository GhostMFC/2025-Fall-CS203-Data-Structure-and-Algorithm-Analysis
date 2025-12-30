#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=2000010;

int n;
struct Nd{int x,num;}nd[N],tmp[N];
struct Node{
  int x,num;
  Node *l,*r;
}*mp[N];

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid),merge(mid+1,r);
  int i=l,j=mid+1,idx=l;
  while(i<=mid&&j<=r){
    if(nd[i].x<=nd[j].x) tmp[idx++]=nd[i++];
    else tmp[idx++]=nd[j++];
  }
  while(i<=mid) tmp[idx++]=nd[i++];
  while(j<=r) tmp[idx++]=nd[j++];
  for(int k=l;k<=r;++k) nd[k]=tmp[k];
}

inline Node *CreateNode(int x,int num){
  Node *newnode=new Node;
  newnode->x=x,newnode->num=num;
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
  delete *x;
  prev->r=next,next->l=prev;
}

inline void solve(){
  Node *head=CreateNode(-1e9,0),*tail=CreateNode(-1e9,n+1);
  head->r=tail,tail->l=head;
  for(int i=1;i<=n;++i){
    Node *newnode=CreateNode(nd[i].x,nd[i].num);
    InsertNode(&newnode,&tail);
    mp[nd[i].num]=newnode;
  }

  for(int i=1;i<n;++i){
    Node *pos=mp[i];
    int res1=abs((pos->l)->x-pos->x),
       res2=abs((pos->r)->x-pos->x);
    cout<<min(res1,res2)<<' ';
    DeleteNode(&pos);
  }
}

signed main(){
  IOS
  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>nd[i].x,nd[i].num=i;
  merge(1,n);
  solve();
  return 0;
}