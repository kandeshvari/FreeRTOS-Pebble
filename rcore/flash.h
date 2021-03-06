#pragma once
/* flash.h
 * routines for [...]
 * RebbleOS
 *
 * Author: Barry Carter <barry.carter@gmail.com>
 */

/* flash regions have moved to platform.h / platform_config.h */

#include "driver.h"
#include "appmanager.h"

#define RES_COUNT           0x00
#define RES_CRC             0x04
#define RES_TABLE_START     0x0C


/*
 
 @4c
*/
typedef struct ResourceHeader {
    char resource_name[13];
    uint32_t resource_list_count;
    uint32_t resource_list_crc_maybe;
    uint32_t unknownoffset;
} __attribute__((__packed__)) ResourceHeader;
 

typedef void (*hw_flash_read_bytes_t)(uint32_t address, uint8_t *buffer, size_t length);

typedef struct hw_driver_ext_flash_t {
    struct driver_common_t common_info;
    hw_flash_read_bytes_t read_bytes;
    // get flash size too
    // and others
} hw_driver_ext_flash_t;


void flash_test(uint16_t resource_id);
void flash_init(void);
void flash_read_bytes(uint32_t address, uint8_t *buffer, size_t num_bytes);
void flash_dump(void);
