# determine library type
if(BUILD_STATIC)
    set(LIB_TYPE STATIC)
    message(STATUS "building double_operators as static library")
else()
    set(LIB_TYPE SHARED)
    message(STATUS "building double_operators as shared library")
endif()

# create the library
add_library(double_operators ${LIB_TYPE}
    src/double_operators.cpp
)

# set properties
set_target_properties(double_operators PROPERTIES
    OUTPUT_NAME "double_operators"
    PUBLIC_HEADER "inc/double_operators.h"
)

# macOS use @executable_path
if(APPLE AND NOT BUILD_STATIC)
    set_target_properties(double_operators PROPERTIES
        INSTALL_NAME_DIR "@executable_path"
    )
endif()

if(NOT BUILD_STATIC)
    # for Unix-like systems, clear the RPATH setting
    if(UNIX)
        set_target_properties(double_operators PROPERTIES
            SKIP_BUILD_RPATH FALSE
            BUILD_WITH_INSTALL_RPATH TRUE
            INSTALL_RPATH "$ORIGIN"
        )
    endif()
endif()

# add dependencies
target_link_libraries(double_operators PRIVATE
    double_add
    double_subtract
    double_multiply
    double_divide
)

# include directories
target_include_directories(double_operators PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

# install rules
install(TARGETS double_operators
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)
