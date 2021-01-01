#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout << fixed << setprecision(10);

#define chk(a) cerr<<"check "<<#a<<" = "<<a<<endl;
#define chk2(a,b) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<endl;
#define chk3(a,b,c) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<endl;
#define chk4(a,b,c,d) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<" , "<<#d<<" = "<<d<<endl;
#define print(v) cerr<<#v<<": ";for(auto &i:v) cout<<i<<" "; cout<<endl;

#define ll	long long int
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

ll inf = 1e10;
ll n;
ll timer=0;

vector<vecll>adj;
vecll res;
void dfs(ll u, ll par){
	// cout<<u<<" "<<par<<endl;
	timer++;
	ll start=timer;
	for(ll v:adj[u]){
		if(v!=par)
			dfs(v,u);
	}
	
	res[u] = (timer - start);
}

void solve(){
	cin>>n;
	adj.resize(n+1);
	ll node;
	for(ll i=2;i<=n;i++){
		cin>>node;
		adj[i].pb(node);
		adj[node].pb(i);
	}
	res.assign(n+1,0);
	dfs(1,0);

	for(ll i=1;i<=n;i++)
		cout<<res[i]<<" ";
}

int main(){
	FAST
	solve();
	return 0;
}