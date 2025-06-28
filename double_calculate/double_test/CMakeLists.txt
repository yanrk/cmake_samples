# create test executable
add_executable(double_test src/double_test.cpp)

# link with libraries
target_link_libraries(double_test PRIVATE
    double_add
    double_subtract
    double_multiply
    double_divide
    double_operators
)

# include directories
target_include_directories(double_test PRIVATE
    ${CMAKE_SOURCE_DIR}/common/inc
    ${CMAKE_SOURCE_DIR}/double_operators/inc
)

# install rules
install(TARGETS double_test
    RUNTIME DESTINATION bin
)

# list dependent libraries while need copy
set(libraries_to_copy
    double_add
    double_subtract
    double_multiply
    double_divide
    double_operators
)

# use Windows-style dynamic library handling
if(NOT BUILD_STATIC)
    # copy libraries
    foreach(lib IN LISTS libraries_to_copy)
        add_custom_command(TARGET double_test POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
                $<TARGET_FILE:${lib}>
                $<TARGET_FILE_DIR:double_test>
            COMMENT "Copying ${lib} to executable directory"
        )
    endforeach()

    # for Unix-like systems, clear the RPATH setting
    if(UNIX)
        set_target_properties(double_test PROPERTIES
            SKIP_BUILD_RPATH FALSE
            BUILD_WITH_INSTALL_RPATH TRUE
            INSTALL_RPATH "$ORIGIN"
        )
    endif()
endif()
