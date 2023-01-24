# FdF - Hive Helsinki / 42Cursus Project

Basic wireframe rendering in 3D using C and [minilibx](https://github.com/dannywillems/minilibx-mac-osx).

![screenshot1](https://i.imgur.com/1AJyVMa.png)
---
### Keybinds

| Keys        | Actions                                         |
| ----------- | ----------------------------------------------- |
| esc         | Exit the program                                |
| i o         | Zoom (i)n / (o)ut (bonus only)                  |
| w a s d q e | Control rotation (bonus only)                   |
| arrow keys  | Control position (bonus only)                   |
| 1           | Set projection style to isometric (bonus only)  |
| 2           | Set projection style to parallel (bonus only)   |

---
### Compilation & Usage

Compiles on MacOS via `make` for the mandatory features, or `make bonus` to include bonus features.
Usage syntax is `./fdf path_to_map`. Many maps to test with are included in the `test_maps` folder. Note that compilation requires an installed version of [minilibx](https://github.com/dannywillems/minilibx-mac-osx).

---
### Bonus features

Compiling the program with `make bonus` adds the following extra features:
- Multicolor rendering
- Multiple projection styles
- Control rotation/position/scale of the projection.

---
### Codestyle disclaimer

42Cursus projects follow the [norminette](https://github.com/42School/norminette) style-guide, intended for educational purposes. The project is written within these limitations.
