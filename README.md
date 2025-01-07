# STM32-Hotspot/ULP & battery less demo with STM32U0

### Related [**STM32 wiki article**](https://wiki.st.com/stm32mcu/wiki/How_to_develop_ultra-low-power_and_battery_less_demo_with_STM32U0_MCUs).

This project is the project of the **battery less demo with STM32U0**.

It contains two main sub-projects:
- The **Data-Logger-and-Transmission-Module** sub-project, developed with **IAR 9.30**.
- The **Receiver-and-Display-Module** sub-project, developed with **IAR 8.50**.

> [!NOTE]
> The TouchGFX middleware library is not included in the **Receiver-and-Display-Module** sub-project for licensing reasons. The steps to add this middleware library are detailed in the wiki article.

It also contains one additional project:
- The full project of the TouchGFX Designer Display (**XTRA_Display-TouchGFX-project**), which the display part of the **Receiver-and-Display-Module** is based on. It has been developed with **TouchGFX Designer 4.24.0**.

For more information, refer to  [**How to develop ultra-low-power and battery less demo with STM32U0 MCUs**](https://wiki.st.com/stm32mcu/wiki/How_to_develop_ultra-low-power_and_battery_less_demo_with_STM32U0_MCUs), the related wiki article.

## Hardware used

**Data-Logger-and-Transmission-Module**:

| Name             | Board   | Documentation                                             |
| ---------------- | ------- | --------------------------------------------------------- |
| STM32U083C-DK    | MB1933B | https://www.st.com/en/evaluation-tools/stm32u083c-dk.html |
| X-Nucleo-S2828A2 | MB1642D | https://www.st.com/en/ecosystems/x-nucleo-s2868a2.html    |


**Receiver-and-Display-Module**

| Name             | Board    | Documentation                                                |
| ---------------- | -------- | ------------------------------------------------------------ |
| Nucleo-U083RC    | MB1932B  | https://www.st.com/en/evaluation-tools/nucleo-u083rc.html    |
| X-Nucleo-GFX01M2 | XS2868V2 | https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html |
| X-Nucleo-S2828A2 | MB1642D  | https://www.st.com/en/ecosystems/x-nucleo-s2868a2.html       |

## Questions & Feedback

Please refer to the [CONTRIBUTING.md](CONTRIBUTING.md) guide.
