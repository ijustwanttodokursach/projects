# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\rpbd_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\rpbd_autogen.dir\\ParseCache.txt"
  "rpbd_autogen"
  )
endif()
