libsqlitepp
=========

libsqlitepp is a C++11 GPL-licensed wrapper around the sqlite library. It aims to be thread safe, simple to use and to have no dependencies (except for libsqlite3, ofcourse).

usage
=====
The library is completely implemented in one .hpp file; the only thing you have to do is to put the header libsqlite.hpp in your include path and use:
```
#include <libsqlite.hpp>
```
or
```
#include "libsqlite.hpp"
```
depending on where it is located.

example usage
=============
refer to the tests.cpp file; you can build the tests.cpp as following:
```
mkdir build
cd build
cmake ..
make
```

a resulting libsqlite executable will be in the build directory.

License
=======
The library is licensed under GPLv3. If you want to use the library under different conditions, please do not hesitate to contact me. See the AUTHORS file.
