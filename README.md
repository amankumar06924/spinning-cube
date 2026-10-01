## Terminal Spinning Cube
This project is a simple C program that generates an animation of a 3D spinning cube.
The goal is to understand how a 3D rendering engine works internally without using graphics APIs such as OpenGL, DirectX, Vulkan, or any game engine.
Everything is implemented manually using mathematics and terminal ASCII characters.
Current output renders a rotating ASCII cube inside the terminal.

<!-- ## Source
Perspective projection: From 3D points to 2D - https://medium.com/@danieldoradotalaveron/perspective-projection-from-3d-points-to-2d-ef2557244b5b

Bresenham's Line Generation Algorithm - https://www.tutorialspoint.com/computer_graphics/bresenhams_line_generation_algorithm.htm
 -->
## Note
For the smoothest animation experience, it is recommended to run this project in a Linux terminal or WSL (Windows Subsystem for Linux).
While the project also runs on Windows, Linux terminals generally provide smoother ANSI escape sequence handling and better frame rendering performance for terminal-based animations(gcc cube.c -lm -o cube , ./cube).

## Why this Project?
For fun.

<img width="1920" height="1080" alt="Screenshot_2026-10-01_14_12_02" src="https://github.com/user-attachments/assets/a5233ff0-db35-4ea1-a34d-15d1c8e31ec2" />
