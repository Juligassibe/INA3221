#include "ina3221.h"

static const char *tag = "ina3221.c";

esp_err_t ina3221_get_config(i2c_master_dev_handle_t *ina3221Handle, uint16_t *config) {
    esp_err_t error;

    uint8_t address = INA_CONFIG;
    uint8_t rxdata[2] = {0};

    // Primero debo escribir direccion del registro a leer y el sensor responde con el valor de ese registro
    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, 2, 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer configuración: %s", esp_err_to_name(error));
        return error;
    }

    // El sensor primero envia MSB y luego LSB
    *config = (rxdata[0] << 8) | rxdata[1];

    return ESP_OK;
}

esp_err_t ina3221_set_config(i2c_master_dev_handle_t *ina3221Handle, uint16_t config) {
    esp_err_t error;

    // Trama: SLAVE_ADDR - REG_ADDR - MSB - LSB
    // En este buffer va: REG_ADDR - MSB - LSB
    uint8_t txdata[3] = {INA_CONFIG, (uint8_t)(config >> 8), (uint8_t)(config & 0xFF)};

    error = i2c_master_transmit(*ina3221Handle, txdata, sizeof(txdata), 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al escribir configuración: %s", esp_err_to_name(error));
        return error;
    }

    printf("Configuracion grabada: %d\n", config);

    return ESP_OK;
}

esp_err_t ina3221_get_ch1_shunt(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch1Shunt) {
    esp_err_t error;

    uint8_t address = CH1_SHUNT;
    uint8_t rxdata[2] = {0};

    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, sizeof(rxdata), 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer voltaje shunt CH1: %s", esp_err_to_name(error));
        return error;
    }

    *ch1Shunt = ((rxdata[0] << 8) | rxdata[1]) >> 3;

    return ESP_OK;
}

esp_err_t ina3221_get_ch1_bus(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch1Bus) {
    esp_err_t error;

    uint8_t address = CH1_BUS;
    uint8_t rxdata[2] = {0};

    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, sizeof(rxdata), 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer voltaje del bus CH1: %s", esp_err_to_name(error));
        return error;
    }

    *ch1Bus = ((rxdata[0] << 8) | rxdata[1]) >> 3;

    return ESP_OK;
}

esp_err_t ina3221_get_ch2_shunt(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch2Shunt) {
    esp_err_t error;

    uint8_t address = CH2_SHUNT;
    uint8_t rxdata[2] = {0};

    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, sizeof(rxdata), 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer voltaje shunt CH2: %s", esp_err_to_name(error));
        return error;
    }

    *ch2Shunt = ((rxdata[0] << 8) | rxdata[1]) >> 3;

    return ESP_OK;
}

esp_err_t ina3221_get_ch2_bus(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch2Bus) {
    esp_err_t error;

    uint8_t address = CH2_BUS;
    uint8_t rxdata[2] = {0};

    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, sizeof(rxdata), 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer voltaje del bus CH2: %s", esp_err_to_name(error));
        return error;
    }

    *ch2Bus = ((rxdata[0] << 8) | rxdata[1]) >> 3;

    return ESP_OK;
}

esp_err_t ina3221_get_ch3_shunt(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch3Shunt) {
    esp_err_t error;

    uint8_t address = CH3_SHUNT;
    uint8_t rxdata[2] = {0};

    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, sizeof(rxdata), 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer voltaje shunt CH3: %s", esp_err_to_name(error));
        return error;
    }

    *ch3Shunt = ((rxdata[0] << 8) | rxdata[1]) >> 3;

    return ESP_OK;
}

esp_err_t ina3221_get_ch3_bus(i2c_master_dev_handle_t *ina3221Handle, int16_t *ch3Bus) {
    esp_err_t error;

    uint8_t address = CH3_BUS;
    uint8_t rxdata[2] = {0};

    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, sizeof(rxdata), 10);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer voltaje del bus CH3: %s", esp_err_to_name(error));
        return error;
    }

    *ch3Bus = ((rxdata[0] << 8) | rxdata[1]) >> 3;

    return ESP_OK;
}


