#include <iostream>
#include <string>
#include <cctype>

bool isUnique(std::string);

int main () {
    std::string str;
    std::cout << "Enter the string: ";
    getline(std::cin, str);

    bool result = isUnique(str);
    if (result) {
        std::cout << "The string is unique\n";
    }
    else {
        std::cout << "The string is not unique\n";
    }
}

bool isUnique(std::string str) {
    int len = str.length();
    if (len > 128) {
        return false;
    }

    bool char_set[128];
    for (int i = 0; i < 128; i++) {
        char_set[i] = false;

        //Case sensitive 
        if (i<len) { 
            str[i] = tolower(str[i]); 
        }
    }

    int currVal;
    for (int i = 0; i < len; i++) {
        currVal = (int)str[i];
        if (char_set[currVal]) {
            return false;
        } 
        char_set[currVal] = true;
    }
    return true;
}

// Time complexity: O(n), arguably O(1) since it never iterate over 128 characters
