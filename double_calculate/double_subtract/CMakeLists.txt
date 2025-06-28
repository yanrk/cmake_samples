# determine library type
if(BUILD_STATIC)
    set(LIB_TYPE STATIC)
    message(STATUS "building double_subtract as static library")
else()
    set(LIB_TYPE SHARED)
    message(STATUS "building double_subtract as shared library")
endif()

# create the library
add_library(double_subtract ${LIB_TYPE}
    src/double_subtract.cpp
)

# set properties
set_target_properties(double_subtract PROPERTIES
    OUTPUT_NAME "double_subtract"
    PUBLIC_HEADER "inc/double_subtract.h"
)

# macOS use @executable_path
if(APPLE AND NOT BUILD_STATIC)
    set_target_properties(double_subtract PROPERTIES
        INSTALL_NAME_DIR "@executable_path"
    )
endif()

# include directories
target_include_directories(double_subtract PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

# install rules
install(TARGETS double_subtract
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)
