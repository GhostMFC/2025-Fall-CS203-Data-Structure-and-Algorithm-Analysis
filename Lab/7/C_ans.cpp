#include <iostream>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1005;

int n, pre[N], in[N], tag[N];
struct Node{int lch, rch;} node[N];

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

void dfs(int pos) {
    if(node[pos].lch) dfs(node[pos].lch);
    if(node[pos].rch) dfs(node[pos].rch);
    cout << pos << ' ';
}

void build() {
    Deque<int> st;
    st.pushBack(pre[1]);
    int j = 1;
    for (int i = 2; i <= n; i++) {
        int top = st.Back();
        if (tag[pre[i]] < tag[top]) {
            node[top].lch = pre[i];
            st.pushBack(pre[i]);
        } else {
            int parent = top;
            while (!st.isEmpty() && tag[st.Back()] < tag[pre[i]]) {
                parent = st.popBack();
                j++;
            }
            node[parent].rch = pre[i];
            st.pushBack(pre[i]);
        }
    }
}

int main() {
  freopen("C.in","r",stdin);
  freopen("C.txt","w",stdout);
    IOS
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> pre[i];
            node[i].lch = node[i].rch = 0;
        }
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tag[x] = i;
        }
        build();
        dfs(pre[1]);
        cout << '\n';
    }
    return 0;
}