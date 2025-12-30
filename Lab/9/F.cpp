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

const int N=100010,mod=1e9+7;

ll a[N],b[N];
int n,m,cnt,head[N],_in[N];
struct Edge{int to,nxt;}edge[N];
inline void Add(int fo,int to){
  edge[++cnt]={to,head[fo]};
  head[fo]=cnt;
}

inline void init(){
  cnt=0;
  for(int i=1;i<=n;++i)
    head[i]=0,_in[i]=0;
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m;
    init();
    for(int i=1;i<=n;++i)
      cin>>a[i]>>b[i];
    for(int i=1;i<=m;++i){
      int u,v;
      cin>>u>>v;
      Add(v,u);
      _in[u]++;
    }
    Deque<int> q;
    for(int i=1;i<=n;++i)
      if(!_in[i])
        q.pushBack(i);
    ll ans=0;
    while(!q.isEmpty()){
      int c=q.popFront();
      for(int i=head[c];i;i=edge[i].nxt){
        int &to=edge[i].to;
        _in[to]--;
        b[to]=(b[to]+b[c])%mod;
        ans=(ans+a[to]*b[c])%mod;
        if(!_in[to]) q.pushBack(to);
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}