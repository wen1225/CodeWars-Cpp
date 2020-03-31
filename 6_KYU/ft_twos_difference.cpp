#include <vector>
#include <algorithm>
using vector_of_pairs = std::vector<std::pair<int, int>>;

vector_of_pairs twos_difference(const std::vector<int> &v){
    //(1)
    std::vector<int> copyOfV(v);
    std::sort(copyOfV.begin(), copyOfV.end());
     //(2)
    std::vector<std::pair<int, int>> a;
    for (unsigned i = 0; i < copyOfV.size(); i++){
        for (unsigned j = i; j < copyOfV.size(); j++){
            if (copyOfV[j] == copyOfV[i] + 2){
                std::pair<int, int> tmp(copyOfV[i], copyOfV[j]);
                a.push_back(tmp);
            }
        }
    }
    return a;
}

/*
    (1)
    Since v is a const, std::sort cannot be used. 
    Issue is resolved by copying it to a new vector, 
    copyOfV. Then, sort copyOfV.
    
    (2)
    Single nested loop to compare ith element with jth
    element. Group them as a pair when j > i by 2
    by pushing it into a (answer). Because push_back() 
    inserts elements to the end of a vector, it will
    be inserted in an ascending sequence since prior to 
    pushing, copyOfV is already sorted. So, elements are
    already being compared at an ascending order
    (small to big)
*/
