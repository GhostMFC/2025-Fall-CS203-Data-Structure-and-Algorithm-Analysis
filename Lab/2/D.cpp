#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

const int N=3005;

int S;
int n,a[N],b[N*N],len,tmp[N*N],tot[N*N];

inline void merge(int l,int r){
	if(l==r) return ;
	int mid=(l+r)>>1;
	merge(l,mid); merge(mid+1,r);
	int lt=l,rt=mid+1;
	for(int i=l;i<=r;++i)
		if(rt>r||(lt<=mid&&b[lt]<b[rt]))
			tmp[i]=b[lt],++lt;
		else tmp[i]=b[rt],++rt;
	for(int i=l;i<=r;++i)
		b[i]=tmp[i];
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n>>S;
	for(int i=1;i<=n;++i)
		cin>>a[i];
		
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			b[++len]=a[i]+a[j];
	merge(1,len);
//	for(int i=1;i<=len;++i) cout<<b[i]<<' ';
//	return 0; 
	
	ll ans=0;
	for(int i=3;i<=n;++i){
		int v=S-a[i];
		for(int j=1;j<i-1;++j){
			int p=a[j]+a[i-1];
			int l=1,r=len;
			while(l<r){
				int mid=(l+r)>>1;
				if(b[mid]>=p) r=mid;
				else l=mid+1;
			}
//			cout<<i<<' '<<p<<' '<<l<<'\n';
			tot[l]++;
		}
		int l=1,r=len;
		while(l<r){
			int mid=(l+r)>>1;
			if(b[mid]>=v) r=mid;
			else l=mid+1;
		}
		if(b[l]!=v) continue;
		ans+=tot[l];
	}
	
	cout<<ans<<'\n'; 

	return 0;
}