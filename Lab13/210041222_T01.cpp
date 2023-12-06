#include<bits/stdc++.h>
#include<cassert>
using namespace std;
#define NDEBUG
#define ll long long
/*
    Only 3 functions to modify: 
    1. combine()
    2. apply
    3. combineUpdate()
*/
template<class T, class U>
class Lsegtree{
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;

    /*
        List of identity element:
        sum: 0
        max: -INF
        min: INF
        XOR: 0
    */
    public:
    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n,identity_element);
        lazy.assign(4*n, identity_update);
    }
    T combine(T l, T r)
    {
        T ans = (l + r); // sum
        // T ans = max(l, r); // max
        // T ans = min(l, r); // min
        // T ans = __gcd(l, r); // gcd
        return ans;
    }
    void buildUtil(ll v, ll tl, ll tr, vector<T> &a)
    {
        if(tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }
    T apply(T curr, U upd, ll tl, ll tr) // What we are quering is needs to be stored in the answer
    {
        // /*sum query*/
        T ans = (tr-tl+1)*upd; // range update (replace with new value)
        // T ans = cur + (tr-tl+1)*upd; // range increment(increment value)
        // /*max query*/
        // T ans = upd; // range update (replace with new value)
        // /*min query*/
        // T ans = upd; // range update (replace with new value)
        return ans;
    }
    // Part of lazy propagation and pushing down lazy value to its children
    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        U ans = new_upd;         // Replacing new value in a range
        // U ans = old_upd+new_upd; // Adding new value in a range
        return ans;
    }  
    void push_down(ll v, ll tl, ll tr)
    {
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if(2*v + 2 < 4*n)
        {
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        if(tr < l or tl > r)
        {
            return identity_element;
        }
        if(l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
 
    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v,tl,tr); 
        if(tr < l or tl > r)return;
        if(tl >=l and tr <=r)
        {
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        }
        else
        {
            ll tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }
    void build(vector<T> a)
    {
        // assert(sz(a) == n);
        buildUtil(0,0,n-1,a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0,0,n-1,l,r);
    }
    void update(ll l,ll r, U upd)
    {
        updateUtil(0,0,n-1,l,r,upd);
    }
};


int main(){
    ll n, q;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    Lsegtree<ll, ll> tree(n+1, 0, -1); // Identity Update for build is -1
    tree.build(a);
    ll k, x, y;
    while(q--){
        cin>>k>>x>>y;
        if(k==1){
            tree.update(x, x, y);
        }else{
            cout<<tree.query(x, y);
        }
    }
    return 0;
}