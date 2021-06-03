#include "../includes/rabin_karp_alg.h"

std::vector<u_int> rabin_karp(u_int sigma_size, std::string s, std::string p)
{
        std::vector<u_int> indexes;

        int q = 30013;
        int d_m = (int)pow(sigma_size, p.size() - 1) % q;
        int h = 0;
        int h_1 = 0;

        for (auto i = 0; i < p.size(); i++)
        {
                h = (sigma_size * h + (int)p[i]) % q;
                h_1 = (sigma_size * h_1 + (int)s[i]) % q;
        }

        for (int i = 0; i <= s.size() - p.size(); i++)
        {
                if (h == h_1)
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
                        h_1 = (sigma_size * (h_1 - (int)s[i] * d_m) + (int)s[i + p.size()]) % q;

                        if (h_1 < 0)
                        {
                                h_1 += q;
                        }
                }
        }

        return indexes;
}