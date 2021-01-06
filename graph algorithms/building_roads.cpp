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
vector<int>g[N];
bool vis[N];

void dfs(int u){
	if(vis[u]!=0 || u<=0 || u>n) return;
	vis[u]=1;
	for(int v:g[u])
		dfs(v);
}

void solve(){
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(vis,0,sizeof(vis));
	vector<int>leader;

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			leader.pb(i);
			dfs(i);
		}
	}
	cout<<sz(leader)-1<<endl;
	for(int i=0;i<sz(leader)-1;i++)
		cout<<leader[i]<<" "<<leader[i+1]<<endl;

}

int main(){
	FAST
	solve();
	return 0;
}