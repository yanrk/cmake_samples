# determine library type
if(BUILD_STATIC)
    set(LIB_TYPE STATIC)
    message(STATUS "building double_add as static library")
else()
    set(LIB_TYPE SHARED)
    message(STATUS "building double_add as shared library")
endif()

# create the library
add_library(double_add ${LIB_TYPE}
    src/double_add.cpp
)

# set properties
set_target_properties(double_add PROPERTIES
    OUTPUT_NAME "double_add"
    PUBLIC_HEADER "inc/double_add.h"
)

# macOS use @executable_path
if(APPLE AND NOT BUILD_STATIC)
    set_target_properties(double_add PROPERTIES
        INSTALL_NAME_DIR "@executable_path"
    )
endif()

# include directories
target_include_directories(double_add PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

# install rules
install(TARGETS double_add
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)
