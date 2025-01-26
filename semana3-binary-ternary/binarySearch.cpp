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
ll target;
ll f(ll x) {
    return x * x + 3 * x + 5;
}
double f2(double x_0) {
    return x_0 * 3.0 / 3.2;
}
int main() {
    cin >> target;
    // Primer elemento mayor o igual al target
    ll ini = 1, fin = 100;
    while (ini < fin) { // O(LOG(N))
        ll med = (ini + fin) / 2;
        if (f(med) < target) {
            ini = med + 1;
        } else {
            fin = med;
        }
    }
    if (f(ini) >= target) {
        cout << ini << endl;
    } else {
        cout << "no existe respuesta" << endl;
    }
    // Ultimo elemento menor o igual al target
    ll ini2 = 0, fin2 = 100;
    while (ini2 < fin2) { // O(LOG(N))
        ll med = (ini2 + fin2 + 1) / 2;
        if (f(med) <= target) {
            fin2 = med - 1;
        } else {
            ini2 = med;
        }
    }
    if (f(ini2) <= target) {
        cout << ini2 << endl;
    } else {
        cout << "no existe respuesta" << endl;
    }

    // Busqueda binaria continua
    ll n2, target2;
    cin >> n2 >> target2;
    ll iteraciones = 80;
    double ini2 = 1, fin2 = n2;
    // for (ll i = 1; i <= iteraciones; i++) {
    while (fin2 - ini2 >= 1e6) {
        double med2 = (ini2 + fin2) / 2;
        if (f2(med2) < target) {
            ini2 = med2;
        } else {
            fin2 = med2;
        }
    }
    if (f2(ini2) >= target2) {
        cout << ini2 << endl;
    } else {
        cout << "No hay respuesta" << endl;
    }
    return 0;
}
