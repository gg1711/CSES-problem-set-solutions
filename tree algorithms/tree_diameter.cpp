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
vector<vecll>adj;
ll ans=0;

ll dfs(ll u, ll par){
	// cout<<u<<" "<<par<<endl;
	vecll child = {0,0};

	for(ll v:adj[u]){
		if(v!=par)
			child.pb(dfs(v,u));
	}
	sort(all(child));
	
	ll x=child[sz(child)-1];
	ll y=child[sz(child)-2];
	ans = max(ans, x+y+1);
	
	return child[sz(child)-1]+1;
}


void solve(){
	cin>>n;
	adj.resize(n+1);
	ll u,v;
	for(int cnt=0;cnt<n-1;cnt++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ans = max(ans, dfs(1,-1));
	cout<<ans-1<<endl;
}

int main(){
	FAST
	solve();
	return 0;
}