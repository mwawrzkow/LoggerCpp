#define SHOULDLOG 1
#include "src/Log.hpp"
class LOG(TestClass)
{
public:
    TestClass() 
    LOG_CONSTRUCTOR(DEBUG,"log.txt") {};
    void log()
    {
        LOG_DEBUG("Debug");
        LOG_INFO("Info");
        LOG_WARNING("Warning");
        LOG_ERROR("Error");
        LOG_CRITICAL("Critical");
    };
};

int main()
{
    TestClass test;
    test.log();
}