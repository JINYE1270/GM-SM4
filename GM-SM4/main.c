//
//  main.c
//  GM-SM4
//
//  Created by 蒋鹏飞 on 2020/8/21.
//  Copyright © 2020 野尽. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include "sm4.h"

int main()
{
    unsigned char key[16] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10};
    unsigned char input[16] = "hello world!!!";
    unsigned char iv[16] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};
    unsigned char output[16];
    sm4_context ctx;

    // encryto sm4cbc
    sm4_setkey_enc(&ctx, key);
    sm4_crypt_cbc(&ctx, 1, 16, iv, input, output);
    printf("enc CBC:");
    for(int i = 0;i < 16;i++)
        printf("%02x ", output[i]);
    printf("\n");

    // decrypt sm4cbc
    sm4_setkey_dec(&ctx, key);
    sm4_crypt_cbc(&ctx, 0, 16, iv, output, output);
    printf("dec CBC:");
    for(int i = 0;i < 16;i++)
        printf("%02x ", output[i]);
    printf("\n");
    printf("After dec:");
    for(int i = 0;i < 16;i++)
        printf("%c", output[i]);
    printf("\n");
    
    printf("\n--------\n");
    
    // encrypt ecb
    sm4_setkey_enc(&ctx, key);
    sm4_crypt_ecb(&ctx, 1, 16, input, output);
    printf("enc ECB:");
    for(int i = 0;i < 16;i++)
        printf("%02x ", output[i]);
    printf("\n");

    // decrypt ecb
    sm4_setkey_dec(&ctx, key);
    sm4_crypt_ecb(&ctx, 0, 16, output, output);
    printf("dec ECB:");
    for(int i = 0;i < 16;i++)
        printf("%02x ", output[i]);
    printf("\n");
    printf("After dec:");
    for(int i = 0;i < 16;i++)
        printf("%c", output[i]);
    printf("\n");
    
    return 0;
}

