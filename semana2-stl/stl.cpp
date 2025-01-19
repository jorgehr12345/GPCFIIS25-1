#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 2e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

vector<ll> vec;
map<ll, ll> ma;
set<ll> se2;
multiset<ll> ms2;
deque<ll> dq;
stack<ll> st; // pila
queue<ll> qq; // cola
priority_queue<ll> pq;
int main() {
    inic;
    inic2;

    ma[20] = 30; // O(log(n))
    ma[40] = 150;
    ma[15] = 30;
    ma[20] = 12;
    for (map<ll, ll>::iterator it = ma.begin(); it != ma.end(); it++) {
        cout << (*it).first << " segundo el: " << (*it).second << endl;
    }
    set<ll, greater<ll>> se;
    se.insert(300);
    se.insert(200);
    se.insert(350);
    se.insert(300);
    for (set<ll>::iterator it2 = se.begin(); it2 != se.end(); it2++) {
        cout << (*it2) << endl;
    }
    if (se.find(300) != se.end()) { // O(log(N))
        cout << "No existe el 300" << endl;
    } else {
        cout << "Existe 300" << endl;
    }
    se.erase(250); // O(log(N))
    cout << "Primer elemento del set: " << *se.begin() << endl;
    se.clear(); // O(N)

    multiset<ll> ms;
    ms.insert(300);
    ms.insert(200);
    ms.insert(350);
    ms.insert(300);
    for (multiset<ll>::iterator it2 = ms.begin(); it2 != ms.end(); it2++) {
        cout << (*it2) << endl;
    }
    if (ms.find(300) != ms.end()) { // O(log(N))
        cout << "No existe el 300" << endl;
    } else {
        cout << "Existe 300" << endl;
    }
    ms.erase(250);          // O(N)
    ms.erase(ms.find(300)); // O(log(N))
    ms.erase(ms.find(300)); // O(log(N))
    for (multiset<ll>::iterator it2 = ms.begin(); it2 != ms.end(); it2++) {
        cout << (*it2) << endl;
    }

    dq.push_back(30);      // O(1)
    dq.push_front(300);    // O(1)
    cout << dq[0] << endl; // O(1)
    dq.pop_back();         // O(1) Eliminacion del ultimo
    dq.pop_front();        // O(1) Eliminacion del primero

    // LOWER_BOUND 1er elemento mayor o igual a
    cout << *(lower_bound(vec.begin(), vec.end(), 30)) << endl;
    cout << lower_bound(vec.begin(), vec.end(), 30) - vec.begin() << endl;
    cout << *(se.lower_bound(30)) << endl;

    // UPPER_BOUND 1er elemento mayor a
    cout << *(upper_bound(vec.begin(), vec.end(), 30)) << endl;
    cout << upper_bound(vec.begin(), vec.end(), 30) - vec.begin() << endl;
    cout << *(se.upper_bound(30)) << endl;

    string s;
    cin >> s;
    vector<char> emparejamientos;
    bool nocumple = false;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            emparejamientos.push_back(s[i]);
        } else {
            if (emparejamientos.size() > 0) {
                if (emparejamientos[emparejamientos.size() - 1] == '[' && s[i] == ']' ||
                    emparejamientos[emparejamientos.size() - 1] == '{' && s[i] == '}' ||
                    emparejamientos[emparejamientos.size() - 1] == '(' && s[i] == ')') {
                    emparejamientos.pop_back();
                } else {
                    cout << "NO" << endl;
                    nocumple = true;
                    break;
                }
            } else {
                cout << "NO" << endl;
                nocumple = true;
                break;
            }
        }
    }
    if (nocumple == false) {
        if (emparejamientos.size() == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    // Dado un string, devolver la palabra que más se repite
    string cadena;
    getline(cin, cadena);
    map<string, ll> respuestas;
    string temporal = "";
    for (ll i = 0; i < cadena.size(); i++) {
        if (cadena[i] != ' ') {
            temporal += cadena[i];
        } else {
            respuestas[temporal]++;
            temporal = "";
        }
    }
    respuestas[temporal]++;
    ll mayor = 0;
    for (map<string, ll>::iterator it = respuestas.begin(); it != respuestas.end(); it++) {
        mayor = max(mayor, (*it).second);
    }
    cout << mayor << endl;

    // Dado q queries, devolver el n fibonacci
    // O(q + pos)
    ll rps[20001];
    rps[0] = 1;
    rps[1] = 1;
    for (ll i = 2; i <= 20000; i++) {
        rps[i] = rps[i - 1] + rps[i - 2];
    }
    ll q;
    cin >> q;
    while (q--) {
        ll pos;
        cin >> pos;
        cout << rps[pos];
    }

    return 0;
}