#include <string>
#include <utility>

std::pair<std::string, std::string> capitalize(const std::string &s)
{
    std::string a = s;
    std::string b = s;
    for (int i = 0; i < s.length(); i+=2){
        a[i] = std::toupper(a[i]);
        b[i+1] = std::toupper(b[i+1]);
    }
    return {a, b};
}
