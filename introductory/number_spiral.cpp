#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout << fixed << setprecision(10);

#define chk(a) cerr<<"check "<<#a<<" = "<<a<<endl;
#define chk2(a,b) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<endl;
#define chk3(a,b,c) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<endl;
#define chk4(a,b,c,d) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<" , "<<#d<<" = "<<d<<endl;
#define print(v) cerr<<#v<<": ";for(auto &i:v) cout<<i<<" "; cout<<endl;

#define ll long long int
#define ld   long double
#define pii             pair<int,int>
#define pll pair<ll,ll>
#define veci vector<int>
#define vecll vector<ll>
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
#define F first
#define S second

int main(){
	FAST;
	int n;
	cin>>n;
	while(n--){
		unsigned long long int x, y;
		cin>>x>>y;
		unsigned long long int result=0;
		if(x>=y){
			if(x%2)
				result =(x-1)*(x-1)+y;
			else 
				result = x*x-y+1;
		}
		else{
			if(y%2)
				result = y*y-x+1;
			else
				result =(y-1)*(y-1)+x;
		}
		cout<<result<<endl;
	}
	return 0;
}