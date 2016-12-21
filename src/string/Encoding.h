//
// Created by ykh on 2016-12-21.
//

#ifndef JWPACK_ENCODING_H
#define JWPACK_ENCODING_H

#include "inc.h"

namespace jwpack {
namespace string {

static const uint8_t UTF16LE_BOM[2] = {0xFE, 0xFE};
static const uint8_t UTF16BE_BOM[2] = {0xFE, 0xFF};
static const uint8_t UTF8_BOM[3] = {0xEF, 0xBB, 0xBF};

class Encoding {
public:
    static std::string W2UTF8(const wchar_t* wstr);
    static std::string W2A(const wchar_t* wstr);
};
}
}

#endif //JWPACK_ENCODING_H
