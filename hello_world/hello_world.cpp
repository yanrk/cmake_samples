#include <iostream>
#include <cstdio>

#if __cplusplus >= 202302L
    #include <print>
#elif __cplusplus >= 202002L
    #include <format>
#endif

int main()
{
#if __cplusplus >= 202302L
    std::println("hello, world! (using std::println)");
#elif __cplusplus >= 202002L
    std::cout << std::format("hello, world! (using std::format)\n");
#elif __cplusplus >= 201103L
    std::cout << "hello, world! (using std::cout)" << std::endl;
#else
    std::printf("hello, world! (using printf)\n");
#endif
    return 0;
}
