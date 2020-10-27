#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F(i, m, n) for (ll i = m; i < n; i++)
#define Fr(j, n, m) for (ll j = n; j >= m; j--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vpll vector<pll>
#define tlll tuple<ll, ll, ll>
/*-------------------------------------*---------------------------------------*/

#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define deb(x) cout << #x << "=" << x << endl
#define cout_array(a)     \
    cout << #a << "=";    \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl

ll gcd(ll a, ll b)
{
    return (b ? gcd(b, a % b) : a);
}
const ll MAX_PRIME = 1e9 + 7;
const ll INF = 1e18;

ll fast_pow(ll x, ll y, ll z)
{
    if (y == 0)
        return 1 % z;
    else if (y == 1)
        return x % z;
    if (y % 2 == 0)
    {
        ll res = fast_pow(x, y / 2, z);
        return (res * res) % z;
    }
    else
    {
        ll res = fast_pow(x, y / 2, z);
        ll temp = (res * res) % z;
        return ((x % z) * temp) % z;
    }
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////~HERE WE GO AGAIN~///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

class Node
{
public:
   Node* left;
   Node* right;
   Node* parent;
    ll data;
    Node(ll val)
    {
        data = val;
    }
    Node()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};
void PrintTree(Node* root){

}
//AIM: Print a tree in its true visual form given the root pointer only
void MakeTree(Node *root, vll &a)
{
    if (a.empty())
        return;
    root->data = a[0];
    a.erase(a.begin());
    ll n = a.size();
    vll b(a.begin(), a.begin() + n / 2);
    if(!b.empty())
     root->left = new Node;
    vll c(a.begin() + n / 2, a.end());
    if(!c.empty())
        root->right = new Node;
    MakeTree(root->left,b);
    MakeTree(root->right, c);
    return;
}
int main()
{
    ll n;
    cin >> n;
    vll a(n);
    F(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());
    Node *root = new Node;
    MakeTree(root,a);
    PrintTree(root);
    return 0;
}
