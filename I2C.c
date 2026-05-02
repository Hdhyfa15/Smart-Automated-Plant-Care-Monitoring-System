#include "i2c.h"

void I2C_Init(void) {
	TWSR = 0x00;   // Prescaler = 1
	TWBR = 0x47;   // Bit rate = 100KHz (?? 16MHz)
	TWCR = (1<<TWEN); // ????? ??? I2C
}

void I2C_Start(void) {
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}

void I2C_Stop(void) {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void I2C_Write(uint8_t data) {
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}