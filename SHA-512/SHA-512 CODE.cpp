#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SHA512_BLOCK_SIZE 128

typedef struct {
    uint8_t data[SHA512_BLOCK_SIZE];
    uint64_t datalen;
    unsigned int bitlen[2];
    uint64_t state[8];
} SHA512_CTX;

#define ROTRIGHT(qword, n) (((qword) >> (n)) | ((qword) << (64 - (n))))

#define SHR(qword, n) ((qword) >> (n))

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define EP0(x) (ROTRIGHT(x, 28) ^ ROTRIGHT(x, 34) ^ ROTRIGHT(x, 39))
#define EP1(x) (ROTRIGHT(x, 14) ^ ROTRIGHT(x, 18) ^ ROTRIGHT(x, 41))
#define SIG0(x) (ROTRIGHT(x, 1) ^ ROTRIGHT(x, 8) ^ SHR(x, 7))
#define SIG1(x) (ROTRIGHT(x, 19) ^ ROTRIGHT(x, 61) ^ SHR(x, 6))

const uint64_t K[80] = {
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    
};

void sha512_transform(SHA512_CTX *ctx, const uint8_t data[]) {
    
    
    
}

void sha512_init(SHA512_CTX *ctx) {
    
    
}

void sha512_update(SHA512_CTX *ctx, const uint8_t data[], size_t len) {
    
    
}

void sha512_final(SHA512_CTX *ctx, uint8_t hash[]) {
	
    
}

void sha512(const uint8_t *data, size_t len, uint8_t hash[]) {
    SHA512_CTX ctx;
    sha512_init(&ctx);
    sha512_update(&ctx, data, len);
    sha512_final(&ctx, hash);
}

int main() {
    char message[] = "SHA-512";
    uint8_t hash[64];  

    sha512((const uint8_t *)message, strlen(message), hash);

    printf("Input: %s\n", message);
    printf("SHA-512 Hash: ");
    for (int i = 0; i < 64; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

