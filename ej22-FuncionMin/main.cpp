#include <iostream> 

int min(int a=3, int b=5) {
    return a<b ? a : b;
}
float min(float a=3., float b=5.) {
    return a<b ? a : b;
}

int main() {
        
    std::cout << "Utilizando float: " << min(float(1.2)) << std::endl;

    std::cout << "Utilizando int: " << min(1, 2) << std::endl;
    
    return 0;
}