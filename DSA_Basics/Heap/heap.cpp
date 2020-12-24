#include <bits/stdc++.h>
#include "pretty_print.h"
using namespace std;

#define ll long long
#define vll vector<ll>

//AIM: Implement Heap using array
//Heap class

class heap
{
public:
    vll array;
    ll end = array.size() - 1;
    void Heapify(ll j);
    void Build_Heap(vll input);
    ll Extract_min();
    void Delete_min();
    void Delete(ll j);
    void Decrease_key(ll j, ll val);
    void Insert(ll val);
};

void heap::Heapify(ll j)
{
    //out of range
    if (j > end)
    {
        cout << "Index out of range" << endl;
        return;
    }
    //swap with the minimum
    ll t = j;
    if (2 * j + 1 <= end && array[2 * j + 1] <= array[j])
        t = 2 * j + 1;
    if (2 * j + 2 <= end && array[2 * j + 2] <= array[t])
        t = 2 * j + 2;
    //already a heap then return;
    if (t == j)
        return;
    //Otherwise swap with minimum and then fix new node
    swap(array[j], array[t]);
    Heapify(t);
    // pretty_print(array,INF);
    return;
}

void heap::Build_Heap(vll input)
{
    //assignment
    array = input;
    end = input.size() - 1;
    //Start from end
    for (int i = end; i >= 0; i--)
    {
        Heapify(i);
        // pretty_print(array,INF);
    }
    return;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    heap test;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        test.Build_Heap(a);

        //Visualisation part
        // for (auto x : test.array)
        // {
        //     cout << x << " ";
        // }
        pretty_print(test.array,INF);
    }
    return 0;
}
