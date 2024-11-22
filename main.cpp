
/*
MIT License

Copyright (c) 2024 Youssef Belahmar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "hash_library.h"



std::string to_hex(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << value;
    return ss.str();
}

std::string pad_hash(const std::string& hash_code) {
    std::string padded_hash = hash_code;
    padded_hash.resize(10, '0'); // Pads or truncates to ensure length is 10
    return padded_hash;
}

int main() {
    std::ifstream file("Path to you json file");
    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    file.seekg(0, std::ios::end);
    std::ifstream::pos_type fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> bytes(fileSize);
    file.read(bytes.data(), fileSize);
    file.close();

    std::string content(bytes.begin(), bytes.end());

    auto start_time = std::chrono::high_resolution_clock::now();
    uint32_t numeric_hash = simple_hash(content.data(), content.size());
    std::string hex_hash = to_hex(numeric_hash);
    std::string final_hash = pad_hash(hex_hash);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Hash Result: " << final_hash << std::endl;
    std::cout << "Time Taken: " << duration << " milliseconds" << std::endl;

    return 0;
}
