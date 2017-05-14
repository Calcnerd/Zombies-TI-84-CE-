#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GameFunctions.h"

#include "Tests.h"

void KeyLeft(int* x, bool* WithinScreen, bool* WithinGun, int* ShowFiring, int* CanShoot)
{
    int i;
    WithinScreen=CheckInScreen(Zombie.x);
    WithinGun=CheckInGun(Zombie.x);
    if (ShowFiring)
        --ShowFiring;
    if (CanShoot)
        --CanShoot;
    if (Zombie.WithinScreen)
    {
        gfx_FillRectangle(Zombie.x,30,225,210);
    }
    if (Zombie.x>=900)
    {
        Zombie.x=-225;
    }else{
        Zombie.x+=8;
    }
    WithinScreen=CheckInScreen(x);
    WithinGun=CheckInGun(x);
    if (Zombie.WithinScreen)
    {
        gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
        gfx_TransparentSprite(EnemySprite,Zombie.x,30);
        gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
        for(i=0;i<2;i--)
        {
            if (Zombie.ShowBloodSplatter[i])
            {
                gfx_TransparentSprite(BloodSplatter,Zombie.ShowBloodSplatter[i]+x,100);
            }
        }
        if (Zombie.WithinGun)
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
void KeyRight(int x)
{
    Zombie.WithinScreen=CheckInScreen(Zombie.x);
    Zombie.WithinGun=CheckInGun(Zombie.x);
    if (ShowFiring)
        --ShowFiring;
    if (CanShoot)
        --CanShoot;
    if (Zombie.WithinScreen)
    {
        gfx_FillRectangle(Zombie.x,30,225,210);
    }
    if (Zombie.x>=900)
    {
        Zombie.x=-225;
    }else{
        Zombie.x+=8;
    }
    Zombie.WithinScreen=CheckInScreen(Zombie.x);
    Zombie.WithinGun=CheckInGun(Zombie.x);
    if (Zombie.WithinScreen)
    {
        gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
        gfx_TransparentSprite(EnemySprite,Zombie.x,30);
        gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
        for(x=0;x<2;x--)
        {
            if (Zombie.ShowBloodSplatter[x])
            {
                gfx_TransparentSprite(BloodSplatter,Zombie.ShowBloodSplatter[x]+Zombie.x,100);
            }
        }
        if (Zombie.WithinGun)
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
