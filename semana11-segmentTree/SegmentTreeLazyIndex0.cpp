#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define POT(x) ((x) * (x))
const ll MX2 = 2e3 + 2, MX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

ll combine(ll x, ll y, ll c = MOD) {
    // return ((x % c) + (y % c)) % c;
    return max(x, y); // ACA
}
ll sum_mod(ll a, ll b, ll c = MOD) {
    return ((a % c) + (b % c)) % c;
}
ll mult_mod(ll a, ll b, ll c = MOD) {
    return (((a % c) * (b % c)) % c);
}
ll pot_mod(ll a, ll b, ll c = MOD) {
    if (b == 0) {
        return 1 % c;
    }
    ll temp = pot_mod(a, b / 2, c);
    temp = (temp * temp) % c;
    if (b % 2 == 0) return temp;
    return (temp * (a % c)) % c;
}

struct SegmentTree {
    ll t[2 * MX];
    ll lazy[2 * MX];
    ll n;

    void clear(ll n) {
        for (ll i = 0; i < 2 * n; i++) {
            t[i] = 0;
            lazy[i] = 0;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        lazy[id] = 0;
        if (tl == tr) {
            t[id] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 0, n - 1);
    }

    void push(ll id, ll tl, ll tr) { // O(1)
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        ll szLeft = tm - tl + 1;
        ll szRight = tr - tm;
        // Apply the lazy value of the node to the children
        // t[left] = sum_mod(t[left], mult_mod(lazy[id], szLeft));
        t[left] += sum_mod(t[left], lazy[id]); // ACA
        // t[right] = sum_mod(t[right], mult_mod(lazy[id], szRight));
        t[right] += sum_mod(t[right], lazy[id]); // ACA
        // Aggregate the lazy value
        lazy[left] = sum_mod(lazy[left], lazy[id]);
        lazy[right] = sum_mod(lazy[right], lazy[id]);

        // Restart the lazy value
        lazy[id] = 0;
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        push(id, tl, tr);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 0, n - 1);
    }

    void update(ll l, ll r, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            ll sz = tr - tl + 1;
            // Apply the lazy value
            // t[id] = sum_mod(t[id], mult_mod(val, sz));
            t[id] = sum_mod(t[id], val); // ACA
            // Aggregate the lazy value
            lazy[id] = sum_mod(lazy[id], val);
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            push(id, tl, tr);
            update(l, r, val, left, tl, tm);
            update(l, r, val, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void update(ll l, ll r, ll val) {
        assert(n > 0);
        update(l, r, val, 1, 0, n - 1);
    }
} st;

int main() {
    inic;
    inic2;
    inic3;

    ll n;
    cin >> n;
    ll as = n;
    vector<ll> guardar;
    while (as--) {
        ll l;
        cin >> l;
        guardar.pb(l);
    }
    st.build(guardar);
    ll m;
    cin >> m;
    while (m--) {
        char c;
        cin >> c;
        if (c == 'u') {
            ll a, b, c;
            cin >> a >> b >> c;
            st.update(a, b, c);
        } else {
            ll a, b;
            cin >> a >> b;
            cout << st.query(a, b) << endl;
        }
    }

    return 0;
}
