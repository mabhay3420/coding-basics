#include <bits/stdc++.h>
#include "../heap/pretty_print.h"
using namespace std;

/**
  @author Abhay mishra
  @date   January 16 2021
  "Implementation of range min/max Segment Tree."
  
  https://codeforces.com/contest/1473/problem/D

  You are given a program that consists of n instructions.
  Initially a single variable x is assigned to 0. Afterwards,
  the instructions are of two types:

  + : increase x by 1;
  - : decrease x by 1;

  You are given m queries of the following format:

  query l r — how many distinct values is x assigned to if all 
        the instructions between the l-th one and the r-th one inclusive 
        are ignored and the rest are executed without changing the order?
    
  Input constrains : 1<=t<=1000 , 1<=n,m<=2.10^5, 1<=l<=r<=n 
                     sum of n over all test cases do not exceed 2.10^5

  NOTE: This is not an efficient solution of the 
  problem (---O(mlog(n)) + O(n)---- time complexity).
  This can be solved in O(n+m). If the queries
  were minimum and maximum value of a general segment 
  then it would have been an efficient solution.
  I used it as an opportunity to learn something new.

 */

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

//*THE RESULT DOESN'T MATTER.....ITS ALL ABOUT YOUR EFFORTS.
/* ~ Ignore
*Hello world
_hello world
!Hello world
?Hello world
AIM: Hello world
TODO: Hello world
DOUBT: Hello world
*/

/**
 * Calcultes greatest Common divison using Euclid's division Lemma
 * 
 * @param   a,b Input numbers whose gcd is to be calculated
 * @returns GCD of a and b
 */
ll gcd(ll a, ll b)
{
    return (b ? gcd(b, a % b) : a);
}
const ll MAX_PRIME = 1e9 + 7;
// const ll INF = 1e18+1;
const pll EXTREMA = make_pair(INF, -INF);
/**
 * Calculates (x^y)%z Using Binary Exponentiation . Similar to pow(x,y,z) function of python
 * 
 * @param   x,y Input numbers
 * @param   z if not specified default to 1e18
 * @returns pow(x,y) modulo z
 */
ll fast_pow(ll x, ll y, ll z = INF)
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
///////////////////~HERE WE GO~///////////////////
/**
 * Get the middle element given start and end index
 */
ll getMiddle(ll start, ll end)
{
    return start + (end - start) / 2;
}
/**
 * Utility function for constructing Segment tree 
 * 
 * @param   a Input array from which segment tree will be constructed
 * @param   in_start starting index of segment being considered
 * @param   in_end end index of segment being considered
 * @param   st Segment Tree to be constructed
 * @param   curr_index Current index of Array associated with segment tree which is to be filled.
 * @returns optional: The value filled in st[curr_index] in this step
 */
pll constructSTUtil(vll a, ll in_start, ll in_end, vpll &st, ll curr_index)
//pass vector by reference otherwise only a copy of vector is passed and the changes are not
//stored properly
{
    /**
     * If a single element we can directly 
     * calculate the min and max
     */

    if (in_start == in_end)
    {
        st[curr_index] = make_pair(a[in_start], a[in_start]);
        return st[curr_index];
    }

    /**
     * Construct Current Node by using Left and right Childs
     * left child is at st[2*curr_index + 1] and right one at st[2*curr_index + 2]
     */

    ll mid = getMiddle(in_start, in_end);
    pll left_child = constructSTUtil(a, in_start, mid, st, 2 * curr_index + 1);
    pll right_child = constructSTUtil(a, mid + 1, in_end, st, 2 * curr_index + 2);

    /**
     * First element of pair contains minimum value in whole segment 
     * and second element contains maximum value.
     */

    st[curr_index].ff = min<ll>(left_child.ff, right_child.ff);
    st[curr_index].ss = max<ll>(left_child.ss, right_child.ss);

    return st[curr_index];
}

/** Constructs Segment Tree for given Array
 * 
 * @param   a input array
 * @param   n size of input array
 * @returns an array which represent required Segment tree
 */
vector<pll> constructSt(vll a, ll n)
{
    /**
     * Form an array with Enough Space to
     * contain segment tree
     */

    ll h = (ll)ceil(log2(n)) + 1;     //max height of tree
    ll max_size = fast_pow(2, h) - 1; //max no of nodes
    vpll st(max_size, EXTREMA);       //flag_min = INF and flag_max = -INF

    //utility function

    constructSTUtil(a, 0, n - 1, st, 0);

    return st;
}

/**
 * Utility function for getting information stored in 
 * Segment Tree corresponding to query Segment.
 * 
 * @param   st Array representing segment Tree
 * @param   seg_start current segment starting index
 * @param   seg_end current segment ending index
 * @param   q_start query segment starting index
 * @param   q_end query segment ending index
 * @param   t_index Index representing segment being 
 *          studied in Array (Which in turn represents Segment Tree).
 * @returns Value stored in current segment which is relevant
 *          for query segment.
 * 
 *          for e.g. If we want sum of all value in query segment         
 *          then if the current segment is completely inside the segment,         
 *          it will return sum of all values in the current segment , if         
 *          it is completely outside it will return 0 and if it is overlapping         
 *          it will recursively calculate the sum of only those values which         
 *          are in query segment and return the sum.         
*/
pll getValUtil(vpll st, ll seg_start, ll seg_end, ll q_start, ll q_end, ll t_index)
{

    if (q_start <= seg_start && q_end >= seg_end) //segment is completely inside
    {
        return st[t_index];
    }
    if (q_start > seg_end || q_end < seg_start) // segment is completely outside
    {
        return EXTREMA;
    }
    //segment is overlapping
    ll mid = getMiddle(seg_start, seg_end);

    pll left_child = getValUtil(st, seg_start, mid, q_start, q_end, 2 * t_index + 1);
    pll right_child = getValUtil(st, mid + 1, seg_end, q_start, q_end, 2 * t_index + 2);

    //only relevant details flow upwards because we return EXTREMA for irrevalant segments
    pll parent;
    parent.ff = min<ll>(left_child.ff, right_child.ff);
    parent.ss = max<ll>(left_child.ss, right_child.ss);

    return parent;
}

/**
 * Main Function for getting value corresponding to a query
 * 
 * @param   st array representing Segment Tree
 * @param   l left index of query segment
 * @param   r right index of query segment
 * @param   n size of input array from which segment tree was constructed
 * @returns Required information stored in Segment Tree corresponding to segment l->r
 */
pll getVal(vpll st, ll l, ll r, ll n)
{
    //Invalid input
    if (l > r || l < 0 || r > n - 1)
    {
        cout << "INVALID" << endl;
        return EXTREMA;
    }
    return getValUtil(st, 0, n - 1, l, r, 0);
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    godspeed
        ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vll a(n + 1);
        a[0] = 0; //initial value
        string steps;
        cin >> steps;
        F(i, 1, n + 1)
        {
            if (steps[i - 1] == '+')
                a[i] = a[i - 1] + 1;
            else
                a[i] = a[i - 1] - 1;
        }

        vpll seg_tree = constructSt(a, n + 1);

        /**
         * Visualization Start Here
         */
        cout<<"The intermediate numbers if all Instruction are carried Out:"<<endl;
        cout_array(a);
        vll a_min, a_max;
        for (auto comb : seg_tree)
        {
            a_min.push_back(comb.ff);
            a_max.push_back(comb.ss);
        }
        cout << "*************** Minimum of a segment **************" << endl;
        pretty_print(a_min, INF);
        cout << "*************** Maximum of a segment **************" << endl;
        pretty_print(a_max, -INF);

        /**
         * Visualization Ends here
         */

        cout << "No of Unique Values Attained If You Do not Perform :" << endl;
        F(i, 0, m)
        {
            ll l, r;
            cin >> l >> r;
            pll left_peak = getVal(seg_tree, 0, l - 1, n + 1);
            if (r != n) //otherwise we only have left segment
            {
                pll right_peak = getVal(seg_tree, r + 1, n, n + 1);
                right_peak.ff -= a[r] - a[l - 1];
                right_peak.ss -= a[r] - a[l - 1];
                left_peak.ff = min<ll>(left_peak.ff, right_peak.ff);
                left_peak.ss = max<ll>(left_peak.ss, right_peak.ss);
            }
            // No of Unique values is determined by Minimum
            // and Maximum values as the results are continuous
            if (l != r)
                cout << "steps from " << l << " to " << r << " : ";
            else
                cout << "step " << l << " : ";
            cout << left_peak.ss - left_peak.ff + 1 << endl;
        }
    }
    return 0;
}