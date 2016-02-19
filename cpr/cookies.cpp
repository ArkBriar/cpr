#include "cpr/cookies.h"

#include "cpr/util.h"

namespace cpr {

Cookies::Cookies(const std::initializer_list<std::pair<const std::string, std::string>>& pairs)
        : map_{pairs} {}

std::string Cookies::GetEncoded() const {
    std::stringstream stream;
    for (const auto& item : map_) {
        stream << cpr::util::urlEncode(item.first) << "=";
        // special case version 1 cookies, which can be distinguished by
        // beginning and trailing quotes
        if (!item.second.empty() && item.second.front() == '"' && item.second.back() == '"') {
            stream << item.second;
        } else {
            stream << cpr::util::urlEncode(item.second);
        }
        stream << "; ";
    }
    return stream.str();
}

std::string& Cookies::operator[](const std::string& key) {
    return map_[key];
}

void Cookies::AddCookie(const Cookies& cookies) {
    AddCookie(cookies.map_);
}

void Cookies::AddCookie(const std::map<std::string, std::string>& cookies) {
    for (auto i : cookies) {
        AddCookie(i);
    }
}

void Cookies::AddCookie(const std::pair<std::string, std::string>& cookie) {
    map_.insert(cookie);
}

void Cookies::DelCookie(const std::string key) {
    map_.erase(key);
}

} // namespace cpr

