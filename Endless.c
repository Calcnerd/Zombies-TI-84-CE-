#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Endless.h"
#include "Structdefs.h"

/*int EndlessGame(void)
{
    int TotalKills;
    bool Exit=false;
    //Initialize player
    player Player;
    while(!Exit)
    {
        if (kTurn & kb_Left)
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
            if (Zombie.x>=450)
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
            update(Zombie.x, Player.ammo);
        }
        if (kTurn & kb_Right)
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
            if (Zombie.x<=-225)
            {
                Zombie.x=450;
            }else{
                Zombie.x-=8;
            }
            Zombie.WithinScreen=CheckInScreen(Zombie.x);
            Zombie.WithinGun=CheckInGun(Zombie.x);
            if (Zombie.WithinScreen){
                gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
                gfx_TransparentSprite(EnemySprite,Zombie.x,30);
                gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
                for(x=0;x<2;x--){
                    if (Zombie.ShowBloodSplatter[x])
                    {
                        gfx_TransparentSprite(BloodSplatter,Zombie.ShowBloodSplatter[x]+Zombie.x,100);
                    }
                }
                if (Zombie.WithinGun){
                    if (ShowFiring)
                    {
                        gfx_TransparentSprite(SilencedPistolFiring,131,154);
                    }else{
                        gfx_TransparentSprite(SilencedPistol,131,174);
                    }
                }
            }
            update(Zombie.x, Player.ammo);
        }
        if ((kShoot & kb_2nd) && (!ShowFiring && !CanShoot)){
            ShowFiring=10;
            if (Player.ammo)
            {
                --Player.ammo;
                if (shoot_gun())
                {
                    AddBloodSplatter(Zombie.x, Zombie.ShowBloodSplatter[0], Zombie.ShowBloodSplatter[1]);
                    Zombie.health-=50;
                    if (!Zombie.health)
                        zombie_dead();
                }
            }
            update(Zombie.x, Player.ammo);
        }
        if (ShowFiring){
            gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
            gfx_TransparentSprite(SilencedPistolFiring,131,154);
            gfx_BlitBuffer();
            --ShowFiring;
            if (!ShowFiring)
            {
                if (Zombie.WithinGun)
                {
                    gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
                    gfx_TransparentSprite(EnemySprite,Zombie.x,30);
                }else{
                    for(x=0;x<50;x++)
                        gfx_FillRectangle(131,154,57,86);
                }
                gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
                gfx_TransparentSprite(SilencedPistol,131,172);
                gfx_BlitBuffer();
                if (Zombie.WithinGun)
                {
                    gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
                    gfx_TransparentSprite(EnemySprite,Zombie.x,30);
                }else{
                    for(x=0;x<50;x++)
                        gfx_FillRectangle(131,172,57,70);
                }
                gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
                gfx_TransparentSprite(SilencedPistol,131,174);
                gfx_BlitBuffer();
                CanShoot=10;
            }
        }
        if (CanShoot)
        {
            --CanShoot;
        }
        Zombie.WithinScreen=CheckInScreen(Zombie.x);
        Zombie.WithinGun=CheckInGun(Zombie.x);
        kShoot=kb_ScanGroup(kb_group_1);
        kTurn=kb_ScanGroup(kb_group_7);
    }
    return 1;
}*/
