# MESHNRF-54L15: Meshtastic nRF54 Device (In Development)

> **Note:** The nRF54 architecture was only recently added to Meshtastic and is still in very early experimental development.

The **MESHNRF-54L15** is a custom DIY nRF54 development board utilizing the Holyiot-24005, an RP2040-Zero, and a WIO-SX1262 LoRa module.

<img width="1042" height="834" alt="MESHNRF-54L15 Hardware Overview" src="https://github.com/user-attachments/assets/3f4774db-9132-49a0-8d04-b96a3562d5d0" />

## 📊 Current Status - 12 Oct 2026 - More updates to follow

> [!IMPORTANT]
> This platform is in an active testing phase. Contributions and debugging help are highly welcome.

| Feature | Status | Notes |
| :--- | :---: | :--- |
| **System Board ** |  | System boots successfully. |
| **Bluetooth** |  | Working |
| **LoRa Radio** |  | Working |
| **I2C Display** |  | Working |
| Stable | ⚠️ | Not yet |

### 🔍 Known Issues & Technical Debugging
* The target is not stable and is currently being investigated under the new nRF54 architecture stack.

---

## 🛠️ Development & Contribution Options

If you want to contribute to the development of this project, you can use the following hardware alternatives:

### 1. Alternative Core & LoRa Configurations
* **Dev Board:** Holyiot-24009 Development Board
* **Compatible LoRa Radios:** 
  * Waveshare SX1262
  * Seeed WIO-SX1262 (or SX121)
  * Waveshare LR1121 
  * *Hardware Link:* [Aliexpress Source](https://www.aliexpress.com/item/1005008993181489.html)

### 2. Flashing & Debugging Setup
For SWDIO flashing and debugging, you can use a CMSIS-DAP debugger such as:
* Raspberry Pi Debug Probe
* An RP2040 or RP2350 board configured as a debug probe

<img width="800" height="800" alt="Debugging Setup Architecture" src="https://github.com/user-attachments/assets/08de9ea8-0e95-4d37-8ae7-35e1678062ba" />

---

## ⚠️ Disclaimer

> [!WARNING]
> Use of the resources provided in this repository is entirely at your own risk. I take no responsibility for any hardware damage, malfunctions, or data loss.

---

## ☕ Support My Work

If this open-hardware project brings value to you, please consider supporting my design pipeline!

[![Buy Me A Coffee](https://img.shields.io/badge/buy_me_a_coffee-FFDD00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=black)](https://buymeacoffee.com/mark.birss)
