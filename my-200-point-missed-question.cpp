#include <iostream>
#include <vector>

#define CHUNK 256
std::vector<int> calculateChunk(std::vector<int> chunks) {
    int size { 0 }, sum { 0 };
    std::vector<int> result;
    result.clear();

    for(int i : chunks) {
        if(!size) {
            size = i + 1;
        } else sum += i;
        
        
        if(size == 1) {
            // Calculate chunks
            result.push_back(sum % CHUNK);
            sum = { 0 };
        }
        --size;
    }
    return result;
}

void printVector(std::vector<int> vec) {
    std::cout << "[ ";
    for(int i : vec) { 
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::vector<int> chunks { 2, 250, 6, 5, 23, 43, 55, 21, 90 };

    printVector(calculateChunk(chunks));
    
    return 0;
}
