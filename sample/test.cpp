//
// Created by ykh on 2016-12-21.
//
#include <cstdio>
#include "JwPack.h"

int main(int argc, char* argv[])
{
    printf("sss \n");

    wchar_t* wstr = L"abc유근鎬";
    std::string utf8str = jwpack::string::Encoding::W2UTF8(wstr);
    std::string ansistr = jwpack::string::Encoding::W2A(wstr);

    printf("utf8=%s", utf8str.c_str());

    return 0;
}
