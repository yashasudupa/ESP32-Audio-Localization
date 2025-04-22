# Sound locator filter

![image](https://github.com/user-attachments/assets/7a0e1f4a-c19f-4895-93ae-e880d86f8ce6)

The goal of this project is to design and implement a power-efficient, multi-sensor fusion system on ESP32 that combines radar and audio data for enhanced environmental monitoring. The system integrates 4G/5G wireless communication and focuses on pre-processing of sensors' data.

## Project Structure
```css
   sound-locator-filter/
   ├── CMakeLists.txt          ← Top-level CMake
   ├── sdkconfig.defaults      ← Optional ESP-IDF default config
   ├── components/             ← Optional, for custom components
   ├── main/
   │   ├── CMakeLists.txt      ← CMake for main app
   │   ├── main.cpp
   │   ├── sound_processor.cpp
   │   ├── radar_filter.cpp
   │   └── sound_processor.hpp
   └── README.md
```

## Hardware Components:
- **Radar Sensors**: Infineon BGT60LTR11AIP, Texas Instruments IWR6843
- **Audio Sensors**: INMP441, SPH0645LM4H (MEMS Microphones)
- **Environmental Sensors**: Bosch BME280 (Temperature, Humidity, Pressure)
- **Wireless Communication**: Quectel EC25/EG25-G (4G LTE)
- **Actuators**: Miniature Mylar Speakers, LRA Motors (Vibratory actuators)

## Software Setup for VSCode

### Prerequisites:
1. **VSCode**: Install Visual Studio Code from [here](https://code.visualstudio.com/).
2. **ESP32 Toolchain**: Follow these instructions to set up the ESP32 toolchain:
   - [ESP32 setup on Windows](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows.html)
   - [ESP32 setup on Linux/macOS](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos.html)
3. **Install Extensions**:
   - ESP-IDF: Install the `Espressif IDF` extension from the VSCode marketplace.
   - CMake Tools: Install the `CMake` extension for CMake integration.

### Setting Up the Project in VSCode:
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/sound-locator-filter.git
   cd sound-locator-filter
2. Modify CMakeLists.txt in the main Component. Edit your CMakeLists.txt file inside the main directory and update the SRCS list to include multiple source files:
   ```CMake
   idf_component_register(SRCS "main.cpp"
                            "file1.cpp"
                            "file2.cpp"
                            "file3.cpp"
                       INCLUDE_DIRS ".")
   set(CMAKE_CXX_STANDARD 17)

3. Ensure Header Files are Accessible
   If your .cpp files include custom headers, make sure their directories are added to INCLUDE_DIRS:
   ```CMake
   idf_component_register(SRCS "main.cpp" "file1.cpp" "file2.cpp"
                       INCLUDE_DIRS "." "include")
   ```
   Place headers in an include/ directory if needed.
4. Open the project folder in VSCode.
5. Configure ESP32 Settings:
   - In the VSCode command palette, run ESP-IDF: Configure ESP-IDF.
   - Follow the prompts to select the ESP32 toolchain and the appropriate target device.
6. Build and Flash:
   - To build the project, open the VSCode command palette and run ESP-IDF: Build.
   - To flash the ESP32, run ESP-IDF: Flash.
7. Build and Flash:
   - To build the project, open the VSCode command palette and run ESP-IDF: Build.

## Serial Monitor Output (ESP32 Boot + Task Logs)
   ```yaml   
   I (0) cpu_start: App cpu up.
   I (436) heap_init: Initializing. RAM available for dynamic allocation...
   I (555) ESP32_Kalman: Initializing I2C master...
   I (560) ESP32_Kalman: Starting I2C capture task...
   I (562) ESP32_Kalman: Initializing LTE...
   I (1562) ESP32_Kalman: Response: OK
   I (2562) ESP32_Kalman: Response: +CPIN: READY
   I (3562) ESP32_Kalman: Response: +CREG: 0,1
   I (4562) ESP32_Kalman: Response: +COPS: 0,0,"Airtel",7
   I (5562) ESP32_Kalman: Response: +CGATT: 1
   I (6562) ESP32_Kalman: Response: OK
   I (7562) ESP32_Kalman: Response: OK
   I (10562) ESP32_Kalman: Response: OK
   I (10564) ESP32_Kalman: LTE Initialization Complete
   
   I (10600) ESP32_Kalman: Sample[0]: 30512
   I (10601) ESP32_Kalman: Sample[1]: 29874
   ...
   I (10620) ESP32_Kalman: Sample[511]: 31209
   
   I (10630) ESP32_Kalman: Sample[0]: 31005
   I (10631) ESP32_Kalman: Sample[1]: 30677
   ...
   I (10650) ESP32_Kalman: Sample[511]: 29584
   
   // Sensor fusion logs (every 500ms)
   I (11000) ESP32_Kalman: Radar: 4.53, Sound: 3.88, Fused: 4.21
   I (11500) ESP32_Kalman: Radar: 5.04, Sound: 4.65, Fused: 4.85
   ```

## RTOS Task Snapshot (Simulated via VS Code Console/Terminal)

   ```Plaintext   
   Task            Status  Core  Priority  Stack   Task Num
   ----------------------------------------------------------
   main            Running    0     1       3000    0
   LTE Task        Ready      1     5       2300    1
   I2C Capture     Ready      0     1       2800    2
   Sensor Fusion   Ready      1     1       2800    3
   IDLE0           Ready      0     0       2048    4
   IDLE1           Ready      1     0       2048    5
