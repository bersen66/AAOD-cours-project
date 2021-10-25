cmake_minimum_required(VERSION 3.19)
project(COURS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(include)
include_directories(src)
include_directories(tests)



add_executable(COURS
        include/time_keeper.h
        src/time_keeper.cpp

        include/date.h

        src/ConsoleGUI.cpp
        src/date.cpp

        include/task.h
        src/task.cpp
        include/storage.h
        src/storage.cpp
        )

#target_link_libraries(COURS SDL2main SDL2)