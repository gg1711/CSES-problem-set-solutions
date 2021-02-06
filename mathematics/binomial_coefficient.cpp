#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout << fixed << setprecision(10);

#define chk(a) cerr<<"check "<<#a<<" = "<<a<<endl;
#define chk2(a,b) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<endl;
#define chk3(a,b,c) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<endl;
#define chk4(a,b,c,d) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<" , "<<#d<<" = "<<d<<endl;
#define print(v) cerr<<#v<<": ";for(auto &i:v) cout<<i<<" "; cout<<endl;

#define ll	 long long int
#define ld   long double
#define pii  pair<int,int>
#define pll pair<ll,ll>
#define veci vector<int>
#define vecll vector<ll>
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
#define F first
#define S second
#define sz(a)	(int)(a).size()

#define N 1e6+5
vector<ll>fact;

void pre(){
	fact.assign(N,1);
	for(int i=2;i<N;i++)
		fact[i] = fact[i-1]*i%mod;
}

ll power(ll a, ll b,ll m){
	if(b==0) return 1;
	ll temp=power(a,b/2,m);
	temp=temp*temp%m;
	if(b%2)temp*=a;
	return temp%m;
}

ll inv(ll a,ll m=mod){
	return power(a,m-2,m);
}

void solve(){
	ll q;
	cin>>q;
	while(q--){
		ll a,b;
		cin>>a>>b;
		ll ans = fact[a]*inv(fact[b])%mod*inv(fact[a-b])%mod;
		cout<<ans<<"\n";
	}
}

int main(){
	FAST;
	auto start = chrono::high_resolution_clock::now();
	pre();
	solve();
	auto stop = chrono::high_resolution_clock::now(); 
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cerr << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
	return 0;
}