#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

template <typename T> class Deque{
  private:
    struct Node{
      T data;
      Node* next,*prev;
      Node(T val=T(),Node* p=nullptr,Node* n=nullptr):
        data(val),prev(p),next(n){}
    };
    int size;
    Node *head,*tail;
  public:
    Deque():size(0){//Deque with sentinel nodes
      head=new Node(); tail=new Node();
      head->next=tail,tail->prev=head;
    }
    ~Deque(){
      while(!isEmpty()) popFront();
      delete head; delete tail;
    }
    void pushFront(const T& value){
      Node* newNode=new Node(value,head,head->next);
      head->next->prev=newNode; head->next=newNode;
      ++size;
    }
    void pushBack(const T& value){
      Node* newNode=new Node(value,tail->prev,tail);
      tail->prev->next=newNode; tail->prev=newNode;
      ++size;
    }
    T popFront(){
      if(isEmpty()) throw runtime_error("Deque is empty");
      Node* toDelete=head->next;
      T value=toDelete->data;
      head->next=toDelete->next;
      toDelete->next->prev=head;
      delete toDelete; --size;
      return value;
    }
    T popBack(){
      if(isEmpty()) throw runtime_error("Deque is empty");
      Node* toDelete=tail->prev;
      T value=toDelete->data;
      tail->prev=toDelete->prev;
      toDelete->prev->next=tail;
      delete toDelete; --size;
      return value;
    }
    T Front() const{
      if(isEmpty()) throw runtime_error("Deque is empty");
      return head->next->data;
    }
    T Back() const{
      if(isEmpty()) throw runtime_error("Deque is empty");
      return tail->prev->data;
    }
    bool isEmpty() const{ return head->next==tail;}
    int Size() const{ return size;}
    void display() const{
      if(isEmpty()) return cout<<"Deque is empty\n",void();
      Node* current=head->next;
      while(current!=tail){
        cout<<current->data<<" ";
        current=current->next;
      } cout<<'\n';
    }
};

#define int ll

inline void Swap(int &a,int &b)
{ int tmp=a; a=b; b=tmp; return ;}
inline void threeWayQs(int arr[],int l,int r){
  if(l>=r) return ;
  int v=(rand()%(r-l+1)+l);
  Swap(arr[l],arr[v]);
  int pivot=arr[l],it=l,i=l+1,gt=r;
  while(i<=gt){
    if(arr[i]<pivot) Swap(arr[i],arr[it]),++i,++it;//add left bound
    else if(arr[i]>pivot) Swap(arr[i],arr[gt]),--gt;//minus right bound
    else ++i;
  }
  threeWayQs(arr,l,it-1); threeWayQs(arr,gt+1,r);
}

const int N=200010;

int b[N],len;
int n,cnt,head[N],dep[N],f[N],ans[N],mx[N];
struct Node{int p,num;}node[N];
struct Edge{
  int to,nxt;
}edge[N<<1];
inline void Add(int fo,int to){
  edge[++cnt]={to,head[fo]};
  head[fo]=cnt;
}

inline void solve(int ori){//if there is no need to set a value same as root(max) in this subtree
  Deque<int> q,v;
  q.pushBack(ori);
  dep[ori]=1;
  while(!q.isEmpty()){
    int c=q.popFront();
    v.pushBack(c);
    for(int i=head[c];i;i=edge[i].nxt){
      int &to=edge[i].to;
      if(dep[to]) continue;
      dep[to]=dep[c]+1;
      q.pushBack(to);
      f[to]=c;//father
    }
  }
  //then from deepest to top, make leaves the most useful
  while(!v.isEmpty()){
    int c=v.popBack();
    if(!ans[c]) ans[c]=node[c].p;//leaves
    else ans[c]+=max(0ll,node[c].p-mx[c]);
    mx[c]=max(mx[c],node[c].p);
    // if(ori==1) cout<<c<<' '<<ans[c]<<'\n';
    int fa=f[c];
    ans[fa]+=ans[c];
    mx[fa]=max(mx[c],mx[fa]);
    // if(ori==1) cout<<c<<' '<<mx[c]<<'\n';
  }
  // cout<<ori<<' '<<ans[ori]<<' '<<mx[ori]<<'\n';
}

signed main(){
  IOS
  cin>>n;
  for(int i=1,fo,to;i<n;++i){
    cin>>fo>>to;
    Add(fo,to); Add(to,fo);
  }
  int mxp=0,mxpos=1;
  for(int i=1;i<=n;++i){
    cin>>node[i].p,node[i].num=i;
    if(mxp<node[i].p) mxp=node[i].p,mxpos=i;
  }
  dep[mxpos]=-1;
  int tot=0;
  for(int i=head[mxpos];i;i=edge[i].nxt){
    int &to=edge[i].to;
    solve(to);
    b[++len]=mx[to];
    tot+=ans[to];
    // cout<<to<<' '<<ans[to]<<'\n';
  }

  threeWayQs(b,1,len);
  // for(int i=1;i<=len;++i) cout<<b[i]<<' '; cout<<'\n';
  int ans1=1e18,ans2;
  if(len>1) ans1=tot+2*mxp-b[len]-b[len-1];
  ans2=tot+2*mxp-b[len];
  cout<<min(ans1,ans2)<<'\n';
  return 0;
}
/*
7
4 1
4 2
1 3
5 1
7 2
2 6
4 1 1 5 2 1 3

12
*/