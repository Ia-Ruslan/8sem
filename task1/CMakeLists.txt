cmake_minimum_required(VERSION 3.0)

project(MyCSRProject VERSION 1.0.0 LANGUAGES CXX)

option(WITH_EXAMPLE "Compile examples" ON)
option(WITH_SPARSKIT "Use SPARSKIT" OFF)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/" "${CMAKE_MODULE_PATH}")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wpedantic -Wextra -fexceptions -O0 -g3 -ggdb --std=c++17")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -O3 --std=c++17")

include(GNUInstallDirs)

add_subdirectory(src)
add_subdirectory(include)

add_library(MySRC "${SOURCE_LIB}" "${HEADER_LIB}")

set_target_properties(MyCSR PROPERTIES VERSION ${PROJECT_VERSION}
                            PUBLIC_HEADER ${PUBLIC_HEADERS})


target_include_directories(MyCSR PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
	$<INSTALL_INTERFACE: ${CMAKE_INSTALL_INCLUDEDIR}>)

if (WITH_SPARSKIT)
	target_compile_definitions(MyCSR PUBLIC WITH_SPARSKIT)
        find_package(SPARSKIT REQUIRED)
        target_link_libraries(MyCSR ${SPARSKIT_LIBRARIES})
endif()	


if (WITH_EXAMPLE)
    add_subdirectory(example)
endif()

install(TARGETS MyCSR EXPORT MyCSR-targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


install(EXPORT MyCSR-targets DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/MyCSR")

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/csrmatr-config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/csrmatr-config.cmake"
	#PATH_VARS CSR_INCLUDE_DIR
	INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/MyCSR")

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/MyCSRConfigVersion.cmake"
	VERSION "${PROJECT_VERSION}"
        COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/csr-config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/MyCSRConfigVersion.cmake
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/MyCSR")



