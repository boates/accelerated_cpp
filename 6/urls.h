#ifndef GUARD_urls_h
#define GUARD_urls_h

// urls.h
#include <string>
#include <vector>

bool not_url_char(char c);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

#endif