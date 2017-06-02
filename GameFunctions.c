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

void ZombieDead(int x)
{
    gfx_PrintStringXY("Kill!",150,0);
    gfx_FillRectangle(x,30,225,210);
    gfx_BlitBuffer();
}

void NewZombie(int* x, int* health, int* ShowBloodSplatter, enum TYPE *zType)
{
    *x=randInt(-225,450);
    *health=100;
    ShowBloodSplatter[0]=0;
    ShowBloodSplatter[1]=0;
    *zType=NORMAL;
    //Note: need to redraw zombie after
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

void Sprite(int x, int ShowBloodSplatter[], int WithinScreen, int WithinGun, int ShowFiring, int Health)
{
    int i;
    if (Health)
    {
        if (WithinScreen)
        {
            gfx_TransparentSprite(EnemySprite,x,30);
            for(i=0;i<2;i++)
            {
                if (ShowBloodSplatter[i])
                {
                    gfx_TransparentSprite(BloodSplatter,ShowBloodSplatter[i]+x,150);
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
}

bool shoot_gun(int x, int ShowBloodSplatter[], bool* WithinScreen, bool* WithinGun, bool* GunRedraw, int ShowFiring, int health)
{
    bool hit;
    int i;
    CheckRange(x, WithinScreen, WithinGun, GunRedraw);
    //gun moving upward
    if (WithinGun)
    {
        Sprite(x, ShowBloodSplatter, *WithinScreen, *WithinGun, ShowFiring, health);
    }else{
        for(i=0;i<50;i++)
            gfx_FillRectangle(131,174,57,70);
    }
    gfx_TransparentSprite(SilencedPistol,131,172);
    gfx_BlitBuffer();
    if (WithinGun)
    {
        Sprite(x, ShowBloodSplatter, *WithinScreen, *WithinGun, ShowFiring, health);
    }else{
        for(i=0;i<50;i++)
            gfx_FillRectangle(131,172,57,70);
    }
    gfx_TransparentSprite(SilencedPistolFiring,131,154);
    gfx_BlitBuffer();
    if(x+50<=158 && x+175>=162)
    {
        hit=true;
    }else{
        hit=false;
    }
    return hit;
}
