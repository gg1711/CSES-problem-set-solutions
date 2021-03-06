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
const int N = 1e5 + 5;
ll n,m;

vector<pll>g1[N];
vector<pll>g2[N];

vector<ll> d1,d2;
void dijkstra(vector<pll>g[],vector<ll>&d, int src){
	priority_queue<pll,vector<pll>,greater<pll>>pq;

	pq.push({0,src});
	d[src]=0;
	while(sz(pq)>0){
		pll node=pq.top();
		pq.pop();
		if(d[node.S]<node.F) continue;
		for(auto p:g[node.S]){
			if(d[p.F] > d[node.S] + p.S){
				d[p.F] = d[node.S] + p.S;
				pq.push({d[p.F], p.F});
			}
		}
	}
	return;
}

void solve(){
	cin>>n>>m;
	int a,b,w;
	d1.assign(n+1,inf);
	d2.assign(n+1,inf);
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		g1[a].pb({b,w});
		g2[b].pb({a,w}); //transpose graph
	}

	dijkstra(g1,d1,1);
	dijkstra(g2,d2,n);

	ll ans=inf;

	for(int u=1;u<n;u++)
		for(auto p:g1[u])
			ans = min(ans, d1[u] + d2[p.F] + p.S/2);
	cout<<ans<<endl;
	return ;
}

int main(){
	FAST
	solve();
	return 0;
}