#ifndef INA3221_H
#define INA3221_H

#include "driver/i2c_master.h"
#include "esp_err.h"
#include "esp_log.h"

typedef enum INA3221_ADDR_t {
    CONFIG            = 0x00,
    CH1_SH            = 0x01,
    CH1_BUS           = 0x02,
    CH2_SH            = 0x03,
    CH2_BUS           = 0x04,
    CH3_SH            = 0x05,
    CH3_BUS           = 0x06,
    CH1_CAL           = 0x07,
    CH1_WAL           = 0x08,
    CH2_CAL           = 0x09,
    CH2_WAL           = 0x0A,
    CH3_CAL           = 0x0B,
    CH3_WAL           = 0x0C,
    SHUNT_SUM         = 0x0D,
    SHUNT_SUM_LIMIT   = 0x0E,
    MASK_ENABLE       = 0x0F,
    POWER_UPPER_LIMIT = 0x10,
    POWER_LOWER_LIMIT = 0x11,
    MAN_ID            = 0xFE,
    DIE_ID            = 0xFF
};

esp_err_t ina3221_get_config(i2c_master_dev_handle_t *ina3221Handle, uint16_t *config);




#endif