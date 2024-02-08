# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\mslast_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mslast_autogen.dir\\ParseCache.txt"
  "mslast_autogen"
  )
endif()
