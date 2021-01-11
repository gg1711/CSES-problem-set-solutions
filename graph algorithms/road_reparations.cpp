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

ll inf = 1e18;
const int N = 2e5 + 5;
ll n,m;
vector<pll>g[N];
vecll vis;

ll sum=0;

void prim(){
	priority_queue<pll, vector<pll>,greater<pll> >pq;

	pq.push({0,1});

	while(!pq.empty()){
		auto node=pq.top();
		pq.pop();
		ll u=node.S, d=node.F;
		if(vis[u]) continue;
		vis[u]=1;
		sum+=d;
		// cout<<u<<" "<<d<<endl;
		for(pll p:g[u]){
			ll v=p.F,wt=p.S;
			if(!vis[v])
				pq.push({wt,v});
		}
	}
}

//Prims algorithm
void solve(){
	cin>>n>>m;
	ll a,b,w;
	vis.assign(n+1,0);
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		g[a].pb({b,w});
		g[b].pb({a,w});
	}

	prim();
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
	}
	cout<<sum<<endl;
}
struct edge{
	int a,b,w;
};

vecll par;
vector<edge> edges;

ll find_set(ll x){
	if(par[x]==x)
		return x;	
	return par[x] = find_set(par[x]);
}

void union_sets(ll x, ll y){
	ll a=find_set(x);
	ll b=find_set(y);
	if(a!=b)
		par[a]=b;
}

bool compare(edge &e1,edge &e2){
	return e1.w<e2.w;
}
void solve2(){
	cin>>n>>m;
	ll a,b,w;
	vis.assign(n+1,0);
	for(int i=0;i<m;i++){
		edge e;
		cin>>e.a>>e.b>>e.w;
		edges.pb(e);
	}
	par.assign(n+1,0);
	for(int i=1;i<=n;i++)
		par[i]=i;

	sort(all(edges),compare);
	ll cnt=0;
	for(ll i=0;i<m;i++){
		ll u=edges[i].a,v=edges[i].b,w=edges[i].w;
		if(find_set(u)!=find_set(v)){
			sum+=w;
			union_sets(u,v);
			cnt++;
		} 
	}

	if(cnt!=(n-1))
		cout<<"IMPOSSIBLE"<<endl;
	else
		cout<<sum<<endl;

}

int main(){
	FAST
	solve2();
	return 0;
}