#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define ll long long int
ll mod=1e9+7;

ll power(ll a, ll b, ll mod=mod){
	if(b==0) return 1;
	if(b==1) return a;
	ll temp = power(a,b/2,mod);
	temp = (temp*temp)%mod;
	if(b%2)
		temp*=a;
	return temp%mod;
}

int main(){
	FAST;
	ll n;
	cin>>n;
	while(n--){
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<power(a,power(b,c,mod-1))<<"\n";
	}
}