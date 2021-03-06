cmake_minimum_required(VERSION 3.1...3.16)

# https://github.com/boostcon/cppnow_presentations_2017/blob/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf
# https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/
# https://dominikberner.ch/cmake-interface-lib/

project(matlab
  LANGUAGES CXX)

add_library(mex SHARED src/mex.cpp include/mex.h include/mex_versions.h)
add_library(mx SHARED src/mx.cpp include/mex.h include/matrix.h include/matrix_versions.h)
add_library(ut SHARED src/ut.cpp)
add_library(eng SHARED src/eng.cpp)

if (MATLAB_API_VERSION)
  target_compile_definitions(mex PUBLIC "APIVERSION=${MATLAB_API_VERSION}")
  target_compile_definitions(mx PUBLIC "APIVERSION=${MATLAB_API_VERSION}")
endif()

set_target_properties(mex mx ut eng PROPERTIES CXX_STANDARD 11)

install(TARGETS mex mx ut eng EXPORT matlabTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include)

add_library(matlab INTERFACE)
target_link_libraries(matlab INTERFACE mex mx ut eng)



if(APPLE)
  set(MATLAB_MEX_EXT "mexi64")
elseif(WIN32)
  target_compile_definitions(matlab INTERFACE __STDC_UTF_16__ WINMAT64)
  set(MATLAB_MEX_EXT "mexw64")
else()
  set(MATLAB_MEX_EXT "mexa64")
endif()

target_include_directories(mex PUBLIC
  $<BUILD_INTERFACE:${matlab_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(mx PUBLIC
  $<BUILD_INTERFACE:${matlab_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(matlab INTERFACE
  $<BUILD_INTERFACE:${matlab_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS matlab EXPORT matlabTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT matlabTargets
  FILE matlabTargets.cmake
  NAMESPACE matlab::
  DESTINATION cmake
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/matlabConfigVersion.cmake
  VERSION 1.2014a
  COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
  INSTALL_DESTINATION
  cmake)


install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/matlabConfigVersion.cmake"
  DESTINATION cmake
)

