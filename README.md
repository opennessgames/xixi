<!--
 * @Author: xixi_
 * @Date: 2024-11-03 19:34:53
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-09 03:34:47
 * @FilePath: /FHMF/src/Modules/xixi/README.md
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved. 
-->

# xixi Library

## Introduction
The xixi library provides a variety of features, including:
- **JSON Parsing and Generation**: Easily parse and generate JSON data.
- **SQLite3**: Support for SQLite3 database operations.
- **UUID Generation**: Generate unique identifiers (UUIDs).
- **Stack Implementation**: A standard stack data structure.
- **DynamicStack**: A dynamic version of the stack with automatic resizing.
- **2048 Game**: A fun implementation of the popular 2048 game.
- **NumberHuarong**: A puzzle game for number rearrangement.
- **Sudoku**: Solve and generate Sudoku puzzles.
- **URL Encoding/Decoding**: Encode and decode URLs for safe transmission.
- **CRC32 Calculation**: Calculate the CRC32 checksum for data verification.
- **Base64**: Encode and decode data in Base64 format.
- **Algebra**: Perform basic algebraic operations and calculations.

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
   #include <xixi/UUID.h>
   ```
2. **Use the following code to generate a UIID:**
   ```c
   int main() {
       char *uuid = XIXI_GetUUID();
       printf("%s\n", uuid);
       free(uuid);
       return 0;
   }
   ```
3. **Compile the code:**
   ```bash
   gcc uuid.c -o uuid -lxixi
   ```

## License

- **cJSON**: Distributed under the [MIT License](https://opensource.org/licenses/MIT), as described in the [cJSON GitHub repository](https://github.com/DaveGamble/cJSON).
- **JSON.lua**: Distributed under the [Creative Commons Attribution 3.0 Unported License (CC BY 3.0)](https://creativecommons.org/licenses/by/3.0/), as described in the [JSON.lua GitHub repository](https://github.com/tiye/json-lua).
- **SQLite**: Distributed under the [MIT License](https://opensource.org/licenses/MIT), as described on the [SQLite website](https://www.sqlite.org/download.html).