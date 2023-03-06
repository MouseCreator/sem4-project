# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Modelium_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Modelium_autogen.dir\\ParseCache.txt"
  "Modelium_autogen"
  )
endif()
