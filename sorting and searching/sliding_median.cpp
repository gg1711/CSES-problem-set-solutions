#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
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
#define size(a)	(int)a.size()

typedef tree<pll, null_type, less<pll>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_tree;

void getMedian(ll k, ll a, ll b){
		cout<<min(a,b)<<" ";
}

void solve(){
	ll n,k;
	cin>>n>>k;
	vecll a(n);
	for(ll &i:a)
		cin>>i;

	ordered_tree st;

	for(ll idx=0;idx<k-1;idx++)
		st.insert({a[idx],idx});

	for(ll i=k-1;i<n;i++){
		st.insert({a[i],i});
		getMedian(k, (*st.find_by_order((k-1)/2)).F, (*st.find_by_order(k/2)).F);
		st.erase({a[i-(k-1)], i-(k-1)});
	}
	cout<<endl;
}

void balance(multiset<ll>&left, multiset<ll>&right){
	if(size(left)>(size(right)+1)){
		right.insert(*(left.rbegin()));
		left.erase(--left.end());
	}
	else if(size(left) < size(right)){
		left.insert(*(right.begin()));
		right.erase(right.begin());
	}
}

void add(multiset<ll>&left, multiset<ll>&right, ll val){
	if(size(left)>0 && val > *(left.rbegin()))
		right.insert(val);
	else
		left.insert(val);
	balance(left, right);	
}

void erase(multiset<ll>&left, multiset<ll>&right, ll val){
	if(left.count(val)>0)
		left.erase(left.find(val));
	else
		right.erase(right.find(val));
	balance(left,right);
}


void solve2(){
	ll n,k;
	cin>>n>>k;
	vecll a(n);
	for(ll &i:a)
		cin>>i;
	//left keeps min element and right keeps maximum
	multiset<ll>left, right;

	//add()
	//erase()
	//median()
	for(ll idx=0;idx<n;idx++){
		add(left, right,a[idx]);
		if(idx>=k-1){
			cout<<(*left.rbegin())<<" ";
			// print(left);
			// print(right);
			erase(left, right,a[idx-(k-1)]);
		}
	}
	cout<<endl;
	return;

}

int main(){
	FAST;
	solve2();
	return 0;
}