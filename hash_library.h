//
// Created by Youssef Belahmar on 22/11/2024.
//

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

#ifndef HASH_LIBRARY_H
#define HASH_LIBRARY_H

#include <cstddef>  // For size_t
#include <cstdint>  // For uint32_t

// Declaration of the hashing functions
extern "C" {
/**
 * Computes a simple hash (FNV-1a algorithm) for a given data buffer.
 *
 * @param data Pointer to the data to be hashed.
 * @param length Length of the data in bytes.
 * @return A 32-bit hash value.
 */
uint32_t simple_hash(const char* data, size_t length);

/**
 * Converts a hash value to its hexadecimal string representation.
 *
 * @param hash_value The 32-bit hash value.
 * @param output A buffer where the hexadecimal string will be stored.
 * @param buffer_size The size of the output buffer.
 */
void hash_to_hex(uint32_t hash_value, char* output, size_t buffer_size);
}

#endif // HASH_LIBRARY_H
