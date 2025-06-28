
---

## Tree

cmake_sample
├── CMakeLists.txt
├── common
│   └── inc
│       └── export.h
├── double_add
│   ├── CMakeLists.txt
│   ├── inc
│   │   └── double_add.h
│   └── src
│       └── double_add.cpp
├── double_subtract
│   ├── CMakeLists.txt
│   ├── inc
│   │   └── double_subtract.h
│   └── src
│       └── double_subtract.cpp
├── double_multiply
│   ├── CMakeLists.txt
│   ├── inc
│   │   └── double_multiply.h
│   └── src
│       └── double_multiply.cpp
├── double_divide
│   ├── CMakeLists.txt
│   ├── inc
│   │   └── double_divide.h
│   └── src
│       └── double_divide.cpp
├── double_operators
│   ├── CMakeLists.txt
│   ├── inc
│   │   └── double_operators.h
│   └── src
│       └── double_operators.cpp
├── double_test
│   ├── CMakeLists.txt
│   └── src
│       └── double_test.cpp
└── readme.md

---

## Build

- **Windows**：
  - `cmake -S . -B build -D BUILD_STATIC=OFF -G "Visual Studio 17 2022"`
  - `cmake --build build`
- **Unix-Like**：
  - `cmake -S . -B build -D BUILD_STATIC=OFF -D CMAKE_BUILD_TYPE=Release`
  - `cmake --build build`

---
