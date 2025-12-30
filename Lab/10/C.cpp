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

const int N=50010;

int n,m,a[N];
inline int trans(int x,int y)
{ return (x-1)*m+y;}
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct Edge{ int fo,to; ll dis;
  bool operator<(const Edge& o)const{
    return dis<o.dis;
  }
};
int fa[N];
inline int find(int x)
{ return x==fa[x]?x:fa[x]=find(fa[x]);}

signed main(){
  IOS
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j){
      cin>>a[trans(i,j)];
      fa[trans(i,j)]=trans(i,j);
    }
  Priority_Queue<Edge> pq;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j){
      int node=trans(i,j);
      for(int k=0;k<4;++k){
        int tx=i+dx[k],ty=j+dy[k];
        if(tx<1||ty<1||tx>n||ty>m) continue;
        int node2=trans(tx,ty);
        pq.Push({node,node2,a[node]*a[node2]});
      }
    }
  ll ans=0;
  while(pq.Size()){
    Edge c=pq.Top(); pq.Pop();
    int x=c.fo,y=c.to;
    x=find(x),y=find(y);
    if(x==y) continue;
    fa[x]=y;
    ans+=c.dis;
  } cout<<ans<<'\n';

  return 0;
}