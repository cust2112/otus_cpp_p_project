cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(otus_cpp_p_project VERSION ${PROJECT_VESRION})

find_package (Boost REQUIRED
    COMPONENTS program_options
)
include_directories(${Boost_INCLUDE_DIR})

add_executable(halfSumFinder.exe
    halfSumFinder/main.cpp
    src/halfsumfinder.cpp
    src/set.cpp
)
add_executable(hsfTester.exe
    hsfTester/main.cpp
    src/halfsumfinder.cpp
    src/set.cpp
    util/gendata.cpp
)
add_executable(hsfSearchOrderDemo.exe
    hsfSearchOrderDemo/main.cpp
    src/set.cpp
)
add_executable(hsfInputGenerator.exe
    hsfInputGenerator/main.cpp
    util/gendata.cpp
)
add_executable(hsfOutputVerifier.exe
    hsfOutputVerifier/main.cpp
)

set_target_properties(halfSumFinder.exe hsfTester.exe hsfSearchOrderDemo.exe
    hsfInputGenerator.exe hsfOutputVerifier.exe
 PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(hsfTester.exe PUBLIC
	Boost::program_options
)
target_link_libraries(hsfInputGenerator.exe PUBLIC
	Boost::program_options
)

if (MSVC)
    target_compile_options(halfSumFinder.exe PRIVATE
        /W4
    )
else ()
    target_compile_options(halfSumFinder.exe PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfTester.exe PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfTester.exe PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfSearchOrderDemo.exe PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfSearchOrderDemo.exe PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfInputGenerator.exe PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfInputGenerator.exe PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfOutputVerifier.exe PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfOutputVerifier.exe PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()


install(TARGETS halfSumFinder.exe hsfTester.exe hsfSearchOrderDemo.exe
    hsfInputGenerator.exe hsfOutputVerifier.exe RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)