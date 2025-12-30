#include <iostream>
#include <string>
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
    {capacity=500000; size=0; data=new T[capacity];}
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

inline void Swap(ll &a,ll &b)
{ ll tmp=a; a=b; b=tmp; return ;}
inline void threeWayQs(ll arr[],int l,int r){
  if(l>=r) return ;
  int v=(rand()%(r-l+1)+l);
  Swap(arr[l],arr[v]);
  ll pivot=arr[l]; int it=l,i=l+1,gt=r;
  while(i<=gt){
    if(arr[i]<pivot) Swap(arr[i],arr[it]),++i,++it;//add left bound
    else if(arr[i]>pivot) Swap(arr[i],arr[gt]),--gt;//minus right bound
    else ++i;
  }
  threeWayQs(arr,l,it-1); threeWayQs(arr,gt+1,r);
}

const int N=500010;

int n,m,k;
ll a[N],b[N];
struct Node{
  ll val; int numa,numb;
  bool operator<(const Node& o) const{
    return val<o.val;
  }
};

signed main(){
  IOS
  cin>>n>>m>>k;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=m;++i) cin>>b[i];
  threeWayQs(a,1,n); threeWayQs(b,1,m);
  Priority_Queue<Node> pq;
  for(int i=1;i<=n;++i) pq.Push({-a[i]*b[1],i,1});
  while(k--){
    Node c=pq.Top(); pq.Pop();
    if(c.numb<m) pq.Push({-a[c.numa]*b[c.numb+1],c.numa,c.numb+1});
    cout<<-c.val<<' ';
  }
  return 0;
}