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
const int N = 1e5 + 5;
ll n,m;

vector<pll>g[N];
ll dis[N];
ll vis[N];
ll par[N];
ll wt[N];

void solve(){
	cin>>n>>m;
	ll a,b,w;
	
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		g[a].pb({b,w});
	}
	memset(dis,-1,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(par,-1,sizeof(par));
	memset(wt,-1,sizeof(wt));
	priority_queue<pll>pq;

	pq.push({0,1});
	dis[1]=0;
	ll maxVal=0;
	while(!pq.empty()){
		ll u = pq.top().S;
		pq.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(auto v:g[u]){
			if((dis[v.F]==-1 || dis[v.F]>dis[u]+v.S) && vis[v.F]==0){
				dis[v.F] = dis[u]+v.S;
				par[v.F]=u;
				wt[v.F]=v.S;
				pq.push({-dis[v.F], v.F});
			}
		}
	}

	int p=n;
	while(p!=1){
		maxVal=max(maxVal,wt[p]);
		p=par[p];
	}
	// cout<<dis[n]<<endl;
	cout<<dis[n]-(maxVal+1)/2<<endl;
}

int main(){
	FAST
	solve();
	return 0;
}