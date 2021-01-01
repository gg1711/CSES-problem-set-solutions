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
vector<pll> res;
ll ans=0;

map<ll,vector<pll>> mp;

ll dfs(ll u, ll par){
	// cout<<u<<" "<<par<<endl;
	ll max_len=0;

	for(ll v:adj[u]){
		if(v!=par){
			ll dist = dfs(v,u);
			mp[u].pb({v,dist});
			max_len = max(max_len, dist); 
		}
	}	
	return max_len+1;
}

ll dfs1(ll u, ll par){
	// cout<<u<<" "<<par<<endl;
	vector<pll> child = {{0,0}, {0,0}};

	for(ll v:adj[u]){
		if(v!=par)
			child.pb({dfs1(v,u),v});
	}
	sort(all(child));
	
	ll x=child[sz(child)-1].F;
	ll y=child[sz(child)-2].F;
	ans = max(ans, x+y+1);
	
	if (x) mp[u].pb({child[sz(child)-1].S, child[sz(child)-1].F});
	if (y) mp[u].pb({child[sz(child)-2].S, child[sz(child)-2].F});

	return child[sz(child)-1].F+1;
}


void dfs2(ll u, ll par){
	ll max_len=1;
	
	bool flag=0;
	if(par!=-1){
		for(auto p:mp[par]){
			if(p.F!=u){
				max_len = max(max_len, p.S+1);		
			}
		}
		mp[u].pb({par,max_len});
	}


	for(auto p:mp[u]){
		max_len = max(p.S,max_len);
	}
	// cout<<u<<" "<<max_len<<" "<<flag<<endl;
	res[u] = {max_len,flag};

	for(ll v:adj[u]){
		if(v!=par)
			dfs2(v,u);
	}
}


void solve(){
	cin>>n;
	if(n==1){
		cout<<0;
		return;
	}
	adj.resize(n+1);
	res.resize(n+1);
	ll u,v;
	for(int cnt=0;cnt<n-1;cnt++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1,-1);
	dfs2(1,-1);

	// for(auto p:mp){
	// 	cout<<p.F<<": ";
	// 	for(auto pp:p.S){
	// 		cout<<"{ "<<pp.F<<" "<<pp.S<<"}, ";
	// 	}
	// 	cout<<endl;
	// }

	
	
	for(ll idx=1;idx<=n;idx++)
		cout<<res[idx].first<<" ";
}

int main(){
	FAST
	solve();
	return 0;
}