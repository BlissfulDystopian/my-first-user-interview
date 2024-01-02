#include <iostream>
#include <vector>
#include <string>
#define ZEROS 48

// String to int
int stringToInt(std::string num) {
    int result { 0 };
    for(char c: num) {
        result *= 10;
        result += c - ZEROS;
    }
    return result;
}

void printVec(const std::vector<std::string>& texts) {
    for(std::string text : texts) {
        std::cout << text << '\n';
    }
}

std::string parseNum(std::string text) {
    std::string res {""};
    for(char c : text) {
        if(c == ' ') break;
        res += c;
    }
    return res;
}
// Process vector
std::vector<std::string> procVec(std::vector<std::string> texts, int input) {
    std::vector<std::string> result , numbers, domain;
    std::string temp {""}, domTemp {""};
    bool isNumber = true;
    
    //initialize
    numbers.clear();
    domain.clear();

    // Parsing
    for(std::string s : texts) {
        isNumber = true;

        for(char c : s) {
            if(c == ' ') isNumber = false;

            if(isNumber) {
                temp += c;
            } else {
                domTemp += c;
            }
        }

        numbers.push_back(temp);
        domain.push_back(domTemp);
        temp = "";
        domTemp = "";
    }
    result.clear();
    
    // number calculation
    for(std::string s : numbers) {
        int x = stringToInt(s) * input;
        std::string str = std::to_string(x);
        result.push_back(str);
    }
    
    // merge result and domain
    for(int i = 0; i < result.size(); ++i) {
        result[i] += domain[i];
    }
    return result;
}

int main() {
    std::vector<std::string> ingredients;
    ingredients.clear();
    int input; 
    std::cin >> input;
    
    std::string temp;
    std::getline(std::cin, temp); // to dodge the first \n after cin above

    for(int i = 0; i < 3; i++) {
        std::getline(std::cin, temp); 
        ingredients.push_back(temp);
    }

    printVec(procVec(ingredients, input));

    return 0;
}
