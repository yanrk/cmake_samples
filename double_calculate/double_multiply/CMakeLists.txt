# determine library type
if(BUILD_STATIC)
    set(LIB_TYPE STATIC)
    message(STATUS "building double_multiply as static library")
else()
    set(LIB_TYPE SHARED)
    message(STATUS "building double_multiply as shared library")
endif()

# create the library
add_library(double_multiply ${LIB_TYPE}
    src/double_multiply.cpp
)

# set properties
set_target_properties(double_multiply PROPERTIES
    OUTPUT_NAME "double_multiply"
    PUBLIC_HEADER "inc/double_multiply.h"
)

# macOS use @executable_path
if(APPLE AND NOT BUILD_STATIC)
    set_target_properties(double_multiply PROPERTIES
        INSTALL_NAME_DIR "@executable_path"
    )
endif()

# include directories
target_include_directories(double_multiply PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

# install rules
install(TARGETS double_multiply
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)
