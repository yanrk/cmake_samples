cmake_minimum_required(VERSION 3.10)

project(double_calculate
    LANGUAGES CXX
    VERSION 1.0.0
)

# set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# platform-specific settings
if(WIN32)
    if(NOT BUILD_STATIC)
        add_definitions(-DEXPORT_DLL)
    endif()
else()
    if(NOT BUILD_STATIC)
        set(CMAKE_CXX_VISIBILITY_PRESET hidden)
        set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
    endif()
endif()

# build option - ON for static, OFF for shared
option(BUILD_STATIC "build static libraries (OFF for shared libraries)" ON)

# common compilation flags (apply to all platforms)
set(COMMON_FLAGS "-Wall")

# platform-specific flags
if(WIN32)
    # Windows (MSVC) specific settings
    set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} /EHsc /W4")

    # Debug/Release differentiation
    if(BUILD_STATIC)
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /Zi")      # Debug: Multi-threaded debug, debug info
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /O2")   # Release: Multi-threaded, optimization
    else()
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /Zi")      # Debug: Multi-threaded Dynamic debug, debug info
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /O2")   # Release: Multi-threaded Dynamic, optimization
    endif()
else()
    # Linux/macOS (GCC/Clang) settings
    set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -Wextra")                          # Enable extra warnings to catch potential issues
    set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -fPIC")                            # Position Independent Code for shared libraries

    # Debug/Release differentiation
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")            # Debug: No optimization, debug symbols
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")  # Release: Max optimization, no debug
endif()

# include common directory
include_directories(${CMAKE_SOURCE_DIR}/common/inc)

# add subdirectories
add_subdirectory(double_add)
add_subdirectory(double_subtract)
add_subdirectory(double_multiply)
add_subdirectory(double_divide)
add_subdirectory(double_operators)
add_subdirectory(double_test)

# install rules
install(DIRECTORY common/inc/ DESTINATION include)
install(DIRECTORY double_add/inc/ DESTINATION include)
install(DIRECTORY double_subtract/inc/ DESTINATION include)
install(DIRECTORY double_multiply/inc/ DESTINATION include)
install(DIRECTORY double_divide/inc/ DESTINATION include)
install(DIRECTORY double_operators/inc/ DESTINATION include)
