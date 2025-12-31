#include <iostream>
using namespace std;

int count_x (const char *p,char x){
    if (p==nullptr) return 0;
    int count = 0;
    for(;*p!='\0';++p){
        if (*p == x){
            ++count;
        }
    }
    return count;
}

int count_array_size(const char *p){
    if (p ==nullptr) return 0;
    int size = 0;
    for(;*p != 0;++p){
        std::cout << (const void*)p;
        std::cout << *p;
        ++size;
    }
    return size;
}
int main() {
    const char* s = "Oi Ola Bao?";
    int size = count_array_size(s);
    int i = 0;
    while (i != size){
        std::cout<<i;
        ++i;
}
    int qtd_o = count_x(s,'o');
    std::cout<<qtd_o;
return 0;
}