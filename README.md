# Bézier curves

This is a C++ SDL2 Demo, it demonstrate how...
- to apply [De Casteljau's algorithm](https://en.wikipedia.org/wiki/De_Casteljau%27s_algorithm) on quadratic and Cubic [Bézier curves](https://en.wikipedia.org/wiki/B%C3%A9zier_curve).

## Demo

![](https://i.imgur.com/UJl4LUn.gif)

## Build Instructions

- Requirements
  - Git
  - CMake
  - C++ Compiler

- Steps

    ```cmd
    # Clone this project along with submodules
    $ git clone --recursive https://github.com/AbhayJoshi-Dev/BezierCurves

    # Go to project root
    $ cd BezierCurves

    # Pull SDL and SDL_image as submodule (if you cloned without --recursive flag)
    $ git submodule update --init --recursive

    # Create a folder for build
    $ mkdir build

    # Go to build folder
    $ cd build

    # Generate project files
    $ cmake ..
    ```

- This will generate project files using default cmake generator for your platform. For example:

  - on `Windows` with `Visual Studio` installed, it will generate a `.sln`
  - on `Linux` with `make` installed, it will generate a `Makefile`
  - on `Mac` with `xcode` installed, it will generate a `.xcodeproj`