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
vector<vecll> g;

vector<vecll> dis;

vecll tin, tout, depth;

unordered_map<ll,unordered_map<ll,ll>> inc;
unordered_map<ll,ll> dcr;

ll timer=0;

void dfs(ll u, ll par, ll d){
	timer++;
	tin[u]=timer;
	depth[u]=d;
	dis[u][0] = par;
	for(int i=1;i<=20;i++){
		if(dis[u][i-1]!=-1)
			dis[u][i] = dis[dis[u][i-1]][i-1];
		else
			dis[u][i]=-1;	
	}

	for(ll v:g[u]){
		if(v!=par)
			dfs(v,u,d+1);
	}
	timer++;
	tout[u]=timer;
}

bool is_ancestor(ll u,ll v){
	return (tin[u]<=tin[v] && tout[u]>=tout[v]); //equality when u==v
}



ll update(ll x, ll y){
	ll node;
	ll temp=x;
	for(int i=20;i>-1;i--){
		node = dis[temp][i];
		// cout<<i<<" "<<x<<" "<<node<<endl;
		if(node!=-1 && is_ancestor(node,y)==0)
			temp=node;

	}
	ll lca = dis[temp][0];

	inc[lca][temp]++;
	dcr[x]--;
	return lca;
}



void path(ll x, ll y){
	ll lca;
	if(is_ancestor(x,y)){
		lca = x;
		update(y,x);
	}

	else if(is_ancestor(y,x)){
		lca = y;
		update(x,y);
	}

	else{
		update(x,y);
		lca = update(y,x);
	}
	inc[lca][lca]++;
}


vecll res;
void dfs2(ll u, ll par, ll cnt){
	res[u]=cnt;
	if(inc.count(u)>0 && inc[u].count(u)>0) res[u]+=inc[u][u];
	cnt=cnt - dcr[u];

	for(ll v:g[u]){
		if(v!=par){
			ll add=0;
			if(inc.count(u)>0 && inc[u].count(v) > 0) add+=inc[u][v];
			dfs2(v,u,cnt+add);
		}
	}
}


void solve(){
	ll q;
	cin>>n>>q;
	g.resize(n+1);
	dis.assign(n+1, vecll(22,-1));
	tin.assign(n+1,-1);
	tout.assign(n+1,-1);
	depth.assign(n+1,-1);
	res.assign(n+1,0);

	ll u,v;
	for(int i=2;i<=n;i++){
		cin>>u>>v;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1,-1,1);
	// for(auto i:dis){
	// 	print(i);
	// }
	// print(depth);
	ll x,y;
	for(ll i=0;i<q;i++){
		cin>>x>>y;
		path(x,y);
	}

	for(auto p:dcr)
		cout<<p.F<<" "<<p.S<<endl;

	for(auto p:inc){
		for(auto pp:p.S)
			cout<<p.F<<" "<<pp.F<<" "<<pp.S<<endl;
	}

	dfs2(1,-1,0);

	for(int i=1;i<=n;i++)
		cout<<res[i]<<" ";
	cout<<endl; 
}

int main(){
	FAST
	solve();
	return 0;
}