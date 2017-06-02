#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddBloodSplatter(int x, int* ShowBloodSplatter/*, int ShowBloodSplatter*/)
{
        if (!ShowBloodSplatter[0])
        {
            ShowBloodSplatter[0]=160-x-3;
        }else{
            ShowBloodSplatter[1]=160-x-3;
        }
}

void CheckRange(int x, bool* WithinScreen, bool* WithinGun, bool* GunRedraw)
{
    if (x+225>=0 && x<=320)
    {
        *WithinScreen=true;
    }else{
        *WithinScreen=false;
    }
    if (x+225>=188 && x<=131)
    {
        *WithinGun=true;
        return;
    }else{
        *WithinGun=false;
    }
    if (x+225>=131 && x<=188)
    {
        *GunRedraw=true;
    }else{
        *GunRedraw=false;
    }
}
