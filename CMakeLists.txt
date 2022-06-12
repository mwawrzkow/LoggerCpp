cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Werror)
add_compile_options(-Wpedantic)
add_compile_options(-Wconversion)
#DEFINITIONS
add_compile_definitions(SAVE_TO_FILE)
# add_compile_definitions(USE_THREADS)




#END of DEFINITIONS


project(logger)


add_library(logger_shared SHARED src/logger.cpp)
add_library(logger_static STATIC src/logger.cpp)
if(USE_THREADS)
    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)
    target_link_libraries (logger_shared Threads::Threads) 
    target_link_libraries (logger_static Threads::Threads)
endif()




add_executable(main-withStatic main.cpp)
target_link_libraries(main-withStatic logger_static)
add_executable(main-withShared main.cpp)
target_link_libraries(main-withShared logger_shared)

add_compile_definitions(SHOULDLOG)
target_precompile_headers(main-withStatic PUBLIC src/Log.hpp)
target_precompile_headers(main-withShared  PUBLIC src/Log.hpp) 