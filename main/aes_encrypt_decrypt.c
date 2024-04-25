#include "aes/esp_aes.h"
#include <stdio.h>

uint8_t encrypted_data[64];

void encrypt_data(uint8_t *data, size_t data_len, uint8_t *key, size_t key_len) {
    if (key_len != AES_128_KEY_BYTES) {//data_len != AES_BLOCK_BYTES || 
        printf("Error: Wrong size\n");
        return;
    }

    printf("Raw Data:\n");
    for (int i = 0; i < data_len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");

    esp_aes_context aes_ctx;
    esp_aes_init(&aes_ctx);

    esp_aes_setkey(&aes_ctx, key, key_len * 8);

    // esp_aes_encrypt(&aes_ctx, data, data);
    printf("Encrypted Data:\n");   
    for (int i = 0; i < 64; i += 16) {
        esp_aes_crypt_ecb(&aes_ctx, ESP_AES_ENCRYPT, &data[i], &encrypted_data[i]);
    }

    for (int i = 0; i < 64; i++) {
        printf("%02x ", encrypted_data[i]);
    }
    printf("\n");

    esp_aes_free(&aes_ctx);
}

void decrypt_data(uint8_t *data, size_t data_len, uint8_t *key, size_t key_len) {
    if (key_len != AES_128_KEY_BYTES) {
        printf("Error: Wrong size\n");
        return;
    }

    esp_aes_context aes_ctx;
    esp_aes_init(&aes_ctx);

    esp_aes_setkey(&aes_ctx, key, key_len * 8);

    printf("Data yang Telah Didekripsi:\n");
    for (int i = 0; i < 64; i += 16) {
        esp_aes_crypt_ecb(&aes_ctx, ESP_AES_DECRYPT, &data[i], &data[i]);
    }    
         
    for (int i = 0; i < 64; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");

    esp_aes_free(&aes_ctx);
}

void app_main() {
    // Data
    uint8_t data[64] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
                        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
                        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
                        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F};

    // Key
    uint8_t encrypt_key[AES_128_KEY_BYTES] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x15, 0x87, 0xca, 0x47, 0xd8};

    uint8_t decrypt_key[AES_128_KEY_BYTES] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x15, 0x87, 0xca, 0x47, 0xd8};

    // Encrypt
    encrypt_data(data, 64, encrypt_key, AES_128_KEY_BYTES);

    printf("Encrypted Data Saved:\n");
    for (int i = 0; i < 64; i++) {
        printf("%02x ", encrypted_data[i]);
    }
    printf("\n");

    // Decrypt
    decrypt_data(encrypted_data, 64, decrypt_key, AES_128_KEY_BYTES);
}
