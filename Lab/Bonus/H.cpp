#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=305;
bool vis[N][N];
int n,m,h[N][N];
double dis[N][N];

template <typename T> class Priority_Queue{
  private:
    T* data;
    int capacity;
    int size;

    void Swap(T& a,T& b){T temp=a; a=b; b=temp;}

    void swim(int index){
      while(index>0){
        int parent=(index-1)/2;
        if(data[parent]<data[index]){
          Swap(data[index],data[parent]);
          index=parent;
        } else break;
      }
    }

    void sink(int index){
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
    Priority_Queue(){capacity=100000; size=0; data=new T[capacity];}
    ~Priority_Queue(){delete[] data;}

    void Push(const T& value){
      if(size>=capacity) resize();
      data[size]=value; swim(size); ++size;
    }
    void Pop(){
      if(size==0) throw runtime_error("pop empty");
      data[0]=data[size-1]; --size;
      if(size>0) sink(0);
    }
    const T& Top() const{
      if(size==0) throw runtime_error("top empty");
      return data[0];
    }
    bool Empty() const { return size==0; }
    int Size() const{ return size; }
};

struct Node{
  double val;
  int x,y;
  bool operator<(const Node& o)const{
    return val<o.val;
  }
};

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  IOS
  cin>>n>>m;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      cin>>h[i][j];
      dis[i][j]=1e100;
      vis[i][j]=false;
    }
  }

  int h0 = h[1][1];

  Priority_Queue<Node> pq;
  dis[1][1]=0.0;
  pq.Push({-0.0,1,1});

  while(pq.Size()){
    Node c=pq.Top(); pq.Pop();
    int x=c.x, y=c.y;
    if(vis[x][y]) continue;
    vis[x][y]=true;

    double w = pow(2.0, (double)(h[x][y]-h0));

    for(int d=0; d<4; ++d){
      int tx=x+dx[d], ty=y+dy[d];
      if(tx<1 || tx>n || ty<1 || ty>m) continue;
      if(vis[tx][ty]) continue;

      double nd = dis[x][y] + w;
      if(nd < dis[tx][ty]){
        dis[tx][ty]=nd;
        pq.Push({-nd, tx, ty});
      }
    }
  }

  cout<<fixed<<setprecision(2)<<dis[n][m]<<"\n";
  return 0;
}
