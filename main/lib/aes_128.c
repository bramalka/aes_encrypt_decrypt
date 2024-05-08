#include "aes_128.h"
#include "aes/esp_aes.h"
#include <stdio.h>


void encrypt_data(uint8_t *data, size_t data_len, uint8_t *key, size_t key_len, uint8_t *encrypted_data) {
    if (key_len != AES_128_KEY_BYTES) {
        printf("Error: Wrong key size\n");
        return;
    }

    esp_aes_context aes_ctx;
    esp_aes_init(&aes_ctx);

    esp_aes_setkey(&aes_ctx, key, key_len * 8);

    for (int i = 0; i < data_len; i += 16) {
        esp_aes_crypt_ecb(&aes_ctx, ESP_AES_ENCRYPT, &data[i], &encrypted_data[i]);
    }

    esp_aes_free(&aes_ctx);
}

void decrypt_data(uint8_t *data, size_t data_len, uint8_t *key, size_t key_len, uint8_t *decrypted_data) {
    if (key_len != AES_128_KEY_BYTES) {
        printf("Error: Wrong key size\n");
        return;
    }

    esp_aes_context aes_ctx;
    esp_aes_init(&aes_ctx);

    esp_aes_setkey(&aes_ctx, key, key_len * 8);

    for (int i = 0; i < data_len; i += 16) {
        esp_aes_crypt_ecb(&aes_ctx, ESP_AES_DECRYPT, &data[i], &decrypted_data[i]);
    }    
         
    esp_aes_free(&aes_ctx);
}
