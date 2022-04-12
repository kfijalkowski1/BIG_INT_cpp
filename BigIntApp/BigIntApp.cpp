#include <iostream>

int silnia(int n) {
    int i = 0;
    int wyn = 1;
    while (i < n) {
        wyn *= ++i;
    }
    return wyn;
}

int main()
{
    int x = silnia(2);
    std::cout << x;
}