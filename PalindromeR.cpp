#include "PalindromeR.hpp"

int PalindromeR::test_string(const std::string& s) {
    if (s.length() <= 1)
        return -1;
    else {
        if (s[0] == s[s.length() - 1]) {
            return test_string(s.substr(1, s.length()-2));
        } else {
            return 1;
        }
    }
}