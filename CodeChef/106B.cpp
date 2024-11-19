#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int A[N];
int prefix[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        
        int count = 0;
        
        prefix[0] = (A[0] & 1);
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + (A[i] & 1);
        }

        for(int i = k - 1; i < n; i++){
            int tmp = (0 <= i - k) ? prefix[i - k] : 0;
            if(prefix[i] > tmp){
                count++;
            }
        }
        cout << count << '\n';
    }


    return 0;
}
