#include "../includes/finite_state_machine_alg.h"

u_int suffix(std::string p, std::string s)
{
        u_int max = 0;
        bool flag = false;
        std::string prefix = "";

        for (auto i : p)
        {
                prefix += i;
                flag = true;
                for (auto j = 0; j < prefix.size(); j++)
                {
                        if (prefix[j] != s[s.size() - prefix.size() + j])
                        {
                                flag = false;
                        }
                }

                if (flag)
                {
                        max = prefix.size();
                }
        }

        return max;
}

std::vector<std::map<char, u_int>> table_building(std::vector<char> &sigma, std::string p)
{
        std::vector<std::map<char, u_int>> table;
        std::string p1 = "";
        std::string p2 = "";

        for (auto i = 0; i <= p.size(); i++)
        {
                std::map<char, u_int> temp;
                table.push_back(temp);

                p1 += p[i];

                for (auto j : sigma)
                {
                        table[i].insert(std::pair<char, u_int>(j, suffix(p1, p2 + j)));
                }

                p2 += p[i];
        }

        return table;
}

std::vector<u_int> finite_state_machine(std::vector<char> &sigma, std::string s, std::string p)
{
        u_int statement = 0;
        std::vector<std::map<char, u_int>> table = table_building(sigma, p);
        std::vector<u_int> indexes;
        std::string temp = "";

        for (auto i = 0; i < s.size(); i++)
        {
                for (auto it = table[statement].begin(); it != table[statement].end(); it++)
                {
                        if (it->first == s[i])
                        {
                                statement = it->second;
                                break;
                        }
                }

                if (statement == table.size() - 1)
                {
                        indexes.push_back(i - (p.size() - 1));
                }
        }

        return indexes;
}