#ifndef _FAST_RESET_H_
#define _FAST_RESET_H_

#define _FAST_RESET_PREF_NAMESPACE_ "fast-reset"
#define _FAST_RESET_PREF_KEY_ "count"

#include <Preferences.h>

class FastReset
{
private:
    Preferences _prefs;
    uint16_t _timeout;
    uint16_t _count;
    static void _stopTaskImpl(void *);
    void _stopTask();

public:
    FastReset();
    void begin(uint16_t timeout = 3);
    uint16_t count();
};

#endif