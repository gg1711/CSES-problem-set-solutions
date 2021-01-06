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
const int N = 502;
ll n,m;

ll g[N][N];

void solve(){
	ll q;
	cin>>n>>m>>q;
	ll a,b,w;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) g[i][j]=0;
			else g[i][j]=inf;
		}
	
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		g[a][b]=min(g[a][b],w);
		g[b][a]=min(g[a][b],w);
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
			}

	while(q--){
		cin>>a>>b;
		if(g[a][b]==inf)
			cout<<-1<<endl;
		else
			cout<<g[a][b]<<endl;
	}
}

int main(){
	FAST
	solve();
	return 0;
}