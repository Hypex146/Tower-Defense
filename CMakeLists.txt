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

set(ALL_MY_LIBS ${MY_STRING} ${CFG})

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

set(HERO entities/hostile/enemies/Hero.cpp)

set(HERO_LIGHT_INFANTRY entities/hostile/enemies/HeroLightInfantry.cpp ${LIGHT_INFANTRY} ${HERO})
set(HERO_LIGHT_INFANTRY_TEST ${HERO_LIGHT_INFANTRY} entities/hostile/enemies/test_HeroLightInfantry.cpp)

set(HERO_HEAVY_INFANTRY entities/hostile/enemies/HeroHeavyInfantry.cpp ${HEAVY_INFANTRY} ${HERO})
set(HERO_HEAVY_INFANTRY_TEST ${HERO_HEAVY_INFANTRY} entities/hostile/enemies/test_HeroHeavyInfantry.cpp)

set(HERO_AVIATION entities/hostile/enemies/HeroAviation.cpp ${AVIATION} ${HERO})
set(HERO_AVIATION_TEST ${HERO_AVIATION} entities/hostile/enemies/test_HeroAviation.cpp)

set(ALL_ENTITIES ${CASTLE} ${WALL} ${TOWER} ${LAIR} ${ENEMY} ${LIGHT_INFANTRY} ${HEAVY_INFANTRY} ${AVIATION}
        ${HERO_LIGHT_INFANTRY} ${HERO_HEAVY_INFANTRY} ${HERO_AVIATION})

set(ENTITIES_MANAGER main-modules/EntitiesManager.cpp ${ALL_ENTITIES})

set(TOWER_DEFENSE main-modules/TowerDefense.cpp ${ENTITIES_MANAGER} ${GAME_MAP} ${CONSOLE_RENDERER})

set(GAME_MAP main-modules/GameMap.cpp)

set(RENDERER main-modules/Renderer.cpp)

set(CONSOLE_RENDERER main-modules/ConsoleRenderer.cpp ${RENDERER})

set(SETTINGS_DATABASE main-modules/SettingsDatabase.cpp ${CFG})

set(ALL_MAIN_MODULES ${ENTITIES_MANAGER} ${TOWER_DEFENSE} ${GAME_MAP} ${RENDERER} ${CONSOLE_RENDERER} ${SETTINGS_DATABASE})

set(MAIN main.cpp)

set(ALL_TOWER_DEFENSE ${ALL_MY_LIBS} ${ALL_ENTITIES} ${ALL_MAIN_MODULES})

include_directories(lib/my-lib/string)
include_directories(lib/my-lib/configurator)
include_directories(lib/my-lib/list)
include_directories(lib/my-lib/table)
include_directories(lib/my-lib/graph)
include_directories(entities)
include_directories(entities/allied)
include_directories(entities/hostile)
include_directories(entities/hostile/enemies)
include_directories(main-modules)

#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)

add_executable(Tower_Defense ${MAIN} ${ALL_TOWER_DEFENSE})
#add_executable(Tower_Defense ${LIST_TEST})
#add_executable(Tower_Defense ${GRAPH_TEST})

#target_link_libraries(Tower_Defense gtest gtest_main)
