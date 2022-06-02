#include <iostream>
#include <type_traits>

#include "muduo/net/EventLoop.h"

using namespace std;
using namespace muduo::net;

int main()
{
    cout << "hello world" << endl;
    cout << std::is_trivial<EventLoop>::value << endl;
    return 0;
}