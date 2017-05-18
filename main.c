// Program Name: Zombies
// Author(s): Calcnerd
// Description: A simple FPS for the TI-84+CE

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Libraries*/
#include <lib/ce/graphx.h>
#include <lib/ce/keypadc.h>


/*gfx includes*/
#include <sprites.h>
#include <xlibcsprites.h>


#include "Structdefs.h"
#include "Tests.h"
#include "GameFunctions.h"


bool shoot_gun(void);


void main()
{
    player Player;
    zombie Zombie;
    int kTurn=0, kShoot=0, kMenu=0, kExit=0;
    int ShowFiring=0, CanShoot=0, i;
    //seed random number generator
    srand(rtc_Time());
    Zombie.x=randInt(-225,450);
    Zombie.health=100;
    Zombie.ShowBloodSplatter[0]=0;
    Zombie.ShowBloodSplatter[1]=0;
    Zombie.zType=NORMAL;
    Player.ammo=10;
    Player.health=100;
    gfx_Begin(gfx_8bpp);
    gfx_SetDrawBuffer();
    gfx_SetColor(255);
    gfx_FillScreen(255);
    gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
    gfx_TransparentSprite(EnemySprite,Zombie.x,30);
    gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
    gfx_TransparentSprite(SilencedPistol,131,174);
    update(Zombie.x, Player.ammo);
    while(kb_ScanGroup(kb_group_6) != kb_Clear)
    {
        if (kTurn & kb_Left)
        {
            CheckRange(Zombie.x, Zombie.WithinScreen, Zombie.WithinGun);
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
            CheckRange(Zombie.x, Zombie.WithinScreen, Zombie.WithinGun);
            if (Zombie.WithinScreen)
            {
                gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
                gfx_TransparentSprite(EnemySprite,Zombie.x,30);
                gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
                for(i=0;i<2;i++)
                {
                    if (Zombie.ShowBloodSplatter[i])
                    {
                        gfx_TransparentSprite(BloodSplatter,Zombie.ShowBloodSplatter[i]+Zombie.x,100);
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
            CheckRange(Zombie.x, Zombie.WithinScreen, Zombie.WithinGun);
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
            CheckRange(Zombie.x, Zombie.WithinScreen, Zombie.WithinGun);
            if (Zombie.WithinScreen){
                gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
                gfx_TransparentSprite(EnemySprite,Zombie.x,30);
                gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
                for(i=0;i<2;i++){
                    if (Zombie.ShowBloodSplatter[i])
                    {
                        gfx_TransparentSprite(BloodSplatter,Zombie.ShowBloodSplatter[i]+Zombie.x,100);
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
                    AddBloodSplatter(Zombie.x, Zombie.ShowBloodSplatter);
                    Zombie.health-=50;
                    if (!Zombie.health)
                        ZombieDead(Zombie.x);
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
                    for(i=0;i<50;i++)
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
                    for(i=0;i<50;i++)
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
        kShoot=kb_ScanGroup(kb_group_1);
        kTurn=kb_ScanGroup(kb_group_7);
    }
    gfx_End();
    pgrm_CleanUp();
}

/* Other functions */

bool shoot_gun(void){
    bool hit;
    int i;
    Zombie.WithinScreen=CheckInScreen(Zombie.x);
    Zombie.WithinGun=CheckInGun(Zombie.x);
    //gun moving upward
    if (Zombie.WithinGun)
    {
        gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
        gfx_TransparentSprite(EnemySprite,Zombie.x,30);
    }else{
        for(i=0;i<50;i++)
            gfx_FillRectangle(131,174,57,70);
    }
    gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
    gfx_TransparentSprite(SilencedPistol,131,172);
    gfx_BlitBuffer();
    if (Zombie.WithinGun)
    {
        gfx_SetPalette(sprites_pal,sizeof(sprites_pal),0);
        gfx_TransparentSprite(EnemySprite,Zombie.x,30);
    }else{
        for(i=0;i<50;i++)
            gfx_FillRectangle(131,172,57,70);
    }
    gfx_SetPalette(xlibcsprites_pal,sizeof(xlibcsprites_pal),0);
    gfx_TransparentSprite(SilencedPistolFiring,131,154);
    gfx_BlitBuffer();
    if(Zombie.x+50<=158 && Zombie.x+175>=162)
    {
        hit=true;
    }else{
        hit=false;
    }
    return hit;
}
