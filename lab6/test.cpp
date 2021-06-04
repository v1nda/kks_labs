#include <iostream>

#include "includes/finite_state_machine_alg.h"
#include "includes/rabin_karp_alg.h"

void print_vector(std::vector<u_int> &vec)
{
        for (auto i : vec)
        {
                std::cout << i << " ";
        }
        std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
        std::vector<std::vector<char>> sigma = {
                {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',\
                'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
                {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',\
                'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ',', ' '},
                {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
                {' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', '`', '-', '.',\
                '/', ':', ';', '^'}
        };

        std::vector<std::string> str = {
                "abcdfkjklolkilervbkjkkjkafbkjkjklabd",
                "now in this line, according to the algorithms that smart people have come up with, and I have implemented, substrings will be found",
                "1126781982366111234576",
                "!!#$%&*&^%$#$%##+++*#$%-:^)"
        };

        std::vector<std::string> substr = {
                "kjk",
                ", ",
                "112",
                ":^)"
        };

        for (auto i = 0; i < sigma.size(); i++)
        {
                std::cout << "==== " << i + 1 << " test ====" << std::endl;

                std::cout << "[Alphabet] <";
                for (auto c : sigma[i])
                {
                        std::cout << c;
                }
                std::cout << ">" << std::endl;

                std::cout << "[String] <" << str[i] << ">" << std::endl;
                std::cout << "[Substring] <" << substr[i] << ">" << std::endl;

                std::cout << std::endl;

                std::vector<u_int> indexes;

                std::cout << "[Finit-state machine algorithm]" << std::endl;
                std::cout << "Occurrence indexes > ";

                indexes = finite_state_machine(sigma[i], str[i], substr[i]);
                print_vector(indexes);
                std::cout << std::endl;

                std::cout << "[Rabin-Kapr ><> algorithm]" << std::endl;
                std::cout << "Occurrence indexes > ";

                indexes = finite_state_machine(sigma[i], str[i], substr[i]);
                print_vector(indexes);
                std::cout << std::endl;

        }

        std::cout << "Done." << std::endl;

        return 0;
}
