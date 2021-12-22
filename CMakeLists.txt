cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(otus_cpp_p_project VERSION ${PROJECT_VESRION})

find_package (Boost REQUIRED
    COMPONENTS program_options
)
include_directories(${Boost_INCLUDE_DIR})

add_executable(halfSumFinder
    halfSumFinder/main.cpp
    src/halfsumfinder.cpp
    src/set.cpp
)
add_executable(hsfTester
    hsfTester/main.cpp
    src/halfsumfinder.cpp
    src/set.cpp
    util/gendata.cpp
)
add_executable(hsfSearchOrderDemo
    hsfSearchOrderDemo/main.cpp
    src/set.cpp
)
add_executable(hsfInputGenerator
    hsfInputGenerator/main.cpp
    util/gendata.cpp
)
add_executable(hsfOutputVerifier
    hsfOutputVerifier/main.cpp
)

set_target_properties(halfSumFinder hsfTester hsfSearchOrderDemo
    hsfInputGenerator hsfOutputVerifier
 PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(hsfTester PUBLIC
	Boost::program_options
)
target_link_libraries(hsfInputGenerator PUBLIC
	Boost::program_options
)

if (MSVC)
    target_compile_options(halfSumFinder PRIVATE
        /W4
    )
else ()
    target_compile_options(halfSumFinder PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfTester PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfTester PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfSearchOrderDemo PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfSearchOrderDemo PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfInputGenerator PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfInputGenerator PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()
if (MSVC)
    target_compile_options(hsfOutputVerifier PRIVATE
        /W4
    )
else ()
    target_compile_options(hsfOutputVerifier PRIVATE
        -Wall -Wextra -pedantic -Werror -Wno-sign-compare
		-Wno-parentheses
    )
endif()


install(TARGETS halfSumFinder hsfTester hsfSearchOrderDemo
    hsfInputGenerator hsfOutputVerifier RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)