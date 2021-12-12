#ifndef TOWER_DEFENSE_TOWERDEFENSE_H
#define TOWER_DEFENSE_TOWERDEFENSE_H

#include "EntitiesManager.h"

class TowerDefense {
private:
    EntitiesManager *entities_manager_;
public:
    const EntitiesManager *getEntitiesManagerPtr();

};


#endif //TOWER_DEFENSE_TOWERDEFENSE_H
