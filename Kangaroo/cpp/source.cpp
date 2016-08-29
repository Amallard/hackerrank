#include <iostream>
using namespace std;

int main(){
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    
    // If one kangaroo is behind the other AND moving slower, 
    //    he/she will never catch up to the other one
    if ((x1 < x2) && (v1 < v2)) cout << "NO";
    else if ((x2 < x1) && (v2 < v1)) cout << "NO";
        
    // Otherwise, move each kangaroo one jump at a time until 
    //     the one behind is no longer behind. 
    else {
        if (x1 < x2) {
            while (x1 < x2) {
                x1 += v1;
                x2 += v2;
            }
        } else {
            while (x2 < x1) {
                x1 += v1;
                x2 += v2;
            }
        }
        
        // Once he/she is no longer behind the other, check to see
        //    if he/she is in the same position, or if he/she has passed
        if (x1 == x2) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
