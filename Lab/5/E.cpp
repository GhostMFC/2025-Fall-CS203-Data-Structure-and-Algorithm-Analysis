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

const int N=2000005;

int n,m,a[N];
struct Two{int val,num;};

inline void solve(){
  Deque<Two> dq;
  for(int i=1;i<=m;++i){
    while(!dq.isEmpty()&&dq.Back().val<=a[i])
      dq.popBack();
    dq.pushBack({a[i],i});
  }
  int ans=dq.Front().val;
  for(int i=m+1;i<=n;++i){
    while(!dq.isEmpty()&&dq.Front().num<=i-m) dq.popFront();
    while(!dq.isEmpty()&&dq.Back().val<=a[i]) dq.popBack();
    dq.pushBack({a[i],i});
    ans^=dq.Front().val;
  }
  cout<<ans<<'\n';
}

signed main(){
  IOS
  cin>>m;
  while(true){
    int x;
    cin>>x;
    if(x==-1) break;
    a[++n]=x;
  } solve();

  return 0;
}