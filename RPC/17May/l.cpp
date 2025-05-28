#include <bits/stdc++.h>
using namespace std;

multiset<int> L;
multiset<int> R;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

    
void add(int e) {
    if (L.empty()) {
        L.insert(e);
    }
    else if (R.empty()) {
        int mn = *L.rbegin();
        if (mn <= e) R.insert(e);
        else {
            L.extract(mn);
            R.insert(mn);
            L.insert(e);
        }
    }
    else {
        int mn = *L.rbegin();
        if (L.size() == R.size()) {
            int last = *R.begin();
            if (e <= last) {
                L.insert(e);
            }
            else {
                R.extract(last);
                L.insert(last);
                R.insert(e);
            }
        }
        else {
            int heap = *L.rbegin();
            if (e >= heap) {
                R.insert(e);
            }
            else {
                L.extract(heap);
                R.insert(heap);
                L.insert(e);
            }
        }
    }
}

void del(int e) {
    if (!L.count(e) && !R.count(e)) return;
    if (L.size() == R.size()) {
        int last = *R.begin();
        if (e >= last) R.extract(e);
        else {
            L.extract(e);
            L.insert(last);
            R.extract(last);
        }
    }
    else {
        int heap = *L.rbegin();
        if (e <= heap) L.extract(e);
        else {
            R.extract(e);
            L.extract(heap);
            R.insert(heap);
        }
    }
}

void query() {
    int len = L.size() + R.size();
    if (len == 0) {
        cout << "Empty!\n";
    } 
    else {
        if (len & 1) {
            cout << *(--L.end()) << "\n";
        }
        else {
            assert(!R.empty());
            int a = *(--L.end());
            int b = *(R.begin());
            cout << (a + b) / 2 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            add(x);
        }
        else if (op == 2) {
            int x;
            cin >> x;
            del(x);
        }
        else {
            query();
        }
    }
    return 0;
}
