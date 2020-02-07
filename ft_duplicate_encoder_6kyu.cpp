/*  
Problem: 
The goal of this exercise is to convert a string to a new string where each character 
in the new string is "(" if that character appears only once in the original string, 
or ")" if that character appears more than once in the original string. Ignore 
capitalization when determining if a character is a duplicate.

Examples:
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 

Problem Notes:
Assertion messages may be unclear about what they display in some languages. If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!

Origin:
6 Kyu, CodeWars.

Notes:
Can still be refactor to simplify logic. Check the other cleaner solution!

Time to Solve:
~2 hours. 2/6/20
*/

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
