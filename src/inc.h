//
// Created by ykh on 2016-12-21.
//

#ifndef JWPACK_INC_H
#define JWPACK_INC_H

#include <cstdlib>
#include <cassert>

#include <string>
#include <memory>

#include <thread>
#include <mutex>
#include <condition_variable>

#ifdef __MINGW__
#include "mingw.condition_variable.h"
#include "mingw.thread.h"
#include "mingw.mutex.h"
#else

#endif


#endif //JWPACK_INC_H
