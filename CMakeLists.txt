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

set(ENTITY entities/Entity.cpp ${MY_STRING})
set(ENTITY_TEST ${ENTITY} entities/test_Entity.cpp)

set(CASTLE entities/allied/Castle.cpp ${MY_STRING} ${ENTITY})
set(CASTLE_TEST ${CASTLE} entities/allied/test_Castle.cpp)

set(WALL entities/allied/Wall.cpp ${MY_STRING} ${ENTITY})
set(WALL_TEST ${WALL} entities/allied/test_Wall.cpp)

set(TOWER entities/allied/Tower.cpp ${MY_STRING} ${ENTITY})
set(TOWER_TEST ${TOWER} entities/allied/test_Tower.cpp)

set(LAIR entities/hostile/Lair.cpp ${MY_STRING} ${ENTITY})
set(LAIR_TEST ${LAIR} entities/hostile/test_Lair.cpp)

set(ENEMY entities/hostile/Enemy.cpp ${MY_STRING} ${ENTITY})
set(ENEMY_TEST ${ENEMY} entities/hostile/test_Enemy.cpp)

set(LIGHT_INFANTRY entities/hostile/enemies/LightInfantry.cpp ${ENEMY})
set(LIGHT_INFANTRY_TEST ${LIGHT_INFANTRY} entities/hostile/enemies/test_LightInfantry.cpp)

set(HEAVY_INFANTRY entities/hostile/enemies/HeavyInfantry.cpp ${ENEMY})
set(HEAVY_INFANTRY_TEST ${HEAVY_INFANTRY} entities/hostile/enemies/test_HeavyInfantry.cpp)

set(AVIATION entities/hostile/enemies/Aviation.cpp ${ENEMY})
set(AVIATION_TEST ${AVIATION} entities/hostile/enemies/test_Aviation.cpp)

set(ALL_ENTITIES ${CASTLE} ${WALL} ${TOWER})

set(ENTITIES_MANAGER entities/EntitiesManager.cpp ${ALL_ENTITIES})

set(MAIN main.cpp)

include_directories(lib/my-lib/string)
include_directories(lib/my-lib/configurator)
include_directories(lib/my-lib/list)
include_directories(lib/my-lib/table)
include_directories(entities)
include_directories(entities/allied)
include_directories(entities/hostile)
include_directories(entities/hostile/enemies)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

add_executable(Tower_Defense ${AVIATION_TEST})
target_link_libraries(Tower_Defense gtest gtest_main)
