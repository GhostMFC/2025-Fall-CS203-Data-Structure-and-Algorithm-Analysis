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

const int N=100010;

bool vis[N];
int n,m,s,cnt,head[N],ans[N];
struct Edge{
  int to,nxt;
}edge[N<<4];
inline void Add(int fo,int to){
  edge[++cnt]={to,head[fo]};
  head[fo]=cnt;
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m>>s;
    cnt=0;
    for(int i=1;i<=n;++i) head[i]=0,ans[i]=0x3f3f3f3f,vis[i]=false;
    for(int i=1;i<=m;++i){
      int x,y;
      cin>>x>>y;
      Add(x,y); Add(y,x);
    }
    Deque<int> q;
    q.pushBack(s);
    ans[s]=0;
    while(!q.isEmpty()){
      int c=q.popFront();
      if(vis[c]) continue;
      vis[c]=true;
      for(int i=head[c];i;i=edge[i].nxt){
        int &to=edge[i].to;
        if(vis[to]) continue;
        if(ans[to]<=ans[c]+1) continue;
        ans[to]=ans[c]+1;
        q.pushBack(to);
      }
    }
    for(int i=1;i<=n;++i){
      if(ans[i]==0x3f3f3f3f)
        ans[i]=-1;
      cout<<ans[i]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}