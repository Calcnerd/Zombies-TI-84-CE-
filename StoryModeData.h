#ifndef _StoryModeData_h_
#define _StoryModeData_h_

//Story Mode Data. Includes data about the level (# of zombies per level, type of zombies (NORMAL, HEAVY, LARGE, HULK - defined in Structdefs.h), amount of each type of zombie per level)

int LevelNumZombies[30]={
//first 10 levels all NORMAL zombies
     5, 6, 7, 8, 9,10,15,16,17,18,
//introduce LARGE after level 10
    19,20,25,25,25,25,30,30,30,30,
//Introduce HEAVY after level 20, then HULK at level 25
    35,35,35,40,40,40,45,45,45,50
}

int LevelTypeZombies[30][4]={//LEVEL:    |10|                          |20|                          |30|
    /*NORMAL*/{ 5, 6, 7, 8, 9,10,15,16,17,18,18,18,20,20,19,19,23,22,21,20, 5, 5, 5, 7, 5, 4,45,45,45, 7},
    /*LARGE */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 5, 6, 6, 7, 8, 9,10,25,20,19,20,17,10, 0, 0, 0,15},
    /*HEAVY */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,10,11,13,18,25, 0, 0, 0,25},
    /* HULK */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 3}
}

#endif
