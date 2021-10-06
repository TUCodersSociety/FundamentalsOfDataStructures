// Given 2 strings, write a method to decide of one is a permutation of the other

#include <iostream>
#include <string>
#include <string.h>

bool isPermutation(std::string, std::string);

int main () {
    std::string str1, str2; 

    std::cout << "String 1: ";
    getline(std::cin, str1);

    std::cout << "String 2: ";
    getline(std::cin, str2);

    if (isPermutation(str1, str2)) {
        std::cout << str2 << " is the permutation of " << str1 << "\n";
    }
    else {
        std::cout << str2 << " is not the permutation of " << str1 << "\n";
    }
}

bool isPermutation(std::string str1, std::string str2)  {
    int len = str1.length();
    if (len != str2.length()) {
        return false;
    }

    for (int i = 0; i < len; i++) 
    {
        static bool found = false;
        for (int j = 0; j < len && !found; j++) 
        {
            if (str1[i] == str2[j]) 
            {
                str2[j] = '\0';
                found = true;
            }
        }
        if (!found) {
            return false;
        }
    }

    return true;
}