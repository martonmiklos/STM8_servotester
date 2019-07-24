#ifndef CONFIG_SMT8_H
#define CONFIG_SMT8_H

#include <stdint.h>

/*
 * EEPROM MAP:

 * */
enum EEAddrMap {
    EEAddr_Normal_Bot = 0,
	EEAddr_Normal_Top = 2,
	EEAddr_DJI_Bot = 4,
	EEAddr_DJI_Top = 6
};

void EEWriteU8(uint16_t address, uint8_t value);
#define EEReadU8(address) (*((uint8_t *)(0x4000 + address)))

void EEWriteU16(uint16_t address, uint16_t value);
#define EEReadU16(address) (*((uint16_t *)(0x4000 + address)))
uint16_t EEReadU16WithDefVal(uint16_t address, uint16_t def);
uint16_t EEReadU16WithDefValAndRange(uint16_t address, uint16_t def, uint16_t min, uint16_t max);


#endif // CONFIG_SMT8_H
