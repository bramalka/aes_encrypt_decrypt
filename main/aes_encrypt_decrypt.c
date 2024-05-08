#include "aes/esp_aes.h"
#include <stdio.h>
#include "aes_128.h"
#include <string.h>

#define AES_LEN 50

uint8_t encrypted_data[64];
uint8_t decrypted_data[64];

uint8_t key[AES_128_KEY_BYTES] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x15, 0x87, 0xca, 0x47, 0xd8};

void app_main() {
    uint8_t data[AES_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
                             0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
                             0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
                             0x30, 0x31};

    memset(encrypt_data, 0, 64);

    encrypt_data(data, sizeof(data), key, AES_128_KEY_BYTES, encrypted_data);

    printf("Encrypted Data Saved:\n");
    for (int i = 0; i < 64; i++) {
        printf("%02x ", encrypted_data[i]);
    }
    printf("\n");

    decrypt_data(encrypted_data, sizeof(data), key, AES_128_KEY_BYTES, decrypted_data);

    printf("Decrypted Data:\n");
    for (int i = 0; i < 64; i++) {
        printf("%02x ", decrypted_data[i]);
    }
    printf("\n");
    
}
