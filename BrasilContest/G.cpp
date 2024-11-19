#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int INF = 1e9;
const int MAXN = 1e6+5;

ll FT[ MAXN ]{};
ll getFT (int b){
    ll v = 0;
    for (int x = b; x; x -= x & -x) v += FT[x];
    return v;
}
void setFT (int p, int v) {
    for (int x = p; x < MAXN; x += x & -x) FT[x] += v;
}
ll get (int a) { return getFT(a);}
void update (int l, int r, int v) { setFT(l, v); setFT(r+1, -v);}

int FT2[ MAXN ]{};
int getFT2 (int b){
    int v = 0;
    for (int x = b; x; x -= x & -x) v += FT2[x];
    return v;
}
void setFT2 (int p, int v) {
    for (int x = p; x < MAXN; x += x & -x) FT2[x] += v;
}
int get2FT (int a) { return getFT2(a);}
void updateFT2 (int l, int r, int v) { setFT2(l, v); setFT2(r+1, -v);}


void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        update(l, r, v);
        updateFT2(l, r, 1);
    }
    ll xam = 0;
    for (int i = 1; i < MAXN; i++) {
        if(get2FT(i) <= k) {
            xam = max(xam, getFT(i));
        }
    }
    cout << xam << endl;
}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

