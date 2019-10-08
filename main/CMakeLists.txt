idf_component_register(SRCS main.cc
  INCLUDE_DIRS .
  PRIVATE "${xtensa-esp32-elf_SOURCE_DIR}/xtensa-esp32-elf/include/c++/8.2.0")

target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unused-variable -std=c++14)

message("Building main")
