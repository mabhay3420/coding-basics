#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define deb(x) cout << #x << " = " << x << endl
#define F(i, m, n) for (ll i = m; i < n; i++)
#define cout_array(a) for(auto x : a)cout << x << " "; cout << endl

int main()
{
    ll n;
    cout << "Please input the no of rows in Required Magic Squre:";
    cin >> n;
    //Program needs odd no of rows
    while (n % 2 == 0)
    {
        cout << "Please input Odd no of rows :";
        cin >> n;
    }
    vector<vll> a(n, vector<ll>(n, 0));
    //Initialize variables and 
    ll fill_val = 1;
    pll curr_index; //Proposed next index decided from last index visited
    pll last_index = make_pair(0, (n - 1) / 2); //move to middle of first row

    // complete the first step.
    a[last_index.ff][last_index.ss] = fill_val;
    fill_val += 1;

    //for handling the case when the we are at corner
    pll corner = make_pair(0, n - 1);


    //Start checking for each index--total n^2-1 index yet to fill.
    //TODO : Can we optimize the code
    F(j, 0, n * n - 1)
    {
        //diagonal case
        if (last_index == corner)
        {
            last_index.ff += 1;
        }
        else
        {
            //calculate proposed next index
            curr_index.ff = last_index.ff - 1;
            curr_index.ss = last_index.ss + 1;

            //out of rows
            if (curr_index.ff < 0)
            {
                //move to last row
                curr_index.ff = n - 1;
            }

            //out of columns
            if (curr_index.ss > n - 1)
            {
                //move to first column
                curr_index.ss = 0;
            }

            //Check whether the proposed position is empty or not
            ll val = a[curr_index.ff][curr_index.ss];
            //not empty
            if (val != 0)
            {
                //place below the last placed value
                last_index.ff += 1;
            }
            //empty
            else
            {
                //we are done
                last_index = curr_index;
            }
        }
        //fill the value
        a[last_index.ff][last_index.ss] = fill_val;
        fill_val += 1;
    }

    //We are starting from 1
    cout << "Check The sum of Every row , column and diagonal is " << (n * (n * n + 1)) / 2 << endl;
    //TODO:find a better method to format the output in form of a Table which is flexible and more compact.
    for (auto v : a)
    {
        //borders
        cout<<"-";
        F(i, 0, n)
        {
            cout << "-------";
        }
        cout << endl;
        cout<<"|";
        for (auto x : v)
        {
            //centre align the numbers
            string s = to_string(x);
            ll p = 6-s.length();   //assuming the longest length of number is 6 --- can be changed.
            F(i, 0,p/2)
                cout << " ";
            cout << s;
            F(i,0,p-p/2)
            cout<<" ";
            //seprators
            cout << "|";
        }
        cout << endl;
    }
    F(i, 0, n)
    {
        cout << "-------";
    }
    cout << endl;
    return 0;
}