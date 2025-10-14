#include "ina3221.h"

static const char *tag = "ina3221.c";

esp_err_t ina3221_get_config(i2c_master_dev_handle_t *ina3221Handle, uint16_t *config) {
    esp_err_t error;

    uint8_t address = CONFIG;
    uint8_t rxdata[2] = {0};

    // Primero debo escribir direccion del registro a leer y el sensor responde con el valor de ese registro
    error = i2c_master_transmit_receive(*ina3221Handle, &address, sizeof(address), rxdata, 2, -1);

    if (error != ESP_OK) {
        ESP_LOGE(tag, "Error al leer configuración: %s", esp_err_to_name(error));
        return error;
    }

    // El sensor primero envia MSB y luego LSB
    *config = (rxdata[0] << 8) | rxdata[1];

    return ESP_OK;
}