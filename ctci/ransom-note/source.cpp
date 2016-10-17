#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

bool ransom_note(std::vector<std::string> magazine, std::vector<std::string> ransom) {

    // map magazine words with frequency count
    std::map <std::string, int> mag;
    for (int i = 0; i < magazine.size(); ++i) {
        if (mag[magazine[i]]) ++mag[magazine[i]];
        else mag[magazine[i]] = 1;
    }
    
    // subtract ransom words from mag map, if ransom word is not in map return false
    for (int i = 0; i < ransom.size(); ++i) {
        if (!(mag[ransom[i]] && mag[ransom[i]] > 0)) return false;
        else --mag[ransom[i]];
    }
    
    return true;
    
}

int main(){
    int m;
    int n;
    std::cin >> m >> n;
    std::vector<std::string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       std::cin >> magazine[magazine_i];
    }
    std::vector<std::string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       std::cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    return 0;
}
