# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
cmake_minimum_required(VERSION 3.15)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

if (APPLE)
  SET(XTENSA_URL "https://dl.espressif.com/dl/xtensa-esp32-elf-gcc8_2_0-esp32-2019r1-rc2-macos.tar.xz")
elseif (WIN32)
  SET(XTENSA_URL "https://dl.espressif.com/dl/xtensa-esp32-elf-gcc8_2_0-esp32-2019r1-rc2-win32.tar.xz")
else()
  SET(XTENSA_URL "https://dl.espressif.com/dl/xtensa-esp32-elf-gcc8_2_0-esp32-2019r1-rc2-linux-amd64.tar.xz")
endif()

# gcc and other compiler tools
FetchContent_Declare(
  xtensa-esp32-elf
  URL      ${XTENSA_URL}
)
FetchContent_Populate(xtensa-esp32-elf)
# Path so esp-idf toolchain can find compilers
# Done through sdkconfig file
LIST(APPEND CMAKE_PROGRAM_PATH ${xtensa-esp32-elf_SOURCE_DIR}/bin)

# esp-idf source
FetchContent_Declare(
  espressifidf
  #URL https://github.com/espressif/esp-idf/archive/master.zip
  GIT_REPOSITORY https://github.com/espressif/esp-idf
  GIT_TAG v4.0-beta1
)
FetchContent_Populate(espressifidf)
set(ENV{IDF_PATH} ${espressifidf_SOURCE_DIR})

include(${espressifidf_SOURCE_DIR}/tools/cmake/project.cmake)

project(espproj
  VERSION 0.0.1
  LANGUAGES C CXX ASM)
