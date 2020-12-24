#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
const ll INF = 1e18 + 1;

ll w(ll h)
{
    return pow(2, h + 1) - 1;
}

void print_aux(vll A, ll flag,ll i, vector<string> &B, ll H, ll h, ll index, ll width)
{
    //if node is empty do nothing for that subtree
    if(A[i] == flag) return;
    //root assignment
    string s = to_string(A[i]);
    // string s2(' ',3-s.size());
    // s+=s2;
    ll j = 0;
    if (h == 0)
    {
        for (auto x : s)
        {
            B[index][width + w(h) - 1 + j] = x;
            j++;
        }
    }
    else
    {
        if (s.length() == 3)
        {
            j = -1;
        }
        for (auto x : s)
        {
            B[index][width + w(h) - 1 + j] = x;
            j++;
        }
    }
    // B[index][width + w(h) - 1] = char(A[i] + 48);
    index += 1;
    for (int j = 1; j <= w(h - 1); j++)
    {
        //first branch component
        if (2 * i + 1 < A.size())
            B[index][width + 2 * w(h - 1) - j] = '/';
        //second branch component
        if (2 * i + 2 < A.size())
            B[index][width + 2 * w(h - 1) + j] = '\\';
        //move to next line
        index += 1;
    }
    //if leaf return;
    if (h == 0)
        return;
    //left child
    if (2 * i + 1 < A.size())
    {
        print_aux(A, flag ,2 * i + 1, B, H, h - 1, index, width);
    }
    //right child
    if (2 * i + 2 < A.size())
    {
        print_aux(A, flag,2 * i + 2, B, H, h - 1, index, width + w(h) + 1);
    }

    return;
}

void pretty_print(vll input,ll flag)
{
    ll n = input.size();
    ll h = ceil(log2(n + 1) - 1);
    ll p = w(h);
    //define storage vector
    vector<string> B(p, string(2 * p - 1, ' '));
    //Call aux function to fill B
    print_aux(input, flag,0, B, h, h, 0, 0);
    //print values
    //_ When including file as header file function seems to alway start with 1st line
    //Start with new lines 
    cout<<endl;
    cout<<"---Array Representation---"<<endl;
    cout<<endl;
    for(auto x: input){
        if(x != flag)
        cout<<x<<" ";
        else cout<<"- ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"-----Visual Representation of Tree-----"<<endl;
    cout<<endl;
    for (auto x : B)
    {
        cout << x << endl;
    }
    cout << endl;
    return;
}

// int main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         vll a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         pretty_print(a);
//     }
//     return 0;
// }