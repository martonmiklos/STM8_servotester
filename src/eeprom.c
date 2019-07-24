#include "eeprom.h"

#include "iostm8s003f3.h"

void EEWriteU8(uint16_t address, uint8_t value)
{
    //  Check if the EEPROM is write-protected.  If it is then unlock the EEPROM.
    if (FLASH_IAPSR_bits.DUL == 0) {
        FLASH_DUKR = 0xAE;
        FLASH_DUKR = 0x56;
    }

    //  Write the data to the EEPROM.
	address += 0x4000;
    (*(uint8_t *)address) = value;

    //  Now write protect the EEPROM.
    FLASH_IAPSR_bits.DUL = 0;
}

void EEWriteU16(uint16_t address, uint16_t value)
{
    //  Check if the EEPRO M is write-protected.  If it is then unlock the EEPROM.
    if (FLASH_IAPSR_bits.DUL == 0) {
        FLASH_DUKR = 0xAE;
        FLASH_DUKR = 0x56;
    }

    //  Write the data to the EEPROM.
	address += 0x4000;
    (*(uint16_t *)address) = value;

    //  Now write protect the EEPROM.
    FLASH_IAPSR_bits.DUL = 0;
}

uint16_t EEReadU16WithDefVal(uint16_t address, uint16_t def)
{
	uint16_t ret = EEReadU16(address);
	return (ret == 0xFFFF ? def : ret);
}

uint16_t EEReadU16WithDefValAndRange(uint16_t address, uint16_t def, uint16_t min, uint16_t max)
{
	uint16_t ret = EEReadU16(address);
	return 
		(ret < min ? min :
			(ret > max ? max :
				(ret == 0xFFFF ? def : ret)));
}

