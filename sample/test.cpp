//
// Created by ykh on 2016-12-21.
//
#include <cstdio>
#include <mutex>
#include "JwPack.h"
#include "spdlog/spdlog.h"



int main(int argc, char* argv[])
{
    std::mutex m;

    printf("sss  %ld \n", __cplusplus);

    wchar_t* wstr = L"abc유근鎬";
    std::string utf8str = jwpack::string::Encoding::W2UTF8(wstr);
    std::string ansistr = jwpack::string::Encoding::W2A(wstr);

    wprintf(L"wstr=%ls \n", wstr);
    printf("utf8=%s \n", utf8str.c_str());
    printf("ansi=%s \n", utf8str.c_str());

    return 0;
}
