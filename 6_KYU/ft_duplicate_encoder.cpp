#include <string>

std::string duplicate_encoder(const std::string& word){
    const int word_size = word.length();
    std::string word_filtered = "";
    std::string results = "";
    for (int i = 0; i < word_size; i++){
        word_filtered = word_filtered + char(std::tolower(word[i]));
    }
    
    for (int i = 0; i < word_size; i++){
        int counter = 0;
        for (int j = 0; j < word_size; j++){
            if (word_filtered[i] == word_filtered[j]){
                counter++;
            }
        }
        if (counter <= 1){
            results = results + "(";
        }
        else{
            results = results + ")";
        }
        
    }
    return results;
}
