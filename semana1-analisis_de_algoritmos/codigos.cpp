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

ull getBit(ull x, ull i) { // int
    return (x >> i) & 1;
}
vector<vector<ll>> vec5;
int main() {
    inic;
    inic2;
    ll t, c, c_location, ini, fin, med = 1;
    vector<ll> vec, vec2, vec3, vec4;
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(25);
    vec2.push_back(20);
    vec2.push_back(30);
    vec2.push_back(40);
    vec2.push_back(25);
    sort(vec.begin(), vec.end());            // O(N*LOG(N))
    upper_bound(vec.begin(), vec.end(), 30); // O(LOG(N)) Necesita estar ordenado
    lower_bound(vec.begin(), vec.end(), 30); // O(LOG(N)) Necesita estar ordenado
    reverse(vec.begin(), vec.end());         // O(N)
    ll n;
    cin >> n;
    ll cont = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j += i) { // n + n/2 + n/3 + n/4 + ... + n/n
            cont++;
        }
    }
    ll num;
    cin >> num;
    cout << ((num / 3) * (num / 3 + 1) / 2) * 3 + ((num / 5) * (num / 5 + 1) / 2) * 5 -
                ((num / 15) * (num / 15 + 1) / 2) * 15; // O(1)
    ll raiz = sqrt(num);
    return 0;
}