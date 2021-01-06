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
const int N = 2e5 + 5;
ll n,m;
vector<int>g[N];
bool vis[N];
int color[N];
bool flag=0;

void dfs(int u, int c){
	if(flag==1) return;
	// cout<<u<<" "<<c<<endl;
	color[u]=c;
	vis[u]=1;
	for(int v:g[u]){
		if(vis[v]==0)
			dfs(v,c%2+1);
		else if(color[u]==color[v])
			flag=1;
	}
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
	flag=0;
	for(int i=1;i<=n && flag==0;i++)
		if(vis[i]==0) dfs(i,1);

	if(flag==0){
		for(int i=1;i<=n;i++)
			cout<<color[i]<<" ";
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
}

int main(){
	FAST
	solve();
	return 0;
}