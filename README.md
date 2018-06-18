# 2D Plotter

### Overview:
2D plotter machine which can efficiently print letters and words using a pen. 
We use FT232 to send chars to our STM32. Plotter is build with floor panels and two
frames from CD-ROM drivers.

### Tools:
* Microcontroller STM32F407VG DISCOVERY
* C / C++

### How to run:
1. Compile program in System Workbench for STM32.
2. Open Hercules 3.2.8.
3. Start connection using proper COM port.
4. Write words you want to print on paper.
5. Send those things to STM using SEND button.

### How to compile:
* System Workbench for STM32.

### Attributions:
* Some parts of our code are based on Arduino Stepper Motor original library.

### License:
* GNU LESSER GENERAL PUBLIC LICENSE.

### Credits:
* **Jakub Hamerliński** - [jakubhamer](https://github.com/jakubhamer)
* **Marcin Hradowicz** - [LiLatee](https://github.com/LiLatee)
* **Natalia Gierszewska** - [ngiersz](https://github.com/ngiersz)

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Tomasz Mańkowski
