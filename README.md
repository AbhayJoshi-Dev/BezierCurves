This is a C++ SDL2 Demo, it demonstrate how...

- to apply [De Casteljau's algorithm](https://en.wikipedia.org/wiki/De_Casteljau%27s_algorithm) on quadratic and Cubic [Bézier curves](https://en.wikipedia.org/wiki/B%C3%A9zier_curve).

## Screenshot
![](https://i.imgur.com/UJl4LUn.gif)

## Compiling

Project depends on `SDL2` libs.

### On Windows

Download and unpack devel packages for [SDL2](https://www.libsdl.org/download-2.0.php) and [SDL2_image](https://www.libsdl.org/projects/SDL_image/).\
Set paths to them in `CMakeLists.txt`, see suggested placement in `/external`.\
Use the following commands in project directory to compile the code with CMake..
```bash
mkdir build

cd build

cmake ..

cmake --build .
```
The compiled `.exe` is located in `./build/Debug/`

### On Linux

Install devel packages for `SDL2` and `SDL2_image`.\
Compile with CMake