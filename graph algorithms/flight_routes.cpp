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
ll n,m,k;

vector<pll>g[N];

vector<vecll> dis;
void dijkstra(int src){
	priority_queue<pll,vector<pll>,greater<pll>>pq;

	pq.push({0,src});

	dis[src][0]=0;

	while(sz(pq)>0){
		pll node=pq.top();
		pq.pop();
		if(dis[node.S][k-1]<node.F) continue;
		for(auto p:g[node.S]){
			if(dis[p.F][k-1] > node.F + p.S){
				dis[p.F][k-1] = node.F + p.S;
				pq.push({dis[p.F][k-1], p.F});
				sort(all(dis[p.F]));
			}
		}
	}
	return;
}

void solve(){
	cin>>n>>m>>k;
	int a,b,w;
	dis.assign(n+1,vecll(k,inf));
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		g[a].pb({b,w});
	}

	dijkstra(1);

	for(int i=0;i<k;i++)
		cout<<dis[n][i]<<" ";
	cout<<endl;
}

int main(){
	FAST
	solve();
	return 0;
}