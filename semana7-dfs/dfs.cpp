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
vector<pair<ll, ll>> adj[MX];
bool usado[MX];
ll padre[MX], profundidad[MX], hijos[MX];
ll tiempo_entrada[MX], tiempo_salida[MX], cont = 0;
void dfs(ll nodo_actual, ll pap, ll prof) {
    cont++;
    tiempo_entrada[nodo_actual] = cont;
    usado[nodo_actual] = true;
    padre[nodo_actual] = pap;
    profundidad[nodo_actual] = prof;
    for (ll i = 0; i < adj[nodo_actual].size(); i++) {
        if (usado[adj[nodo_actual][i].first] == false) {
            dfs(adj[nodo_actual][i].first, nodo_actual, prof + 1);
            hijos[nodo_actual] += hijos[adj[nodo_actual][i].first];
        }
    }
    cont++;
    tiempo_salida[nodo_actual] = cont;
    hijos[nodo_actual]++;
}
bool esta_en_subarbol(ll nodo_a, ll nodo_b) {
    if (tiempo_entrada[nodo_a] < tiempo_entrada[nodo_b] &&
        tiempo_salida[nodo_a] > tiempo_salida[nodo_b]) {
        return true;
    }
    return false;
}
int main() {
    inic;
    inic2;
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dfs(1, -1, 1); // O(n+m)
    Rep1(i, n) {
        cout << "Hijos : " << i << " es: " << hijos[i] << endl;
    }
    return 0;
}