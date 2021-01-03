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
char g[1005][1005];
bool vis[1005][1005];
ll n,m;

void dfs(int r, int c){
	if(r<0 || c<0 || r>=n ||c>=m || g[r][c]=='#' || vis[r][c]==1) return;
	vis[r][c]=1;
	dfs(r+1,c);
	dfs(r,c+1);
	dfs(r-1,c);
	dfs(r,c-1);
}


void solve(){
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(g[i][j]=='.' && vis[i][j]==0){
				cnt++;
				dfs(i,j);
			}
		}
	cout<<cnt<<endl;
}

int main(){
	FAST
	solve();
	return 0;
}