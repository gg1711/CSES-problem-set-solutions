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


void dfs(ll u, ll par){
	dis[u][0] = par;
	for(int i=1;i<=20;i++){
		if(dis[u][i-1]!=-1)
			dis[u][i] = dis[dis[u][i-1]][i-1];
		else
			dis[u][i]=-1;	
	}

	for(ll v:g[u]){
		if(v!=par)
			dfs(v,u);
	}
}

ll query(ll x, ll k){
	ll node = x;

	for(ll i=20;i>=0 && node!=-1;i--){
		if(k & (1<<i)){
			// cout<<(1<<i)<<endl;
			node = dis[node][i];
		}
	}
	return node;
}



void solve(){
	ll q;
	cin>>n>>q;
	g.resize(n+1);
	dis.assign(n+1, vecll(22,-1));
	ll u,v;
	for(int i=2;i<=n;i++){
		cin>>u;
		g[i].pb(u);
		g[u].pb(i);
	}
	dfs(1,-1);
	// for(auto i:dis){
	// 	print(i);
	// }
	ll x,k;
	for(ll i=0;i<q;i++){
		cin>>x>>k;
		cout<<query(x,k)<<endl;
	}
}

int main(){
	FAST
	solve();
	return 0;
}