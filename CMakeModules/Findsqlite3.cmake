###############################################################################
# CMake module to search for SQLite library
#
# On success, the macro sets the following variables:
# SQLITE_FOUND = if the library found
# SQLITE_LIBRARY = full path to the library
# SQLITE_LIBRARIES = full path to the library
# SSQLITE_INCLUDE_DIR = where to find the library headers
#
# Copyright (c) 2009 Mateusz Loskot <mateusz@loskot.net>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#
###############################################################################


find_path(SQLITE_INCLUDE_DIR
  NAMES sqlite3.h
  PATH_PREFIXES sqlite 
  PATHS
  /usr/include
  /usr/local/include
  $ENV{LIB_DIR}/include
  $ENV{LIB_DIR}/include/sqlite
  $ENV{ProgramFiles}/SQLite/*/include
  $ENV{SystemDrive}/SQLite/*/include
  )

set(SQLITE_NAMES  sqlite3)
find_library(SQLITE_LIBRARY
  NAMES ${SQLITE_NAMES}
  PATHS
  /usr/lib
  /usr/local/lib
  $ENV{LIB_DIR}/lib
  $ENV{ProgramFiles}/SQLite/*/lib
  $ENV{SystemDrive}/SQLite/*/lib
   )

set(SQLITE_LIBRARIES ${SQLITE_LIBRARY})

#message(STATUS ${SQLITE_LIBRARY})
# Handle the QUIETLY and REQUIRED arguments and set SQLITE_FOUND to TRUE
# if all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLITE
  DEFAULT_MSG
  SQLITE_LIBRARY
  SQLITE_INCLUDE_DIR)

mark_as_advanced(SQLITE_LIBRARY SQLITE_INCLUDE_DIR SQLITE_LIBRARY)
