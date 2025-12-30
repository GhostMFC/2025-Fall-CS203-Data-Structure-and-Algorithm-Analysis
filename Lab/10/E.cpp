#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=50005;

int n,m,a[N],cnt,head[N],ss,in[N];
struct Edge{
	int fo,to,nxt;
}edge[N];
inline void Add(int fo,int to){
	edge[++cnt]={fo,to,head[fo]};
	head[fo]=cnt;
}

bool ins[N];
int dfn[N],low[N],s[N],top,belong[N],gp,v[N];
inline void tj(int x){
	dfn[x]=low[x]=++cnt,s[++top]=x,ins[x]=true;
	for(int i=head[x];i;i=edge[i].nxt){
		int &to=edge[i].to;
		if(!dfn[to]){
			tj(to);
			low[x]=min(low[x],low[to]);
		} else if(ins[to]) low[x]=min(low[x],low[to]);
	}
	
	if(dfn[x]==low[x]){
		int c; ++gp;
		do{
			c=s[top--];
			ins[c]=false;
			belong[c]=gp;
			v[gp]+=a[c];
		} while(top&&c^x);
	}
}

int main(){
	IOS
	cin>>n>>m>>ss;
	for(int i=1;i<=m;++i){
    int fo,to;
		cin>>fo>>to;
		Add(fo,to);
	}
	
	cnt=0;
	for(int i=1;i<=n;++i)
		if(!dfn[i]){
			top=0;
			tj(i);
		}
		
	cnt=0;
  for(int i=1;i<=n;++i) head[i]=0;
	for(int i=1;i<=m;++i){
		int x=belong[edge[i].fo],y=belong[edge[i].to];
		if(x^y){
			Add(x,y);
			in[y]+=1;
		}
	}
  int ans=0;
  for(int i=1;i<=gp;++i)
    if(!in[i])
      ++ans;
  ans-=(!in[belong[ss]]);
  cout<<ans<<'\n';
	return 0;
}