#ifndef _GameFunctions_h
#define _GameFunctions_h

void KeyLeft(int* x, bool* WithinScreen, bool* WithinGun, int* ShowFiring, int* CanShoot, int* ShowBloodSplatter);
void KeyRight(int* x, bool* WithinScreen, bool* WithinGun, int* ShowFiring, int* CanShoot, int* ShowBloodSplatter);
bool ShootGun(int x);
void ZombieDead(int x);
struct zombie NewZombie(void);
void update(int x, int ammo);


#endif
