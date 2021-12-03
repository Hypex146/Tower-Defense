cmake_minimum_required(VERSION 3.20)
project(Tower_Defense)

set(CMAKE_CXX_STANDARD 20)

set(MY_STRING lib/my-lib/string/MyString.cpp)
set(MY_STRING_TEST ${MY_STRING} lib/my-lib/string/test_MyString.cpp)

set(CFG lib/my-lib/configurator/Configurator.cpp ${MY_STRING})
set(CFG_TEST ${CFG} lib/my-lib/configurator/test_Configurator.cpp)

set(LIST_TEST lib/my-lib/list/test_List.cpp)

set(QUEUE_TEST lib/my-lib/list/test_Queue.cpp)

set(GRAPH_TEST lib/my-lib/graph/test_Graph.cpp)

set(TABLE_TEST lib/my-lib/table/test_Table.cpp)

set(ENTITY entities/Entity.cpp)
set(ENTITY_TEST entities/Entity.cpp entities/test_Entity.cpp)

set(CASTLE entities/allied/Castle.cpp ${MY_STRING} ${ENTITY})
set(CASTLE_TEST ${CASTLE} entities/allied/test_Castle.cpp)

set(WALL entities/allied/Wall.cpp ${MY_STRING} ${ENTITY})
set(WALL_TEST ${WALL} entities/allied/test_Wall.cpp)

set(TOWER entities/allied/Tower.cpp ${MY_STRING} ${ENTITY})
set(TOWER_TEST ${TOWER} entities/allied/test_Tower.cpp)

set(MAIN main.cpp)

include_directories(lib/my-lib/string)
include_directories(lib/my-lib/configurator)
include_directories(lib/my-lib/list)
include_directories(lib/my-lib/table)
include_directories(entities)
include_directories(entities/allied)
include_directories(entities/hostile)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

add_executable(Tower_Defense ${TOWER_TEST})
target_link_libraries(Tower_Defense gtest gtest_main)
