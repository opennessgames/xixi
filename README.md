<!--
 * @Author: xixi_
 * @Date: 2024-11-03 19:34:53
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-03 20:26:16
 * @FilePath: /FHMF/src/Modules/xixi/README.md
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved. 
-->

# xixi Library

## Introduction
The xixi library provides a variety of features, including:
- **JSON Parsing and Generation**
- **UIID Generation**
- **Stack Implementation**
- **2048 Game**
- **URL Encoding/Decoding**
- **CRC32 Calculation**

## Compilation and Installation

### Prerequisites
No external dependencies are required.

### Installation Steps
1. **Clone the repository:**
   ```bash
   git clone https://github.com/opennessgames/xixi.git
   ```
2. **Navigate to the project directory:**
   ```bash
   cd xixi
   ```
3. **Build the library:**
   ```bash
   cmake . && make
   ```
4. **Install the library:**
   ```bash
   sudo make install
   ```

## Quick Start

### Example: Generating a UIID
1. **Include the header file:**
   ```c
   #include <xixi/UIID.h>
   ```
2. **Use the following code to generate a UIID:**
   ```c
   int main() {
       char *uiid = XIXI_GetUIID();
       printf("%s\n", uiid);
       free(uiid);
       return 0;
   }
   ```
3. **Compile the code:**
   ```bash
   gcc uiid.c -o uiid -lxixi
   ```

## License
- **cJSON**: Distributed under the [MIT License](https://github.com/DaveGamble/cJSON)