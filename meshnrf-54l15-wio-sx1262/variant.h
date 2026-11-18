#pragma once

/*
 * Holyiot-24009 Dev Board with an SX1262/WIO-SX1262 or WS_LR1121 - https://www.aliexpress.com/item/1005008993181489.html
 *
 * This header shadows the framework's variants/nrf54l15dk/variant.h, so it carries the core
 * pin table definitions as well. Arduino pin = physical GPIO: P0.n = n, P1.n = 32+n, P2.n = 64+n.
 *
// 					Holyiot-24009 Dev Board
//				_____________________________________
//				  RESET	     nRF54 Chip B3  B1
//				        5
//				  L0 L1	1		B2  B0
//				  L2 L3	L
//				nFC  	4		SWDIO
//					5
//				VDD	F		D D O K	VDD
//				GND	R		D N I L	GND
//				NC	n		V G D C	P0.04 Button3	I2C_SCL
//				P1.14	-	LED3	    W W	P0.03		I2C_SDA
//		PIN_BUTTON1	P1.13	9	Button0	    S S	P0.02		LORA_DIO1	Purple
//		PIN_SERIAL1_RX	P1.12	0  TxD			P0.01
//		PIN_SERIAL1_TX	P1.11	0  RXD			P0.00
//		PIN_LED1	P1.10	4	LED1		P2.10	74	LORA_BUSY	Brown
//				P1.09	2	Button1	LED0	P2.09	73	LED2			LED_PRIMARY_PIN
//				P1.08	-	Button2		P2.08	72	LORA_RESET	White
//				P1.07	T	  TOP	LED2	P2.07	71	RF_SW		Gray	WIO-SX1262
//				P1.06	O			P2.06	70
//		PIN_SERIAL2_RX	P1.05	I			P2.05	69	FLASH_CS	Orange
//		PIN_SERIAL2_TX	P1.04	Y			P2.04	68	MISO		Green
//				P1.03	L			P2.03	67	FLASH_WP
//				P1.02	O			P2.02	66	MOSI		Blue
//				NC	H	     GND  RESET	P2.01	65	SCK		Yellow
//				NC		     5V   VDD	P2.00	64	FLASH_RESET
//				GND	  SW	     3.3V NC	GND		GND		Black
//				VDD	ON OFF	USB-C		VDD		3V3		Red
//
*/

#define VARIANT_MCK (128000000ul)
#define USE_LFXO

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PINS_COUNT (96)
#define NUM_DIGITAL_PINS (96)
#define NUM_ANALOG_INPUTS (8)
#define NUM_ANALOG_OUTPUTS (0)
#define ADC_RESOLUTION 14

// LEDs (active low): LED1 P1.10 status, LED0 P2.09
#define PIN_LED1 42	//P1.10
#define PIN_LED2 73	//P2.09
#define LED_BUILTIN PIN_LED1
#define LED_STATE_ON 0

// BTN0 P1.13 (active low)
#define PIN_BUTTON1 45	//P1.13
#define BUTTON_NEED_PULLUP

#define USE_SH1107

//#define USE_SSD1306
//#define USE_SH1107_128_128

// Serial1: VCOM0 of the on-board J-Link (UARTE20): TX P1.11, RX P1.12
#define PIN_SERIAL1_RX 44	//P1.12
#define PIN_SERIAL1_TX 43	//P1.11
#define SERIAL1_UARTE NRF_UARTE20
#define SERIAL1_IRQN SERIAL20_IRQn
#define SERIAL1_IRQ_HANDLER SERIAL20_IRQHandler

// Serial2 (UARTE21, serial module): RX P1.05, TX P1.06; only P1 pins can be assigned to it
#define PIN_SERIAL2_RX 37	//P1.05
#define PIN_SERIAL2_TX 38	//P1.06
#define SERIAL2_UARTE NRF_UARTE21
#define SERIAL2_IRQN SERIAL21_IRQn
#define SERIAL2_IRQ_HANDLER SERIAL21_IRQHandler

// SPI (SPIM00) for the ESX1262
#define SPI_INTERFACES_COUNT 1
#define PIN_SPI_MISO 68		//P2.04
#define PIN_SPI_MOSI 66		//P2.02
#define PIN_SPI_SCK 65		//P2.01
static const uint8_t SS = 69;	//P2.05
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;

// I2C (TWIM30): SDA P0.03, SCL P0.04, external 4.7k pull-ups required
#define WIRE_INTERFACES_COUNT 1
#define PIN_WIRE_SDA 3		//P0.03
#define PIN_WIRE_SCL 4		//P0.02
#define WIRE_TWIM NRF_TWIM30
#define WIRE_TWIS NRF_TWIS30
#define WIRE_IRQN SERIAL30_IRQn
#define WIRE_IRQ_HANDLER SERIAL30_IRQHandler

#ifdef __cplusplus
}
#endif

#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS

#define LORA_SCK PIN_SPI_SCK
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_MISO PIN_SPI_MISO
#define LORA_CS SS

#define LORA_DIO0 RADIOLIB_NC
#define LORA_RESET 72  // RESET	//P2.08
#define LORA_DIO1 2    // DIO1	//P0.02
#define LORA_DIO2 74   // BUSY	//P2.10
#define LORA_DIO3 RADIOLIB_NC

#define USE_SX1262
//#define USE_LR1121

// SX1262
#ifdef USE_SX1262
#define SX126X_CS SS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
// RXEN is held high permanently (LNA always on); TXEN follows DIO2.
#define SX126X_RXEN 71	//P2.07
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif

#ifdef USE_LR1121
#define LR1121_IRQ_PIN LORA_DIO1
#define LR1121_NRESET_PIN LORA_RESET
#define LR1121_BUSY_PIN LORA_DIO2
#define LR1121_SPI_NSS_PIN SS
#define LR1121_SPI_SCK_PIN SCK
#define LR1121_SPI_MOSI_PIN MOSI
#define LR1121_SPI_MISO_PIN MISO
#define LR11X0_DIO3_TCXO_VOLTAGE 1.8
#define LR11X0_DIO_AS_RF_SWITCH
#define IRQ_DIO_NUM 8
#endif

