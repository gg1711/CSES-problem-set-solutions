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

vector<ll>dis,len,pathCnt,mini,maxi;

void dijkstra(ll src){
	priority_queue<pll, vector<pll>,greater<pll>>pq;
	pq.push({0,src});
	dis[src]=0;
	pathCnt[src]=1;
	mini[src]=0;maxi[src]=0;
	while(sz(pq)!=0){
		ll u=pq.top().S;
		ll d=pq.top().F;
		pq.pop();

		if(d>dis[u])continue;
		// cout<<u<<" "<<d<<endl;
		for(auto p:g[u]){
			ll v=p.F,wt=p.S;
			if(dis[v] > d+wt){
				dis[v]=d+wt;
				pathCnt[v]=pathCnt[u];
				mini[v]=min(mini[v], mini[u]+1);
				maxi[v]=max(maxi[v], maxi[u]+1);
				pq.push({dis[v],v});
			}
			else if(dis[v]==d+wt){
				pathCnt[v]+=pathCnt[u];
				mini[v]=min(mini[v], mini[u]+1);
				maxi[v]=max(maxi[v], maxi[u]+1);
				pathCnt[v]%=mod;
				pq.push({dis[v],v});
			}
		}
	}
}

void dijkstra_set(ll src){
	set<pll>pq;
	pq.insert({0,src});
	dis[src]=0;
	pathCnt[src]=1;
	mini[src]=0;maxi[src]=0;
	while(sz(pq)!=0){
		auto itr=pq.begin();
		ll u=(*itr).S;
		ll d=(*itr).F;
		pq.erase(itr);

		if(d>dis[u])continue;
		// cout<<u<<" "<<d<<endl;
		for(auto p:g[u]){
			ll v=p.F,wt=p.S;
			if(dis[v] > d+wt){
				dis[v]=d+wt;
				pathCnt[v]=pathCnt[u];
				mini[v] = mini[u]+1;
				maxi[v]= maxi[u]+1;
				pq.insert({dis[v],v});
			}
			else if(dis[v]==d+wt){
				pq.erase({dis[v],v});
				pathCnt[v]+=pathCnt[u];
				mini[v]=min(mini[v], mini[u]+1);
				maxi[v]=max(maxi[v], maxi[u]+1);
				pathCnt[v]%=mod;
				pq.insert({dis[v],v});
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	dis.assign(n+1,inf);
	pathCnt.assign(n+1,0);
	mini.assign(n+1,inf);
	maxi.assign(n+1,0);
	len.assign(n+1,0);
	ll a,b,w;
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		g[a].pb({b,w});
	}

	dijkstra_set(1);

	cout<<dis[n]<<" "<<pathCnt[n]<<" "<<mini[n]<<" "<<maxi[n]<<endl;

}

int main(){
	FAST
	solve();
	return 0;
}