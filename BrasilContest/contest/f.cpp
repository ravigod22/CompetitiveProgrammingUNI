#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
        int n,f,s;
        cin >> n >> f >> s;
        vi p(n+1),q(n+1);
        vi tp(n+1),tp_(n+1);
        vi tq(n+1),tq_(n+1);
        vi vis(n+1,0);
        f(i,1,n+1){
                cin >> p[i];
                tp[p[i]] = i;
                tp_[i] = p[i];
        }
        f(i,1,n+1){
                cin >> q[i];
                tq[q[i]] = i;
                tq_[i] = q[i];
        }
        ll ans = (1ll<<62);
        f(i,1,n+1)if(!vis[i]){
                int in_p_o = i;
                int in_q_o = tq[p[i]];
                int pt_o = i;
                int qt_o = tq[p[i]];
                while(pt_o + 1 <= n and qt_o + 1 <= n and p[pt_o + 1] == q[qt_o+1]){
                        pt_o++;
                        qt_o++;
                        vis[pt_o] = 1;
                }
                ll cost = max((in_p_o -1 + in_q_o-1)*1ll*f , (n-pt_o + n - qt_o)*1ll*s);
                ans = min (ans,cost);
        }
        cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
