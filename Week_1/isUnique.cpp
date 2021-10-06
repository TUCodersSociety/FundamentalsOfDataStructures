// Time complexity: O(n*n)

#include <iostream>
#include <string> //for string data type
#include <cctype> //for tolower() func

bool isUnique (std::string);

int main (void) {
    std::string str;
    std::cout << "Please enter a string." << std::endl;
    getline(std::cin, str);

    std::string result = isUnique(str) ? "This string is unique" : "This string is not unique";
    std::cout << result << std::endl;
}

bool isUnique (std::string str) {
    int len = str.length();

    for(int i = 0; i <= len; i++) {
        str[i] = tolower(str[i]);
    }

    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if(str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}
    