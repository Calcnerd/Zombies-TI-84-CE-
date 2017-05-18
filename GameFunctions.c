#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/ce/graphx.h>

#include <Sprites.h>
#include <xlibcsprites.h>

#include "GameFunctions.h"

#include "Tests.h"
#include "Structdefs.h"

/*void KeyLeft(int* x, bool* WithinScreen, bool* WithinGun, int* ShowFiring, int* CanShoot, int* ShowBloodSplatter)
{
    int i;
    CheckRange(x, WithinScreen, WithinGun);
    if (ShowFiring)
        --ShowFiring;
    if (CanShoot)
        --CanShoot;
    if (WithinScreen)
    {
        gfx_FillRectangle(*x,30,225,210);
    }
    if (*x>=675)
    {
        *x=-225;
    }else{
        *x+=8;
    }
    CheckRange(x, WithinScreen, WithinGun);
    if (WithinScreen)
    {
        gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
        gfx_TransparentSprite(EnemySprite,*x,30);
        gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
        for(i=0;i<2;i--)
        {
            if (ShowBloodSplatter[i])
            {
                gfx_TransparentSprite(BloodSplatter,ShowBloodSplatter[i]+*x,100);
            }
        }
        if (WithinGun)
        {
            if (ShowFiring)
            {
                gfx_TransparentSprite(SilencedPistolFiring,131,154);
            }else{
                gfx_TransparentSprite(SilencedPistol,131,174);
            }
        }
    }
}

void KeyRight(int* x, bool* WithinScreen, bool* WithinGun, int* ShowFiring, int* CanShoot, int* ShowBloodSplatter)
{
    int i;
    CheckRange(x, WithinScreen, WithinGun);
    if (ShowFiring)
        --ShowFiring;
    if (CanShoot)
        --CanShoot;
    if (WithinScreen)
    {
        gfx_FillRectangle(*x,30,225,210);
    }
    if (*x>=675)
    {
        *x=-225;
    }else{
        *x+=8;
    }
    CheckRange(x, WithinScreen, WithinGun);
    if (WithinScreen)
    {
        gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
        gfx_TransparentSprite(EnemySprite,*x,30);
        gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
        for(i=0;i<2;i--)
        {
            if (ShowBloodSplatter[i])
            {
                gfx_TransparentSprite(BloodSplatter,ShowBloodSplatter[i]+*x,100);
            }
        }
        if (WithinGun)
        {
            if (ShowFiring)
            {
                gfx_TransparentSprite(SilencedPistolFiring,131,154);
            }else{
                gfx_TransparentSprite(SilencedPistol,131,174);
            }
        }
    }
}*/

void ZombieDead(int x)
{
    gfx_PrintStringXY("Kill!",150,0);
    gfx_FillRectangle(x,30,225,210);
    gfx_BlitBuffer();
}

struct zombie NewZombie(void){
    zombie Zombie;
    Zombie.x=randInt(-225,450);
    Zombie.health=100;
    Zombie.ShowBloodSplatter[0]=0;
    Zombie.ShowBloodSplatter[1]=0;
    Zombie.zType=NORMAL;
    return Zombie;
}

//update will eventually display stats and other information. Now simply used for displaying info useful for debugging.
void update(int x, int ammo)
{
    gfx_FillRectangle(0,0,30,20);
    gfx_SetTextXY(0,0);
    gfx_PrintInt(x,3);
    gfx_SetTextXY(0,9);
    gfx_PrintInt(ammo,2);
    gfx_BlitBuffer();
}
