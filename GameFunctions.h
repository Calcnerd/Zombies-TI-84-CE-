#ifndef _GameFunctions_h
#define _GameFunctions_h

bool shoot_gun(int x, int ShowBloodSplatter[], bool* WithinScreen, bool* WithinGun, int ShowFiring, int health);
void ZombieDead(int x);
//experimental function for creating a new zombie
void NewZombie(int* x, int* health, int* ShowBloodSplatter[], enum TYPE *zType);
void update(int x, int ammo);
void Sprite(int x, int ShowBloodSplatter[], int WithinScreen, int WithinGun, int ShowFiring, int Health);


#endif
