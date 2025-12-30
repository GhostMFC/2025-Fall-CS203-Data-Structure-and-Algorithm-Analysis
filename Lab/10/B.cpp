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

const int N=200010;

int n,m,fa[N];
struct Edge{ int fo,to; ll dis;
  bool operator<(const Edge& o)const{
    return dis<o.dis;
  }
};
inline int find(int x)
{ return fa[x]==x?x:fa[x]=find(fa[x]);}

signed main(){
  IOS
  cin>>n>>m;
  Priority_Queue<Edge> pq;
  ll ans=0;
  for(int i=1;i<=m;++i){
    int u,v; ll d;
    cin>>u>>v>>d;
    pq.Push({u,v,-d});
    ans+=max(0ll,d);
  }
  for(int i=1;i<=n;++i) fa[i]=i;
  while(pq.Size()){
    Edge e=pq.Top(); pq.Pop();
    int u=e.fo,v=e.to;
    int fu=find(u),fv=find(v);
    if(fu!=fv){
      fa[fu]=fv;
      // ans+=e.dis;
      if(e.dis<0) ans+=e.dis;
      // cout<<e.dis<<'\n';
    }
  }
  cout<<ans<<'\n';

  return 0;
}