#include <iostream>

#include "includes/finite_state_machine_alg.h"

int main(int argc, char const *argv[])
{
        std::vector<char> sigma = {'a', 'b', 'c', 'd'};
        std::string str = "aaaababababcabcbbac";
        std::string substr = "d";

        std::cout << "[Alphabet] ";
        for (auto i : sigma)
        {
                std::cout << i << " ";
        }
        std::cout << std::endl;

        std::cout << "[String] " << str << std::endl;
        std::cout << "[Substring] " << substr << std::endl;

        std::vector<u_int> indexes = state_machine(sigma, str, substr);
        for (auto i : indexes)
        {
                std::cout << i << " ";
        }
        std::cout << std::endl;

        return 0;
}
