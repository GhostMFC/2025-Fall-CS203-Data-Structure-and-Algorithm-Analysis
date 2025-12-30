#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=400010;

int ans,n,head[N],cnt,fa[N],m,tot[N],dep[N],len,a[N];
struct Node{int num,dep;}node[N];
struct Edge{
  int to,nxt;
}edge[N<<1];
inline void Add(int fo,int to){
  edge[++cnt]={to,head[fo]};
  head[fo]=cnt;
}

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

inline void solve(int root){
  len=0;
  dep[root]=1;
  Deque<int> q;
  q.pushBack(root);
  // cout<<root<<"------------\n";
  while(!q.isEmpty()){
    int p=q.popFront();
    // cout<<p<<' ';
    if(tot[p]) a[++len]=dep[p];
    for(int i=head[p];i;i=edge[i].nxt){
      int &to=edge[i].to;
      if(dep[to]) continue;
      q.pushBack(to);
      dep[to]=dep[p]+1;
      // a[++len]=dep[to];
    }
  }
  // cout<<root<<'\n';
  // for(int i=1;i<=len;++i)
  //   cout<<a[i]<<' ';
  // cout<<'\n';

  for(int i=2;i<=len;++i)
    if(a[i]<=a[i-1]) a[i]=a[i-1]+1;
  ans=max(ans,a[len]);
}

signed main(){
  IOS
  cin>>n;
  for(int i=1,u,v;i<n;++i){
    cin>>u>>v;
    Add(u,v),Add(v,u);
  }
  cin>>m;
  for(int i=1;i<=m;++i){
    int x;
    cin>>x;
    tot[x]++;
  } dep[1]=1e9;
  for(int i=head[1];i;i=edge[i].nxt) solve(edge[i].to);
  cout<<ans<<'\n';
  return 0;
}
/*
8
1 2
2 3
2 4
3 5
3 6
4 7
4 8
4
5 6 7 8
   
*/