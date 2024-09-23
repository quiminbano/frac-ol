# Fract-ol

## Introduction

**Fract-ol** is a graphical project that visualizes famous mathematical fractals. Using this program, you can explore complex fractals like the Mandelbrot set, Julia sets, and Multibrot Mandelbrot and Julia. The goal is to render these fractals interactively, allowing zooming, color changes, and fractal manipulation.

## What are the features I can find in Fract-ol?

- **Mandelbrot Set** visualization
- **Julia Set** visualization (with customizable parameters)
- Zoom functionality to explore fractals in detail
- Color shifting to customize the fractal's appearance (Bonus)
- Optional: Other fractals (Multibrot Mandelbrot, Multibrot Julia)(Bonus)
<p>
  <img src="https://github.com/user-attachments/assets/93eba5c7-fdf8-4e94-8650-a62e95c39922" alt="fract-ol1" width="325"/>
  <img src="https://github.com/user-attachments/assets/3a83ff2f-98ae-487e-a015-e18140aee570" alt="fract-ol2" width="325"/>
</p>

## What do I need to try fract-ol?

- A Unix-based system (Linux or macOS)
- A C compiler (gcc or clang)
- Basic knowledge of fractals and complex numbers

This repository already includes a version of Minilibx to work in macOS. However, if you want to try this project in linux, you can click [here](https://github.com/42Paris/minilibx-linux.git). You have to name the folder minilibx_linux to make it work. Keep in mind that the project was developed in macOS, using the macOS version of minilibx. It can be some compatibility errors trying to build the project in linux.

## How can I get and compile the program?

1. Clone this repository
```bash
git clone https://github.com/quiminbano/fract-ol.git
```
2. In case that you are running the project in macOS, you can skip this step, otherwise you have to clone the latest version of minilibx for linux
```bash
git clone https://github.com/42Paris/minilibx-linux.git minilibx_linux
```
3. Compile the program. If you want to compile the basic version of fract-ol, you should run in your terminal
```bash
make
```
Otherwise, you should run
```bash
make bonus
```

## How can I execute the program?

To execute the program you must pass the fractal's name as an argument. The available fractals are:
- Mandelbrot (passed as mandelbrot)
- Julia (passed as julia)
- Multibrot (passed as multibrot) (Available in bonus)
- Filled_Julia (passed as filled_julia)

In case Julia and Filled_Julia, you must also pass as arguments the coordinates to build the fractal. Keep in mind that, these coordinates must be in the range of -2.0 and 2.0.

Examples:
```bash
./fractol mandelbrot
```
```bash
./fractol julia -0.8 0.1
```