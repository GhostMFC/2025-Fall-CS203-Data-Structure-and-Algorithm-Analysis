#include <iostream>
#include <string>
#include <vector>
#define pb push_back
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

const int N=200010;

bool vis[N];
int n,m,ans[N],cnt;
vector<int> G[N],P[N];

inline void dfs(int pos){
  for(int &to:G[pos]){
    if(vis[to]) continue;
    vis[to]=true;
    P[pos].pb(to);
    P[to].pb(pos);
    dfs(to);
  }
}

struct Node{ int x,tag;};
inline void sol(int pos,int tag){
  cnt=0;
  Deque<Node> q;
  q.pushBack({pos,tag});
  for(int i=1;i<=n;++i) vis[i]=false;
  while(!q.isEmpty()){
    Node c=q.popFront();
    if(vis[c.x]) continue;
    vis[c.x]=true;
    if(c.tag) ans[++cnt]=c.x;
    for(int &to:P[c.x])
      if(!vis[to])
        q.pushBack({to,c.tag^1});
    // cout<<c.x<<' '<<c.tag<<'\n';
  }
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
      vis[i]=false;
      G[i].clear();
      P[i].clear();
    }
    for(int i=1;i<=m;++i){
      int u,v;
      cin>>u>>v;
      G[u].pb(v);
      G[v].pb(u);
    }
    vis[1]=true;
    dfs(1);//build a subtree
    sol(1,1);
    if(cnt*2>n) sol(G[1][0],1);
    cout<<cnt<<'\n';
    for(int i=1;i<=cnt;++i)
      cout<<ans[i]<<' ';
    cout<<'\n';
  }
  return 0;
}