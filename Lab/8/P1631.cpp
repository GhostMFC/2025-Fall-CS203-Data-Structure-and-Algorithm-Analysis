#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

template <typename T> class Priority_Queue{
  private:
    T* data;//array
    int capacity;
    int size;//current size

    void Swap(T& a,T& b)
    {T temp=a; a=b; b=temp;}

    void swim(int index){//up swap
      while(index>0){
        int parent=(index-1)/2;
        if(data[parent]<data[index]){
          Swap(data[index],data[parent]);
          index=parent;
        } else break;
      }
    }

    void sink(int index){//MAX-HEAP
      while((index<<1|1)<size){
        int lchild=index<<1|1; int rchild=lchild+1; int child=lchild;
        if(rchild<size&&data[lchild]<data[rchild]) child=rchild;
        if(data[index]<data[child]){
          Swap(data[index],data[child]);
          index=child;
        } else break;
      }
    }

    void resize(){
      capacity<<=1;
      T* newData=new T[capacity];
      for(int i=0;i<size;++i) newData[i]=data[i];
      delete[] data; data=newData;
    }
  public:
    Priority_Queue()
    {capacity=100000; size=0; data=new T[capacity];}
    Priority_Queue(int init_Capacity)
    {capacity=init_Capacity; size=0; data=new T[capacity];}
    ~Priority_Queue(){delete[] data;}

    void Push(const T& value){
      if(size>=capacity) resize();
      data[size]=value; swim(size); ++size;
    }
    void Pop(){
      if(Empty())
        throw std::runtime_error("Cannot pop from an empty priority queue");
      if(size>0){
        data[0]=data[size-1]; --size;
        if(size>0) sink(0);
      }
    }
    const T& Top() const{
      if(Empty())
        throw std::runtime_error("Cannot pop from an empty priority queue");
      return data[0];
    }
    bool Empty() const { return size==0;}
    int Size() const{ return size;}
    int Capacity() const{ return capacity;}
    void Display() const{
      std::cout<<"Priority_Queue: ";
      for(int i=0;i<size;++i) std::cout<<data[i]<<' ';
      std::cout<<std::endl;
    }
};

const int N=100010;

int n,a[N],b[N];
struct Node{
  int val,aid,bid;
  bool operator<(const Node& o) const{
    return val<o.val;
  }
};

signed main(){
  IOS
  cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=n;++i) cin>>b[i];
  sort(a+1,a+1+n); sort(b+1,b+1+n);
  Priority_Queue<Node> pq;
  for(int i=1;i<=n;++i) pq.Push({-(a[i]+b[1]),i,1});
  for(int i=1;i<=n;++i){
    Node c=pq.Top(); pq.Pop();
    cout<<-c.val<<' ';
    if(c.bid<n) pq.Push({-(a[c.aid]+b[c.bid+1]),c.aid,c.bid+1});
  }
  return 0;
}