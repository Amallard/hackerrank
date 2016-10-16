/*
    I am using C++, and since strings are immutable, 
    what I decided to do was to create two int arrays (vectors actually) 
    that hold the ascii val of the chars in each string. 
    Then I would sort the vectors. Then I would iterate through the arrays together, 
    counting the number of elements that don't exist in the other.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int calcDeletions(vector<int> a, vector<int> b) {

    int deletions = 0;
    int ai = 0;
    int bi = 0;

    // step through arrays until the end of one is reached
    while (ai < a.size() && bi < b.size()) {
        if (a[ai] < b[bi]) {
            deletions++;
            ai++;
        }
        else if (a[ai] > b[bi]) {
            deletions++;
            bi++;
        }
        else {
            ai++;
            bi++;
        }
    }

    // carry over left-overs
    deletions += (a.size() - ai);
    deletions += (b.size() - bi);

    return deletions;
}

int number_needed(string a, string b) {
    vector<int> aInt;
    vector<int> bInt;

    // create two int vectors to store ascii val of strings
    for (int i = 0; i < a.length(); i++) {
        aInt.push_back((int)a.at(i));
    }
    for (int i = 0; i < b.length(); i++) {
        bInt.push_back((int)b.at(i));
    }

    // sort vectors
    sort(aInt.begin(), aInt.end());
    sort(bInt.begin(), bInt.end());

    // call calcDeletions function with the longer vector passed as first arg
    if (aInt.size() > bInt.size()) {
        return calcDeletions(aInt, bInt);
    }
    else {
        return calcDeletions(bInt, aInt);
    }
}

int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;

    cout << number_needed(a, b) << endl;
    return 0;
}
