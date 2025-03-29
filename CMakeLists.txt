cmake_minimum_required(VERSION 3.10)
project(ConcurrencyPrep LANGUAGES C CXX)

# C settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for headers
include_directories(include)

# C sources
file(GLOB C_SOURCES "src/c/*.c")
foreach(SOURCE ${C_SOURCES})
    get_filename_component(EXEC_NAME ${SOURCE} NAME_WE)
    add_executable(${EXEC_NAME}_c ${SOURCE})
    target_link_libraries(${EXEC_NAME}_c PRIVATE pthread)
    set_target_properties(${EXEC_NAME}_c PROPERTIES
        OUTPUT_NAME "${EXEC_NAME}.o"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/c"
    )
endforeach()

# C++ sources
file(GLOB CPP_SOURCES "src/cpp/*.cpp")
foreach(SOURCE ${CPP_SOURCES})
    get_filename_component(EXEC_NAME ${SOURCE} NAME_WE)
    add_executable(${EXEC_NAME}_cpp ${SOURCE})
    target_link_libraries(${EXEC_NAME}_cpp PRIVATE pthread)
    set_target_properties(${EXEC_NAME}_cpp PROPERTIES
        OUTPUT_NAME "${EXEC_NAME}.o"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/cpp"
    )
endforeach()
