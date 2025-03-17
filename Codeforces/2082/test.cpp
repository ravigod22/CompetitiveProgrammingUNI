#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    cout << arr[1000];  // Acceso fuera del rango del array -> Segfault
    return 0;
}

