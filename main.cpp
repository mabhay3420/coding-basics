#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F(i,m,n) for(ll i=m;i<n;i++)
#define Fr(j,n,m) for(ll j=n;j>=m;j--)
#define vll vector<ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpll vector< pll >
#define tlll tuple < ll ,ll,ll >
/*-------------------------------------*---------------------------------------*/

#define godspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout << #x << "=" << x << endl
#define cout_array(a) cout<<#a<<"=";for(auto x: a){ cout<<x<<" ";}cout<<endl

ll gcd(ll a,ll b){
    return (b?gcd(b,a%b):a);
}
const ll MAX_PRIME = 1e9+7;
const ll INF = 1e18;


/*I NEED YOU TO WORK FOR TWO HOURS ON THIS NO MATTER WHAT....THE RESULT DOESN'T MATTER.....ITS ALL ABOUT YOUR EFFORTS.
---------------------------------------------------------------------------------------------------------------------*/

ll fast_pow(ll x,ll y,ll z){
    if(y==0)return 1%z;
    else if(y==1)return x%z;
    if(y%2==0){
        ll res = fast_pow(x,y/2,z);
        return (res*res)%z;
    }
    else{
        ll res = fast_pow(x,y/2,z);
        ll temp = (res*res)%z;
        return ((x%z)*temp)%z;
    }
}

int main() {
    godspeed
    ll t;
    cin>>t;
    while(t--){
	    ll n;
	    cin>>n;
	    vll a(n);
	    F(i,0,n){
		    cin>>a[i];
		}
    }
    return 0;
}
