#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

ull getBit(ull x, ull i) {
    return (x >> i) & 1;
}
ll n, resp[52][52];
ll posis[52];
bool usado[52][52];
ll dp(ll pos, ll acciones) {
    if (acciones > n) {
        return -1e12;
    }
    if (usado[pos][acciones] == true) {
        return resp[pos][acciones];
    }
    usado[pos][acciones] = true;
    if (pos == 1) {
        if (acciones == 1) {
            return resp[pos][acciones] = (-posis[1]);
        }
        if (acciones == 0) {
            return 0;
        }
        return resp[pos][acciones] = (-1e12);
    }
    resp[pos][acciones] = dp(pos - 1, acciones);
    for (ll i = pos - 1; i >= 1; i--) {
        resp[pos][acciones] =
            max(resp[pos][acciones], (pos - i) * posis[pos] + dp(pos - 1, acciones + pos - i));
    }
    if (acciones > 0) {
        resp[pos][acciones] = max(resp[pos][acciones], dp(pos - 1, acciones - 1) - posis[pos]);
    }
    return resp[pos][acciones];
}

int main() {
    inic;
    inic2;

    cin >> n;
    Rep1(i, n) {
        cin >> posis[i];
    }
    cout << dp(n, 0) << endl;
    return 0;
}