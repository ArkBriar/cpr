#ifndef CPR_COOKIES_H
#define CPR_COOKIES_H

#include <map>
#include <string>
#include <sstream>
#include <initializer_list>

namespace cpr {

class Cookies {
  public:
    Cookies() {}
    Cookies(const std::initializer_list<std::pair<const std::string, std::string>>& pairs);
    Cookies(const std::map<std::string, std::string>& map) : map_{map} {}

    std::string& operator[](const std::string& key);
    std::string GetEncoded() const;

    void AddCookie(const Cookies& cookies);
    void AddCookie(const std::map<std::string, std::string>& cookies);
    void AddCookie(const std::pair<std::string, std::string>& cookie);

    void DelCookie(const std::string key);

  private:
    std::map<std::string, std::string> map_;
};

} // namespace cpr

#endif
