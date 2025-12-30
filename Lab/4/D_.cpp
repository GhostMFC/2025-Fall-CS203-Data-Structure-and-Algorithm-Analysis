#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=300010;

int n,ans[N],len;
struct Nd{ int x,num;}nd[N],tmp[N];
struct Node{
  int x,p;
  Node *l,*r;
}*mp[N];

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid); merge(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(i<=mid&&j<=r){
    if(nd[i].x<=nd[j].x) tmp[k++]=nd[i++];
    else tmp[k++]=nd[j++];
  }
  while(i<=mid) tmp[k++]=nd[i++];
  while(j<=r) tmp[k++]=nd[j++];
  for(int p=l;p<=r;p++) nd[p]=tmp[p];
}

inline Node* CreateNode(int x,int p){
  Node *newnode=new Node;
  newnode->x=x,newnode->p=p;
  newnode->l=newnode->r=nullptr;
  return newnode;
}

inline void InsertNode(Node **newnode,Node **x){
  Node *prev=(*x)->l;
  (*newnode)->l=prev,(*x)->l=(*newnode);
  prev->r=(*newnode),(*newnode)->r=*x;
}

inline Node* DeleteNode(Node **x){
  Node *prev=(*x)->l,*next=(*x)->r;
  delete(*x);
  prev->r=next,next->l=prev;
  return next;
}

signed main(){
  IOS
  int T;
  cin>>T;
  Node *head=CreateNode(0,0),*tail=CreateNode(-1,300005);
  head->r=tail,tail->l=head;
  while(T--){
    cin>>n;
    while(tail->l!=head){
      Node *todel=tail->l;
      DeleteNode(&todel);
    }
    for(int i=1;i<=n;++i) cin>>nd[i].x,nd[i].num=i;
    merge(1,n);
    for(int i=1;i<=n;++i){
      Node *newnode=CreateNode(nd[i].x,i);
      mp[nd[i].num]=newnode;
      InsertNode(&newnode,&tail);
    }

    if(n%2==0) DeleteNode(&mp[n--]);
    Node *pos=head->r;
    for(int i=3;i<=n;i+=2) pos=pos->r;
    len=0;
    ans[++len]=pos->x;
    for(int i=n;i>1;i-=2){
      Node *p1=mp[i],*p2=mp[i-1];
      // cout<<p1->x<<' '<<p2->x<<'\n';
      if(p1->p>pos->p&&p2->p>pos->p) pos=pos->l;
      else if(p1->p<pos->p&&p2->p<pos->p) pos=pos->r;
      else if((p1->p>pos->p&&p2->p<pos->p)||(p1->p<pos->p&&p2->p>pos->p)) void();
      else{//mid will be del
        if(p1->p>pos->p||p2->p>pos->p) pos=pos->l;
        else pos=pos->r;
      }
      DeleteNode(&p1),DeleteNode(&p2);
      ans[++len]=pos->x;
    }
    for(int i=len;i;--i) cout<<ans[i]<<' ';
    cout<<'\n';
  }
  return 0;
}
/*
1
7
5 2 3 8 1 7 0

5 3 3 3
---
1
3
0 1 1

0 1
*/