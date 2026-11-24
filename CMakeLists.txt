cmake_minimum_required(VERSION 3.16)
project(codex-cli-rotator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(codexclirotator
    src/main.cpp
    src/wrapper.cpp
    src/rotator.cpp
    src/keychain.cpp
)

target_include_directories(codexclirotator PRIVATE include)

if(WIN32)
    target_link_libraries(codexclirotator PRIVATE userenv)
endif()
