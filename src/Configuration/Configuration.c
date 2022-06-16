#include <Configuration.h>
#include <avr/eeprom.h>

void writeConfiguration(struct configuration_t configuration) {
    void* configuration_ptr = &configuration;

    for (int idx = 0; idx < sizeof(configuration); idx ++)
        eeprom_write_byte((uint8_t*)(EEPROM_CONFIG_START + idx), ((uint8_t*)configuration_ptr)[idx]);
}

struct configuration_t readConfiguration(void) {
    struct configuration_t configuration;
    void* configuration_ptr = &configuration;

    for (int idx = 0; idx < sizeof(configuration); idx ++) 
        ((uint8_t*)configuration_ptr)[idx] = eeprom_read_byte((const uint8_t*)(EEPROM_CONFIG_START + idx));

    return configuration;
}