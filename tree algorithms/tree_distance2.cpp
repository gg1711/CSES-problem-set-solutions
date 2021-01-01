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
ll timer=0;

vector<pll>info; //stores sum and no of subordinates for each node
vector<ll> res;
void dfs(ll u, ll par){
	timer++;
	ll start=timer;
	ll cnt=0;

	for(ll v:adj[u]){
		if(v==par) continue;
		dfs(v,u);
		cnt+=(info[v].F + info[v].S + 1);
	}
	info[u] = {cnt, timer-start};
}

void dfs2(ll u, ll par){
	ll cnt=info[u].F;

	if(par!=-1){
		cnt+=(info[par].F - (info[u].F + info[u].S + 1) + (info[par].S - info[u].S -1) + 1);
		info[u] = {cnt, n-1};
	}

	res[u] = cnt;

	for(ll v:adj[u]){
		if(v==par) continue;
		dfs2(v,u);
	}
}


void solve(){
	cin>>n;
	adj.resize(n+1);
	info.resize(n+1);
	res.resize(n+1);
	ll u,v;
	for(int cnt=0;cnt<n-1;cnt++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1);
	
	// for(auto p:info)
	// 	cout<<p.F<<" "<<p.S<<endl;

	dfs2(1,-1);

	// for(auto p:info)
	// 	cout<<p.F<<" "<<p.S<<endl;

	for(ll idx=1;idx<=n;idx++)
		cout<<res[idx]<<" ";
	cout<<endl;

}

int main(){
	FAST
	solve();
	return 0;
}