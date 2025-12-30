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

const int N=100010;

ll dis[N];
bool vis[N];
int n,m,head[N],cnt;
struct Node{
  int x; ll dis;
  bool operator <(const Node& o)const{
    return dis<o.dis;
  }
};
struct Edge{int to,nxt; ll val;}edge[N];
inline void Add(int fo,int to,ll val){
  edge[++cnt]={to,head[fo],val};
  head[fo]=cnt;
}

signed main(){
  IOS
  cin>>n>>m;
  for(int i=1;i<=m;++i){
    int fo,to; ll val;
    cin>>fo>>to>>val;
    Add(fo,to,val);
  }
  for(int i=1;i<=n;++i) dis[i]=-1;
  dis[1]=0;

  Priority_Queue<Node> pq;
  pq.Push({1,0});
  while(!pq.Empty()){
    Node c=pq.Top(); pq.Pop();
    if(vis[c.x]) continue;
    vis[c.x]=true;
    for(int i=head[c.x];i;i=edge[i].nxt){
      int &to=edge[i].to;
      if(vis[to]) continue;
      if(dis[to]==-1||dis[to]>dis[c.x]+edge[i].val){
        dis[to]=dis[c.x]+edge[i].val;
        pq.Push({to,-dis[to]});
      }
    }
  }
  cout<<dis[n]<<'\n';

  return 0;
}