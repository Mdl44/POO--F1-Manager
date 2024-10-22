cmake_minimum_required(VERSION 3.15)

# Project name and C++ standard
project(oop)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# FetchContent for external dependencies (SFML)
include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2888d9c56eba4dedb93a84a3c57957e4a907d428
)
FetchContent_MakeAvailable(SFML)

# Add executable and specify source and header files
add_executable(oop
        main.cpp
        sources/Driver.cpp headers/Driver.h
        #sources/Team.cpp headers/Team.h
        #sources/Car.cpp headers/Car.h
        #sources/Race.cpp headers/Race.h
        #sources/Qualifying.cpp headers/Qualifying.h
        #sources/TeamPrincipal.cpp headers/TeamPrincipal.h
)
# Include directories for header files
target_include_directories(oop PRIVATE ${CMAKE_SOURCE_DIR}/headers)

# Include SFML directories and link SFML libraries
target_include_directories(oop SYSTEM PRIVATE ${SFML_SOURCE_DIR}/include)
target_link_directories(oop PRIVATE ${SFML_BINARY_DIR}/lib)
target_link_libraries(oop sfml-graphics sfml-window sfml-system)

# Compiler flags for warnings and errors
if(MSVC)
    target_compile_options(oop PRIVATE /W4 /WX /wd4244 /wd4267 /permissive-)
else()
    target_compile_options(oop PRIVATE -Wall -Wextra -pedantic -Werror)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        # Additional flags for GCC
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        target_compile_options(oop PRIVATE -stdlib=libc++)
        target_link_options(oop PRIVATE -stdlib=libc++)
    endif()
endif()


# Sanitizers (optional, adjust for your platform)
if(APPLE)
    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
elseif(UNIX)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined -fsanitize-memory-track-origins)
        target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined -fsanitize-memory-track-origins)
    endif()
endif()

# Installation rules to copy files and resources to the bin folder
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY resources DESTINATION bin)
install(FILES date.txt tastatura.txt DESTINATION bin)
