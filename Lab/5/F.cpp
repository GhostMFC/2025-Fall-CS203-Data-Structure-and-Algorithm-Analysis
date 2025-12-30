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
        cout<<current->data.num<<" ";
        current=current->next;
      } cout<<'\n';
    }
};

const int N=3000005;

int k,n,a[N];
struct Two{int val,num;};

inline void solve(){
  Deque<Two> dqmx,dqmn;
  int ans=1,pos=1;
  dqmx.pushBack({a[1],1}),dqmn.pushBack({a[1],1});
  for(int i=1;i<=n;++i){
    pos=max(pos,i);
    while(pos<n){
      while(!dqmx.isEmpty()&&dqmx.Front().num<i) dqmx.popFront();
      while(!dqmn.isEmpty()&&dqmn.Front().num<i) dqmn.popFront();
      if(dqmx.isEmpty()||dqmn.isEmpty()){//current pos
        dqmx.pushFront({a[pos],pos});
        dqmn.pushFront({a[pos],pos});
      }
      if(!dqmx.isEmpty()&&!dqmn.isEmpty()){
        int mx=max(dqmx.Front().val,a[pos+1]);
        int mn=min(dqmn.Front().val,a[pos+1]);
        // cout<<i<<' '<<mx<<' '<<mn<<'\n';
        if(mx-mn>k) break;
      }
      ++pos;
      while(!dqmx.isEmpty()&&a[pos]>=dqmx.Back().val)
        dqmx.popBack();
      dqmx.pushBack({a[pos],pos});
      while(!dqmn.isEmpty()&&a[pos]<=dqmn.Back().val)
        dqmn.popBack();
      dqmn.pushBack({a[pos],pos});
    }
    // cout<<i<<": "<<pos<<'\n';
    // dqmx.display(),dqmn.display();
    ans=max(ans,pos-i+1);
    // if(i==2) break;
  } cout<<ans<<'\n';
}

signed main(){
  IOS
  cin>>k>>n;
  for(int i=1;i<=n;++i)
    cin>>a[i];
  solve();
  return 0;
}
/*
4 8
2 1 4 7 4 8 3 6

4
*/