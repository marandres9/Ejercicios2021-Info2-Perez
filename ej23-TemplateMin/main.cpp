#include <iostream> 

template <class T>
T min(T a=3, T b=5) {
    return a<b ? a : b;
}

int main() {
    std::cout << min(int(2)) << std::endl;
    std::cout << min(5.2) << std::endl;
    
    return 0;
}