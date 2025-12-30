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

const int N=50010,K=11;

int n,m,p,k,cnt,head[N],s,t;
struct Edge{
  int fo,to,nxt,val;
}edge[N<<1];
inline void Add(int fo,int to,int val){
  edge[++cnt]={fo,to,head[fo],val};
  head[fo]=cnt;
}

ll dis[N][K];
bool vis[N][K];
struct Node{
  int x,y; ll dis;
  bool operator<(const Node& o)const{
    return dis<o.dis;
  }
};

inline void solve(){
  for(int i=0;i<=p;++i)
    for(int j=1;j<=n;++j)
      dis[j][i]=1e18;
  Priority_Queue<Node> pq;
  dis[s][0]=0;
  pq.Push({s,0,0});
  while(pq.Size()){
    Node c=pq.Top(); pq.Pop();
    if(vis[c.x][c.y]) continue;
    vis[c.x][c.y]=true;
    for(int i=head[c.x];i;i=edge[i].nxt){
      int &to=edge[i].to;
      if(!edge[i].val){//layer lift~~~~
        if(c.y==k) continue;
        if(dis[to][c.y+1]>dis[c.x][c.y]){
          dis[to][c.y+1]=dis[c.x][c.y];
          pq.Push({to,c.y+1,dis[c.x][c.y]});
        }
      } else{
        if(dis[to][c.y]>dis[c.x][c.y]+edge[i].val){
          dis[to][c.y]=dis[c.x][c.y]+edge[i].val;
          pq.Push({to,c.y,-dis[to][c.y]});
          // if(!c.y) cout<<c.x<<' '<<to<<' '<<dis[to][0]<<'\n';
        }
      }
    }
  }

  // for(int i=0;i<=k;++i){
  //   cout<<"Layer "<<i<<": "<<'\n';
  //   for(int j=1;j<=n;++j)
  //     cout<<dis[j][i]<<' ';
  //   cout<<'\n';
  // }

  ll ans=1e18;
  for(int i=0;i<=k;++i)
    ans=min(ans,dis[t][i]);
  cout<<ans<<'\n';
}

signed main(){
  IOS
  cin>>n>>m>>p>>k;
  for(int i=1;i<=m;++i){
    int fo,to,val;
    cin>>fo>>to>>val;
    Add(fo,to,val);
  }
  for(int i=1;i<=p;++i){
    int fo,to;
    cin>>fo>>to;
    Add(fo,to,0);
  }
  cin>>s>>t;
  solve();
  return 0;
}