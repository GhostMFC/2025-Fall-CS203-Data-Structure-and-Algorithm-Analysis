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
 
const int N=300010;
 
int a[N],sufmn[N];
 
signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    Deque<int> st;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sufmn[n]=a[n];
    for(int i=n-1;i;--i) sufmn[i]=min(sufmn[i+1],a[i]);
    int pos=2; st.pushBack(a[1]);
    while(pos<=n){
      if(!st.isEmpty()&&sufmn[pos]>st.Back()){
        int premx=st.Back();
        while(!st.isEmpty()){
          int x=st.popBack();
          cout<<x<<' ';
          if(x==premx) break;
        }
      } else{
        int v=sufmn[pos];
        while(pos<=n){
          if(v==a[pos]){
            cout<<v<<' ';
            ++pos;
            break;
          } st.pushBack(a[pos]);
          ++pos;
        }
      } 
    }
    while(!st.isEmpty())
      cout<<st.popBack()<<' ';
    cout<<'\n';
  }
  return 0;
}
/*
1
4
3 4 1 2
*/