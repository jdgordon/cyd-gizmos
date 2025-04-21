#ifndef _HEBCAL_H
#define _HEBCAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Arduino.h>

struct HebCalVals {
    String hDate;
    int DayOfOmer;
    bool isNighttime;

    int error;
    unsigned long next_update_secs;
};

HebCalVals ReloadHebCal(time_t unixtime);



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
