cmake_minimum_required(VERSION 3.10)
project(CppConcurrencyPrep CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
file(GLOB SOURCES "src/cpp/*.cpp")
foreach(SOURCE ${SOURCES})
    get_filename_component(EXEC_NAME ${SOURCE} NAME_WE)
    add_executable(${EXEC_NAME} ${SOURCE})
    target_link_libraries(${EXEC_NAME} PRIVATE pthread)
	set_target_properties(${EXEC_NAME} PROPERTIES OUTPUT_NAME "${EXEC_NAME}.o")
endforeach()

