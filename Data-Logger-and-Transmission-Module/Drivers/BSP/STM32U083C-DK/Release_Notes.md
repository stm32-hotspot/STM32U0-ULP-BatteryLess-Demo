---
pagetitle: Release Notes for STM32U083C-DK BSP Drivers
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# **Release Notes for STM32U083C-DK BSP Drivers**
Copyright &copy; 2023 STMicroelectronics\
    
[![ST logo](_htmresc/st_logo.png)](https://www.st.com){.logo}
</center>

# Purpose

The BSP (Board Specific Package) drivers are parts of the STM32Cube package based on the HAL drivers and provide a set of high level APIs relative to the hardware components and features in the evaluation boards, discovery kits and nucleo boards coming with the STM32Cube package for a given STM32 series.


The BSP drivers allow a quick access to the boards’ services using high level APIs and without any specific configuration as the link with the HAL and the external components is done in intrinsic within the drivers. 


From project settings points of view, user has only to add the necessary driver’s files in the workspace and call the needed functions from examples. However some low level configuration functions are weak and can be overridden by the applications if user wants to change some BSP drivers default behavior.

*Note that stm32u083c_discovery_conf_template.h file must be copied in user application as
stm32u083c_discovery_conf.h with optional configuration update.*
:::

::: {.col-sm-12 .col-lg-8}
# Update History

::: {.collapse}
<input type="checkbox" id="collapse-section3" checked aria-hidden="true">
<label for="collapse-section3" aria-hidden="true">__V0.3.0 / 13-October-2023__</label>
<div>

## Main Changes

-	Third beta release of __STM32U083C-DK__ BSP drivers in line with STM32Cube BSP drivers development guidelines (UM2298)
-	Updated version to support the __RevB__ version of the __MB1933__ board.

## Dependencies 

- STTS22H Component Driver version V1.4.0

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section2" aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">__V0.2.0 / 28-July-2023__</label>
<div>

## Main Changes

-	Second beta release of __STM32U083C-DK__ BSP drivers in line with STM32Cube BSP drivers development guidelines (UM2298)

## Dependencies 

- STTS22H Component Driver version V1.4.0

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">__V0.1.0 / 28-April-2023__</label>
<div>

## Main Changes

-	First alpha release of __STM32U083C-DK__ BSP drivers in line with STM32Cube BSP drivers development guidelines (UM2298)

## Dependencies 

- STTS22H Component Driver version V1.4.0

</div>
:::

:::
:::

<footer class="sticky">
For complete documentation on <mark>STM32 Microcontrollers</mark> ,
visit: [[www.st.com](http://www.st.com/STM32)]{style="font-color: blue;"}
</footer>
