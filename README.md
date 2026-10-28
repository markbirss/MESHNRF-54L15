# MESHNRF-54L15: Meshtastic nRF54 Device (In Development)

> **Note:** The nRF54 architecture was only recently added to Meshtastic and is still in very early experimental development.

The **MESHNRF-54L15** is a custom DIY nRF54 development board utilizing the Holyiot-24005-nRF54L15, RP2040-Zero and Seeed WIO-SX1262 LoRa module (on the bottom of the PCB).

<img width="1042" height="834" alt="image" src="https://github.com/user-attachments/assets/14412b4f-7939-42a0-8bd4-a823099a34e0" />


The RP2040-Zero acts a debugger/programmer and USB Serial interface for the nRF54L15. This DIY Hardware aims to provide a cheaper alternative to the Seeed LoRa Plus kit and or using a NRF54L15-DK.

https://www.seeedstudio.com/LR2021-LoRa-Plus-Evaluation-kit-915Mhz-US-V2-0-p-6698.html

https://www.digikey.co.za/en/products/detail/nordic-semiconductor-asa/NRF54L15-DK/25601516

## 📊 Current Status - 28 Oct 2026 - More updates to follow

awating new revision board after DIO1 was moved to pin 2

PCB's from JLCPCB was received - 2 Layer 50mm x 40 mm - all functions are ok, but board will be revised to move DIO1

using SMD 1206 parts - Resistor, Caps. 3v3 LDO, Buttons, RP2040-Zero, Holyiot-24005, Seeed WIO-SX1262 and some 2.54 Headers

> [!IMPORTANT]
> This platform is in an active testing phase. Contributions and debugging help are highly welcome.

| Feature | Status | Notes |
| :--- | :---: | :--- |
| **System Board ** |  | System boots successfully. |
| **Firmware Flasing** |  | Working via RP2040-Zero or CMSIS-DAP |
| **Button** |  | Working |
| **UART** |  | Working |
| **Bluetooth** |  | Working |
| **LoRa Radio** |  | Working |
| **I2C Display** |  | Working |
| Stable | ⚠️ | Some bugs have been fixed |

### 🔍 Known Issues & Technical Debugging
* The target is not stable and is currently being investigated under the new nRF54 architecture stack.

---

## 🛠️ Development & Contribution Options

If you want to contribute to the development of this project, you can use the following hardware alternatives:

### 1. Alternative Core & LoRa Configurations
* **Dev Board:** Holyiot-24009 Development Board

The Holyiot-24009 is a low-power development board featuring the Nordic Semiconductor nRF54L15 system-on-chip (SoC) designed for Internet of Things (IoT) and smart home applications

* **Compatible LoRa Radios:** 
  * Waveshare SX1262
  * Seeed WIO-SX1262
  * Waveshare LR1121 
  * *Hardware Link:* [Aliexpress Source](https://www.aliexpress.com/item/1005008993181489.html)

### 2. Flashing & Debugging Setup
For firmware flashing and debugging, you can use a CMSIS-DAP debugger such as:
* Raspberry Pi Debug Probe
* An RP2040 or RP2350 board configured as a debug probe

<img width="800" height="800" alt="Debugging Setup Architecture" src="https://github.com/user-attachments/assets/08de9ea8-0e95-4d37-8ae7-35e1678062ba" />

### Special Thanks to some of the other nRF54 Meshtsatic developers

Development and finding/fixing bugs

| Github name | Link |
| :--- | :---: |
| caveman | [caveman](https://github.com/caveman99) |
| cvaldes | [cvaldes](https://github.com/cvaldess) |
| sussydevil | [@sussydevil](https://github.com/sussydevil) |

---

## ⚠️ Disclaimer

> [!WARNING]
> Use of the resources provided in this repository is entirely at your own risk. I take no responsibility for any hardware damage, malfunctions, or data loss.

---

## ☕ Support My Work

If this open-hardware project brings value to you, please consider supporting my design pipeline!

[![Buy Me A Coffee](https://img.shields.io/badge/buy_me_a_coffee-FFDD00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=black)](https://buymeacoffee.com/mark.birss)
