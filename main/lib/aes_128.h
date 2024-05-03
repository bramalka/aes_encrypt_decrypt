#ifndef AES_128_H
#define AES_128_H

#include <stddef.h>
#include <stdint.h> 

void encrypt_data(uint8_t *data, size_t data_len, uint8_t *key, size_t key_len, uint8_t *encrypted_data);
void decrypt_data(uint8_t *data, size_t data_len, uint8_t *key, size_t key_len, uint8_t *decrypted_data);

#endif /* AES_128_H */