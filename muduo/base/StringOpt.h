#ifndef MUDUO_BASE_STRINGOPT_H
#define MUDUO_BASE_STRINGOPT_H

#include <string>

namespace muduo
{

// 从一行字符串中，获取它的 key 和 value
std::pair<std::string, std::string>
getHeader(const char* start, const char* colon, const char* end)
{
    std::string field(start, colon);
    ++colon;
    while (colon < end && isspace(*colon)) { ++colon; }
    std::string value(colon, end);
    while (!value.empty() && isspace(value[value.size() - 1]))
    {
        value.resize(value.size() - 1);
    }
    return std::pair<std::string, std::string>(field, value);
}

} // namespace muduo

#endif // MUDUO_BASE_STRINGOPT_H