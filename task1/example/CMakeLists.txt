project(example)

set(EXAMPLE_SOURCES "example.cpp")

add_executable(example ${EXAMPLE_SOURCES})

target_link_libraries(example CSR)

install(TARGETS example #EXPORT hello-targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BIDIR}/examples/)
