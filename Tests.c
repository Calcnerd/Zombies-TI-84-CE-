#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool CheckInScreen(int x){
    bool WithinScreen;
    if (x+225>=0 && x<=360){
        WithinScreen=true;
    }else{
        WithinScreen=false;
    }
    return WithinScreen;
}

bool CheckInGun(int x){
    bool WithinGun;
    if (x+225>=188 && x<=131){
        WithinGun=true;
    }else{
        WithinGun=false;
    }
    return WithinGun;
}

void AddBloodSplatter(int x, int ShowBloodSplatter0, int ShowBloodSplatter1){
        if (!ShowBloodSplatter0){
            ShowBloodSplatter0=160-x+50;
        }else{
            ShowBloodSplatter1=160-x+50;
        }
}
