#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N=100010;

int n;
char s[N];
ll x,y,tx,ty,sx,sy,ans=inf;
struct Node{
	ll x,y;
}node[N];
bool tag;

inline bool check(ll t){//at s[t] the Neko is caught
  ll cyc=t/n;
  ll dx=cyc*sx+node[t%n].x,dy=cyc*sy+node[t%n].y;
  ll t1=abs(tx+dx-x)+abs(ty+dy-y);
  ll t2=t;
  return t1<=t2;
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>x>>y>>tx>>ty;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		if(s[i]=='U') sy++;
		else if(s[i]=='D') sy--;
		else if(s[i]=='L') sx--;
		else if(s[i]=='R') sx++;
		node[i]={sx,sy};
	}

  ll l=0,r=1e15;
  while(l<r){
    ll mid=(l+r)>>1;
    if(check(mid)) r=mid,tag=true;
    else l=mid+1;
  }
  if(tag) cout<<l<<'\n';
  else cout<<-1<<'\n';
	return 0;
}
