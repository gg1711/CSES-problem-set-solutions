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
const int N = 2502;
ll n,m;
vector<pair<pll,ll>>edges;
vecll dis;
vecll par;

void solve(){
	cin>>n>>m;
	ll a,b,w;
	dis.assign(n+1, inf);
	par.assign(n+1,-1);
	edges.resize(m+1);
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		edges[i]={{a,b},-w};
		//make wt negative so shortest path become longest
		//detecting -ve cycle becomes same as detecting positive cycle
	}
	dis[1]=0;
	//applying bellman-ford V-1 times 
	for(int i=1;i<=n-1;i++)
		for(auto p:edges){
			if(dis[p.F.S]>dis[p.F.F]+p.S && dis[p.F.F]!=inf){
				dis[p.F.S] = dis[p.F.F]+p.S;
				par[p.F.S]=p.F.F;
			}
		}
	// print(dis);
	//detect negative cycle
	vector<int>cycle(n+1,0);
	for(int i=1;i<=n;i++){
		for(auto p:edges){
			if(dis[p.F.S]>dis[p.F.F]+p.S && dis[p.F.F]!=inf){
				dis[p.F.S] = dis[p.F.F]+p.S;
				cycle[p.F.S]=1;
			}
			if(cycle[p.F.F]==1 )
				cycle[p.F.S]=1;
		}
		// print(cycle);
	}

	if(cycle[n]==1)
		cout<<-1<<endl;
	else
		cout<<-dis[n]<<endl;
}

int main(){
	FAST
	solve();
	return 0;
}