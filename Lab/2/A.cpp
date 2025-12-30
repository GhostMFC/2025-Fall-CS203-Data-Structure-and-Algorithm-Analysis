#include <iostream>
#include <algorithm>
#include <string> 
#define ll long long
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll ans=n*(2*n+1)*(n+1)/6+(n+1)*n/2;
		cout<<ans/2<<'\n';
	}
	
	return 0;	
} 