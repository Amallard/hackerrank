#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    // Fill quantity variables
    long n, k, q;
    cin >> n >> k >> q;
    
    // Fill array
    vector <int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    // Optimize k
    while (k > n) {
        k = k - n;
    }

    // Fake the query index
    int query;
    for (int i = 0; i < q; i++) {
        cin >> query;
        if (query >= k) {
            cout << array[query - k] << endl;
        } else {
            cout << array[n - k + query] << endl;
        }
    }
    
    return 0;
}
