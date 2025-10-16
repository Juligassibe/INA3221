#ifndef INA3221_H
#define INA3221_H

#include "driver/i2c_master.h"
#include "esp_err.h"
#include "esp_log.h"

typedef enum INA3221_ADDR_t {
    INA_CONFIG        = 0x00,
    CH1_SHUNT         = 0x01,
    CH1_BUS           = 0x02,
    CH2_SHUNT         = 0x03,
    CH2_BUS           = 0x04,
    CH3_SHUNT         = 0x05,
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

// Se deberá hacer operacion OR entre todas las configs que se deseen
typedef enum INA3221_CONFIG_t {
    INA_RST = 0x8000,
    CH1_EN = 0x4000,
    CH2_EN = 0x2000,
    CH3_EN = 0x1000,
    AVG_1_SAMPLE = 0x0000,
    AVG_4_SAMPLE = 0x0200,
    AVG_16_SAMPLE = 0x0400,
    AVG_64_SAMPLE = 0x0600,
    AVG_128_SAMPLE = 0x0800,
    AVG_256_SAMPLE = 0x0A00,
    AVG_512_SAMPLE = 0x0C00,
    AVG_1024_SAMPLE = 0x0E00,
    BUS_CT_140US = 0x0000,
    BUS_CT_204US = 0x0040,
    BUS_CT_332US = 0x0080,
    BUS_CT_588US = 0x00C0,
    BUS_CT_1MS = 0x0100,
    BUS_CT_2MS = 0x0140,
    BUS_CT_4MS = 0x0180,
    BUS_CT_8MS = 0x01C0,
    SHUNT_CT_140US = 0x0000,
    SHUNT_CT_204US = 0x0008,
    SHUNT_CT_332US = 0x0010,
    SHUNT_CT_588US = 0x0018,
    SHUNT_CT_1MS = 0x0020,
    SHUNT_CT_2MS = 0x0028,
    SHUNT_CT_4MS = 0x0030,
    SHUNT_CT_8MS = 0x0038,
    MODE_PD = 0x0000,
    MODE_SHUNT_SS = 0x0001,
    MODE_BUS_SS = 0x0002,
    MODE_SHUNT_CONT = 0x0005,
    MODE_BUS_CONT = 0x0006
};

esp_err_t ina3221_get_config(i2c_master_dev_handle_t *ina3221Handle, uint16_t *config);
esp_err_t ina3221_set_config(i2c_master_dev_handle_t *ina3221Handle, uint16_t config);
esp_err_t ina3221_get_ch1_shunt(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch1Shunt);
esp_err_t ina3221_get_ch1_bus(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch1Bus);
esp_err_t ina3221_get_ch2_shunt(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch2Shunt);
esp_err_t ina3221_get_ch2_bus(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch2Bus);
esp_err_t ina3221_get_ch3_shunt(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch3Shunt);
esp_err_t ina3221_get_ch3_bus(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch3Bus);
esp_err_t ina3221_get_ch1_critical_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t *limit);
esp_err_t ina3221_set_ch1_critical_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t limit);
esp_err_t ina3221_get_ch1_warning_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t *limit);
esp_err_t ina3221_set_ch1_warning_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t limit);
esp_err_t ina3221_get_ch2_critical_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t *limit);
esp_err_t ina3221_set_ch2_critical_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t limit);
esp_err_t ina3221_get_ch2_warning_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t *limit);
esp_err_t ina3221_set_ch2_warning_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t limit);
esp_err_t ina3221_get_ch3_critical_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t *limit);
esp_err_t ina3221_set_ch3_critical_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t limit);
esp_err_t ina3221_get_ch3_warning_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t *limit);
esp_err_t ina3221_set_ch3_warning_limit(i2c_master_dev_handle_t *ina3221Handle, uint16_t limit);

#endif