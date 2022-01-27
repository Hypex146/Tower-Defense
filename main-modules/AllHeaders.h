#ifndef TOWER_DEFENSE_ALLHEADERS_H
#define TOWER_DEFENSE_ALLHEADERS_H

#ifdef ALL_INCLUDE
#define STD_LIBS_INCLUDE
#define MY_LIBS_INCLUDE
#define ENTITIES_INCLUDE
#define MAIN_MODULES_INCLUDE
#endif

// Std libs
#ifdef STD_LIBS_INCLUDE
#include <iostream>
#include <fstream>
#include <iterator>
#include <cmath>
#include <ctime>
#endif

// My libs
#ifdef MY_LIBS_INCLUDE
#include "MyString.h"
#include "Configurator.h"
#include "List.h"
#include "Queue.h"
#include "Table.h"
#include "Graph.h"
#endif

// Entities
#ifdef ENTITIES_INCLUDE
#include "Entity.h"
#include "Castle.h"
#include "Tower.h"
#include "Wall.h"
#include "Enemy.h"
#include "Hero.h"
#include "Lair.h"
#include "Aviation.h"
#include "HeavyInfantry.h"
#include "HeroAviation.h"
#include "HeroHeavyInfantry.h"
#include "LightInfantry.h"
#include "HeroLightInfantry.h"
#endif

// Main modules
#ifdef MAIN_MODULES_INCLUDE
#include "SettingsDatabase.h"
#include "Renderer.h"
#include "ConsoleRenderer.h"
#include "EntitiesManager.h"
#include "GameMap.h"
#include "TowerDefense.h"
#endif

#endif //TOWER_DEFENSE_ALLHEADERS_H
