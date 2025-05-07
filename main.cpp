#include "include/Knight.hpp"
#include "include/HighOrc.hpp"

int main() {
    Knight arthur("Arthur");
    HighOrc grok(5);

    arthur.basic_attack(grok);
    grok.basic_attack(arthur);

    return 0;
}