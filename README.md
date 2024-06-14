# Pico Bootsel Button

This library provides a function for reading the state of the builtin boot-select button on the Raspberry Pi Pico.

## 🛠️ Setup

### 1. Add the Repository as a Submodule
```bash
git submodule add https://github.com/Danielaca18/pico-bootsel-btn.git
```

### 2. Include the Library
Include the library in your project by adding the following line to your project cmake:
```cmake
add_subdirectory(pico-bootsel-btn)
target_link_libraries(your_project bootsel_btnlib)
```

## 💼 License
This project is licensed under the [MIT License](LICENSE), which is a permissive open-source license that allows you to use, modify, and distribute the code for both commercial and non-commercial purposes. You can find the full text of the license in the [LICENSE](LICENSE) file.