#ifndef __FINITE_STATE_MACHINE_ALG__
#define __FINITE_STATE_MACHINE_ALG__

#include <string>
#include <vector>
#include <map>

u_int suffix(std::string p, std::string s);

std::vector<std::map<char, u_int>> table_building(std::vector<char> &sigma, std::string p);

std::vector<u_int> finite_state_machine(std::vector<char> &sigma, std::string s, std::string p);

#endif