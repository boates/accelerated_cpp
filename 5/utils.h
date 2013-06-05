#ifndef GUARD_grade_h
#define GUARD_grade_h

// string_util.h
#include <string>
#include <vector>

std::vector<std::string> split(const std::string&);
std::string::size_type width_old(const std::vector<std::string>&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);

#endif