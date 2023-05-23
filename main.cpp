#include "includes/imports.h"
int main() {
    setlocale(LC_ALL, "Polish");
    std::string test = "lol";
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Tu bêdzie majn ale jeszcze ni ma XDD!" << std::endl;
    Engine game(1280, 720, 60, "To the T0p!");

    return 0;
}
