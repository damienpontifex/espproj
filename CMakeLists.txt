cmake_minimum_required(VERSION 3.15)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
  xtensa-esp32-elf
  URL      https://dl.espressif.com/dl/xtensa-esp32-elf-gcc8_2_0-esp32-2019r1-rc2-macos.tar.xz
  URL_HASH SHA256=fac993b4b730b648b038e6393de74940d61a611788b8653bdb8ea5e850a28348
)
FetchContent_Populate(xtensa-esp32-elf)
LIST(APPEND CMAKE_PROGRAM_PATH ${xtensa-esp32-elf_SOURCE_DIR}/bin)

FetchContent_Declare(
  espressifidf
  GIT_REPOSITORY https://github.com/espressif/esp-idf
  GIT_TAG v4.1-dev
)

if(NOT espressifidf_POPULATED)
  # Fetch the content using previously declared details
  FetchContent_Populate(espressifidf)
endif()
set(ENV{IDF_PATH} ${espressifidf_SOURCE_DIR})

include(${espressifidf_SOURCE_DIR}/tools/cmake/project.cmake)
project(espproj)
