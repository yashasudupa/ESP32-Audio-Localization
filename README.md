# Sound locator filter

![image](https://github.com/user-attachments/assets/7a0e1f4a-c19f-4895-93ae-e880d86f8ce6)

The goal of this project is to design and implement a power-efficient, multi-sensor fusion system on ESP32 that combines radar and audio data for enhanced environmental monitoring. The system integrates 4G/5G wireless communication and focuses on pre-processing of sensors' data.

## Project Structure
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
2. Open the project folder in VSCode.
3. Configure ESP32 Settings:
   - In the VSCode command palette, run ESP-IDF: Configure ESP-IDF.
   - Follow the prompts to select the ESP32 toolchain and the appropriate target device.
4. Build and Flash:
   - To build the project, open the VSCode command palette and run ESP-IDF: Build.
   - To flash the ESP32, run ESP-IDF: Flash.
5. Build and Flash:
   - To build the project, open the VSCode command palette and run ESP-IDF: Build.
