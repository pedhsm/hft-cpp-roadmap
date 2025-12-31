#include <iostream>

int buffer[1024]; 

int main() {
    int* block_A = buffer; 
    int* block_B = block_A + 256; 
    int* block_C = block_B + 256; 

    block_A[0] = 10;   // Escreve no buffer[0]
    block_B[0] = 20;   // Escreve no buffer[256]
    block_C[0] = 30;   // Escreve no buffer[512]

    std::cout << "Valor em A: " << buffer[0] << "\n";     // 10
    std::cout << "Valor em B: " << buffer[256] << "\n";   // 20
    std::cout << "Valor em C: " << buffer[512] << "\n";   // 30

    return 0;
}