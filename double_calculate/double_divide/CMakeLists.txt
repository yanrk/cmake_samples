# determine library type
if(BUILD_STATIC)
    set(LIB_TYPE STATIC)
    message(STATUS "building double_divide as static library")
else()
    set(LIB_TYPE SHARED)
    message(STATUS "building double_divide as shared library")
endif()

# create the library
add_library(double_divide ${LIB_TYPE}
    src/double_divide.cpp
)

# set properties
set_target_properties(double_divide PROPERTIES
    OUTPUT_NAME "double_divide"
    PUBLIC_HEADER "inc/double_divide.h"
)

# macOS use @executable_path
if(APPLE AND NOT BUILD_STATIC)
    set_target_properties(double_divide PROPERTIES
        INSTALL_NAME_DIR "@executable_path"
    )
endif()

# include directories
target_include_directories(double_divide PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

# install rules
install(TARGETS double_divide
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)
