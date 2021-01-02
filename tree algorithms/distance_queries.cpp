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

ll query(ll x, ll y){
	ll lca;
	if(is_ancestor(x,y))
		lca = x;

	else if(is_ancestor(y,x))
		lca = y;

	else{
		ll node;
		ll temp=x;
		for(int i=20;i>-1;i--){
			node = dis[x][i];
			// cout<<i<<" "<<x<<" "<<node<<endl;
			if(node!=-1 && is_ancestor(node,y)==0)
				x=node;

		}
		lca= dis[x][0];
		x=temp;
	}

	return depth[x]+depth[y]- 2*depth[lca];
}

void solve(){
	ll q;
	cin>>n>>q;
	g.resize(n+1);
	dis.assign(n+1, vecll(22,-1));
	tin.assign(n+1,-1);
	tout.assign(n+1,-1);
	depth.assign(n+1,-1);

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
		cout<<query(x,y)<<endl;
	}
}

int main(){
	FAST
	solve();
	return 0;
}