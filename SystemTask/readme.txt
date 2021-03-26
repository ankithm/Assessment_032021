1) fragment@4 -> SPI CS0 connected to Ethernet -> reg = <0>, channel@0
	      -> SPI CS1 connected to TPM -> reg <1>, channel@1
	      -> Ethernet interrupt pin label as in fragment@1 -> P9_25_pinmux
	      -> Ethernet Falling edge Interrupt - 0x2, Raising Edge Interrupt - 0x1
	      -> TPM GPIO reset pin label as in fragment@1 -> P8_18_pinmux

2) fragment@5 ->I2C1 connected to EEPROM at address 0x50 -> reg = <0x50>
	      ->I2C1 connected to RTC at address 0x68 -> reg = <0x68>
	      ->I2C1 connected to TPM at address 0x29 -> reg = <0x29>