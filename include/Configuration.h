#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include <stdbool.h>
#include <inttypes.h>

struct configuration_t {
    bool module_enabled;
    bool buzzer_enabled;

    uint8_t headlights_brightness;

    bool headlights_smooth_turnoff_enabled;
    uint8_t headlights_smooth_turnoff_time;

    bool gauges_with_headlights;

    bool send_me_home_enabled;
    uint8_t send_me_home_time;
};

struct configuration_t readConfiguration(void);
void writeConfiguration(struct configuration_t);

#endif
