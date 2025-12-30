#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

class AVLTree{
private:
  struct AVLNode{
    int val,height,cnt,size;
    AVLNode *lch,*rch;
    AVLNode(int v):
      val(v),lch(nullptr),rch(nullptr),height(1),cnt(1),size(1){}
  };
  AVLNode* root;
  int getSize(AVLNode* node){return node?node->size:0;}
  int getHeight(AVLNode* node){return node?node->height:0;}
  int getBalance(AVLNode* node)//expected to be in range [-1,1]
  {return node?getHeight(node->lch)-getHeight(node->rch):0;}
  void update(AVLNode* node){
    if(node){
      node->height=1+max(getHeight(node->lch),getHeight(node->rch));
      node->size=node->cnt+getSize(node->lch)+getSize(node->rch);
    }
  }
  
  AVLNode* Zig(AVLNode* x){//left rotate->heights right-left==2
    AVLNode *y=x->rch,*T2=y->lch;
    y->lch=x,x->rch=T2;
    update(x); update(y);
    return y;//new root
  }
  AVLNode* Zag(AVLNode* y){//right rotate
    AVLNode *x=y->lch,*T2=x->rch;
    x->rch=y,y->lch=T2;
    update(y); update(x);
    return x;
  }

  AVLNode* insert(AVLNode* node,int val){
    if(!node) return new AVLNode(val);
    if(val<node->val) node->lch=insert(node->lch,val);
    else if(val>node->val) node->rch=insert(node->rch,val);
    else{++node->cnt; update(node); return node;}
    update(node);
    int balance=getBalance(node);
    if(balance>1&&val<node->lch->val)//imply that val is in l-tree
      return Zag(node);//LL
    if(balance<-1&&val>node->rch->val)
      return Zig(node);//RR
    if(balance>1&&val>node->lch->val){
      node->lch=Zig(node->lch);
      return Zag(node);//LR
    }
    if(balance<-1&&val<node->rch->val){
      node->rch=Zag(node->rch);
      return Zig(node);
    }
    return node;
  }

  AVLNode* minValueNode(AVLNode* node){
    AVLNode* current=node;
    while(current&&current->lch) current=current->lch;
    return current;
  }

  AVLNode* remove(AVLNode* node,int val){
    if(!node) return node;
    if(val<node->val) node->lch=remove(node->lch,val);
    else if(val>node->val) node->rch=remove(node->rch,val);
    else{//find the point
      if(node->cnt>1){--node->cnt; update(node); return node;}
      if(!node->lch||!node->rch){
        AVLNode* tmp=node->lch?node->lch:node->rch;
        if(!tmp){delete node; node=nullptr;}//leaf
        else{*node=*tmp; delete tmp;}//copy the content
      } else{
        AVLNode* tmp=minValueNode(node->rch);
        node->val=tmp->val; node->cnt=tmp->cnt;//!!!copy the information!!!
        tmp->cnt=1;//swap tmp and deleted node
        node->rch=remove(node->rch,tmp->val);
      }
    }
    if(!node) return node;
    update(node);
    int balance=getBalance(node);
    if(balance>1&&getBalance(node->lch)>=0)
      return Zag(node);//LL
    if(balance<-1&&getBalance(node->rch)<=0)
      return Zig(node);//RR
    if(balance>1&&getBalance(node->lch)<0){
      node->lch=Zig(node->lch);
      return Zag(node);//LR
    }
    if(balance<-1&&getBalance(node->rch)>0){
      node->rch=Zag(node->rch);
      return Zig(node);//RL
    }
    return node;
  }
  void delTree(AVLNode* node)
  {if(node){delTree(node->lch);delTree(node->rch);delete node;}}

  int getKth(AVLNode* node, int k){//find the k-th smallest
    if(!node) return -1;
    int lsize=getSize(node->lch);
    if(k<=lsize) return getKth(node->lch,k);
    if(k<=lsize+node->cnt) return node->val;
    return getKth(node->rch,k-lsize-node->cnt);
  }
  void getPredecessor(AVLNode* node, int val, int& ans){
    if(!node) return;
    if(node->val<val)
    { ans=node->val; getPredecessor(node->rch,val,ans);}
    else getPredecessor(node->lch,val,ans);
  }
  void getSuccessor(AVLNode* node,int val,int& ans){
    if(!node) return;
    if(node->val>val)
    { ans=node->val; getSuccessor(node->lch,val,ans);}
    else getSuccessor(node->rch,val,ans);
  }
  int getRank(AVLNode* node,int val){
    if(!node) return 0;
    if(val==node->val) return getSize(node->lch);
    if(val<node->val) return getRank(node->lch,val);
    return getSize(node->lch)+node->cnt+getRank(node->rch,val);
  }

public:
  AVLTree(): root(nullptr){}
  ~AVLTree(){ clear();}
  void clear(){ delTree(root); root=nullptr;}
  void insert(int val){ root=insert(root,val);}
  void remove(int val){ root=remove(root,val);}
  int getHeight(){ return getHeight(root);}
  bool isEmpty(){ return root==nullptr;}
  int getSize(){ return getSize(root);}
  int getKth(int k){
    if(k>getSize(root)||k<=0) return -2147483647;
    return getKth(root,k);
  }
  int getPredecessor(int val){
    int ans=-2147483647;
    getPredecessor(root,val,ans);
    return ans;
  }
  int getSuccessor(int val){
    int ans=2147483647;
    getSuccessor(root,val,ans);
    return ans;
  }
  int getRank(int val){ return getRank(root,val);}
};

const int N=100010;

int n;

signed main(){
  IOS
  AVLTree avt;
  cin>>n;
  while(n--){
    int opt,x;
    cin>>opt>>x;
    if(opt==1) avt.insert(x);
    else if(opt==2) avt.remove(x);
    else if(opt==3) cout<<avt.getRank(x)+1<<'\n';
    else if(opt==4) cout<<avt.getKth(x)<<'\n';
    else if(opt==5) cout<<avt.getPredecessor(x)<<'\n';
    else cout<<avt.getSuccessor(x)<<'\n';
  }
  return 0;
}