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

void solve(){
	string s;
	cin>>s;
	if(s.size()<3) {cout<<s<<endl;return;}
	string res="";
	vector<int>freq(26,0);
	for (char c:s)
		freq[c-'A']++;
	int cnt=0;
	for(int i=0;i<26;i++)
		if(freq[i]%2==1)cnt++;
	if(cnt>1) cout<<"NO SOLUTION"<<endl;
	else{
		char special='#';
		for(int i=0;i<26;i++){
			if(freq[i]>1)
				res = res + string (freq[i]/2, 'A'+i);
			if(freq[i]%2==1)
				special = 'A'+i;
		}
		cout<<res;
		if(special!='#')cout<<special;
		reverse(all(res));
		cout<<res<<endl;
	}
}

int main(){
	FAST;
	solve();
	return 0;
}