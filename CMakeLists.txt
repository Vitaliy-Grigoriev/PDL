cmake_minimum_required(VERSION   3.17)
project(PdlFramework   CXX)

# Select CPP standard.
set(CMAKE_CXX_STANDARD   17)
set(CMAKE_CXX_STANDARD_REQUIRED    ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

# Select output binary paths.
set(EXECUTABLE_OUTPUT_PATH   ${PROJECT_SOURCE_DIR}/bin)

# Info about a compiler.
message("[info] Compiler is '${CMAKE_CXX_COMPILER_ID}'.")

# Find Boost library.
find_package(Boost   1.74   REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Find GTest library.
if (DEFINED   PDL_WITH_TESTS)
    message("[info] PDL Tests Included.")
    find_package(GTest   1.10   REQUIRED)
    add_subdirectory(tests)
    pdl_test_init()
endif()

set(DISABLE_WARNINGS         "-Wno-unknown-pragmas -Wno-unused-parameter -Wno-zero-as-null-pointer-constant -Wno-deprecated-declarations")
set(DISABLE_WARNINGS_GCC     "-Wno-variadic-macros -Wno-unknown-pragmas")
set(DISABLE_WARNINGS_CLANG   "-Wno-return-std-move-in-c++11 -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-exit-time-destructors -Wno-missing-prototypes -Wno-documentation")
set(DISABLE_WARNINGS_INTEL   "-diag-disable=161,1478")
set(DISABLE_WARNINGS_DEBUG   "-Wno-unused-result -Wno-unused-variable")
set(DISABLE_WARNINGS_DEBUG_CLANG   "-Wno-unused-macros -Wno-padded -Wno-weak-vtables -Wno-cast-align")
set(DISABLE_WARNINGS_BOOST_CLANG   "-Wno-disabled-macro-expansion -Wno-global-constructors")
set(SANITIZE_FLAGS           "-fsanitize=address  -fsanitize=leak  -fsanitize=undefined")


# Choose compiler flags.
set(CMAKE_CXX_FLAGS_DEBUG     "-std=c++17 -O0 -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE   "-std=c++17 -O2 -g -DRELEASE -DNDEBUG")
if (CMAKE_CXX_COMPILER_ID   MATCHES   "GNU")
    set(CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS}   ${DISABLE_WARNINGS}")
    set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS_DEBUG}   -fno-omit-frame-pointer -static-libstdc++ -static-libgcc   -Wall -Wextra -Wpedantic   ${DISABLE_WARNINGS_GCC} ${DISABLE_WARNINGS_DEBUG}")
    set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE}   ${DISABLE_WARNINGS_GCC}")
elseif (CMAKE_CXX_COMPILER_ID   MATCHES   "Clang")
    set(CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS}   ${DISABLE_WARNINGS} ${DISABLE_WARNINGS_BOOST_CLANG}")
    set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS_DEBUG}   -fno-omit-frame-pointer -fstandalone-debug   -Weverything -Wthread-safety   ${SANITIZE_FLAGS} ${DISABLE_WARNINGS_CLANG} ${DISABLE_WARNINGS_DEBUG} ${DISABLE_WARNINGS_DEBUG_CLANG}")
    set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE}   ${DISABLE_WARNINGS_CLANG}")
elseif (CMAKE_CXX_COMPILER_ID   MATCHES   "Intel")
    set(CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS}   ${DISABLE_WARNINGS_INTEL}")
    set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS_DEBUG}   -w3 -Wall -Wcheck")
    set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE}   -Ofast -xSSE4.2 -axAVX,CORE-AVX2")
else()
    set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS_DEBUG}   -Wall")
endif()

# Output compile flags.
if (${CMAKE_BUILD_TYPE}   MATCHES   "Release")
    message("[info] Compiler flags:   ${CMAKE_CXX_FLAGS_RELEASE}.")
else()
    message("[info] Compiler flags:   ${CMAKE_CXX_FLAGS_DEBUG}.")
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(common)
add_subdirectory(parser)
add_subdirectory(model)
#add_subdirectory(tools)
