#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TYPE {NORMAL,LARGE,HEAVY,HULK};

typedef struct zombie{
    int health;
    int x;
    bool WithinScreen;
    bool WithinGun;
    bool GunRedraw;
    int ShowBloodSplatter[2];
    enum TYPE zType;
} zombie;

typedef struct player{
    int ammo;
    int health;
}player;
