enable_testing ()

# Framework for writing tests.
ExternalProject_Add (
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "release-1.8.1"
    CMAKE_ARGS "-DCMAKE_BUILD_TYPE=Release"
    SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/googletest"
    BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/googletest"
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)
set_target_properties (googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)
ExternalProject_Get_Property (googletest source_dir binary_dir)
set (GTEST_ROOT "${CMAKE_CURRENT_BINARY_DIR}/googletest")
set (GTEST_FOUND TRUE)
set (GTEST_INCLUDE_DIRS   "${source_dir}/googletest/include")
set (GTEST_LIBRARIES      "${binary_dir}/googlemock/gtest/libgtest.a")
set (GTEST_MAIN_LIBRARIES "${binary_dir}/googlemock/gtest/libgtest_main.a")
set (GTEST_BOTH_LIBRARIES ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
set (GMOCK_INCLUDE_DIRS   "${source_dir}/googlemock/include")
set (GMOCK_LIBRARIES      "${binary_dir}/googlemock/libgmock.a")

include_directories (
    ${PROJECT_SOURCE_DIR}/test
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

# Special flags fo generating code coverage.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set (CMAKE_SHARED_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")


# Test suites.
set (
    controller_test_SOURCES
    ${controller_SOURCES}
    ${PROJECT_SOURCE_DIR}/test/controller_test.cpp
)

add_executable (controller_test EXCLUDE_FROM_ALL ${controller_test_SOURCES})

target_link_libraries (
    controller_test
    ${GTEST_BOTH_LIBRARIES}
    ${GMOCK_LIBRARIES}
    gcov
    pthread
)
add_dependencies (controller_test googletest)
add_test (controller_test controller_test)


# Test coverage report.
set (Coverage_REPORT ${CMAKE_CURRENT_BINARY_DIR}/coverage.info)
set (Coverage_DIR    ${CMAKE_CURRENT_BINARY_DIR}/coverage)
add_custom_command (
    OUTPUT  ${Coverage_REPORT}
    COMMAND lcov -q -c -f -b . -d ${CMAKE_CURRENT_BINARY_DIR} -o ${Coverage_REPORT}
    COMMAND lcov -e ${Coverage_REPORT} '${PROJECT_SOURCE_DIR}/src/*' -o ${Coverage_REPORT}
    COMMAND genhtml ${Coverage_REPORT} --legend --demangle-cpp -f -q -o ${Coverage_DIR}
    DEPENDS controller_test
)
add_custom_target (coverage DEPENDS ${Coverage_REPORT})
