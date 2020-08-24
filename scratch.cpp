//---decimal to binary representation--
string dec_bin(ll x){
    string result;
    while(x>0){
        result.push_back(x%2 + 48);
        x = (x-(x%2))/2;
    }
    reverse(result.begin(),result.end());
    return result;
}
//----calculate log_x(number) or return -1 if the no is not power of x;
ll pow_x(ll factor,ll x){
    ll count = 0;
    while(factor%x==0){
        count+=1;
        factor/=x;
    }
    if(factor==1)return count;
    else return -1;
}
//----c++ implementation of python function pow(x,y,z)---O(log n) implementation
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
//-------------HASHING----------------------
ll hash_value(string s){
    ll p = low_prime;
    ll m = MAX_PRIME;
    ll n  =s.length() ;
    ll pow_prime = 1;
    ll k = 0;
    F(i,0,n){
        k = (k+ (s[i]-'a'+1)*pow_prime)%m;
        pow_prime = (pow_prime*p)%m;
    }
    return k;
}
//---------------method for calculating general mod inverse-------uses extended euclid algo
ll gcdExtended(ll a, ll b, ll &x, ll &y){
    // ax+by = m
    if (a==0)         //gcd = b & ax+by = gcd(a,b)---x and y can be negative;
    {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;
    ll d = gcdExtended(b%a, a, x1, y1);
    x = y1-b/a*x1;           //use floor for negative values
    y = x1;
    return d;
}

ll modInverse(ll a, ll mod=MAX_PRIME){
    ll x, y;
    ll d = gcdExtended(a, mod, x, y);
    if (d!=1)        //gcd must be 1 for inverse to exist
    {
        return -1;
    }

    return (x%mod+mod)%mod;
}
//------------------if the no is prime use InverseMod-----faster-------
ll InverseMod(ll power){
    //m is prime---use fermat's little theorem---fast_power(a,m-1,m) = 1----multiplicative inverse of pow(p,n) is fast_pow(p,m-n-1,m)
    ll m = MAX_PRIME;
    ll p = low_prime;
    return fast_pow( p,m-power-1,m);
}
ll hash_substr(ll start_pos,ll pre_hash,ll end_hash){
    ll val = ((end_hash - pre_hash)*InverseMod(start_pos))%(MAX_PRIME);
    return (val + MAX_PRIME)%MAX_PRIME;   // to account for negative remainder
}
//--------------------------can be improved-----------------


//---------------coding template reference---------------------
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

const ll MAX_PRIME = 1e9+7;    //hashing and modulo arithmetic
const ll INF = 1e18;
const ll low_prime = 31;     //prime used in hashing of strings having only lower case letters
const ll high_prime = 53;    //for strings having both type of letter
