#include "../includes/rabin_karp_alg.h"

std::vector<u_int> rabin_karp(u_int sigma_size, std::string s, std::string p)
{
        std::vector<u_int> indexes;

        int q = 30013;
        int d_m = (int)pow(sigma_size, p.size() - 1) % q;
        int hash_p = 0;
        int hash_s = 0;

        for (auto i = 0; i < p.size(); i++)
        {
                hash_p = (sigma_size * hash_p + (int)p[i]) % q;
                hash_s = (sigma_size * hash_s + (int)s[i]) % q;
        }

        for (int i = 0; i <= s.size() - p.size(); i++)
        {
                if (hash_p == hash_s)
                {
                        int j = 0;
                        for (j = 0; j < p.size(); j++)
                        {
                                if (s[i + j] != p[j])
                                {
                                        break;
                                }
                        }

                        if (j == p.size())
                        {
                                indexes.push_back(i);
                        }
                }

                if (i < s.size() - p.size())
                {
                        hash_s = (sigma_size * (hash_s - (int)s[i] * d_m) + (int)s[i + p.size()]) % q;

                        if (hash_s < 0)
                        {
                                hash_s += q;
                        }
                }
        }

        return indexes;
}