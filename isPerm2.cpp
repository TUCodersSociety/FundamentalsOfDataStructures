#include <iostream>
#include <string>


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

bool isPermutation(std::string str1, std::string str2) {
    int str1Length = str1.length();
    int str2Length = str2.length();
    if (str1Length != str2Length) {
        return false;
    }

    int charArr[128];
    for (int i = 0; i < 128; i++) {
        charArr[i] = 0;
    }

    int strIndex;
    for (int i = 0; i < str1Length; i++)  {
        strIndex = (int)str1[i];
        charArr[strIndex]++;
    }

    for (int i = 0; i < str2Length; i++) {
        strIndex = (int)str2[i];
        charArr[strIndex]--;

        if (charArr[strIndex] < 0) {
            return false;
        }
    }

    for (int i = 0; i < str2Length; i++) {
        if (charArr[i] != 0) {
            return false;
        }
    }

    return true;
}