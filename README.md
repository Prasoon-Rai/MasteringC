# Simple Raylib Paddle Ball

A small C game using `raylib`. The player controls a left-side paddle to bounce a ball. Score increases each time the ball collides with the paddle.

## Requirements

\- macOS  
\- `raylib` installed (Homebrew recommended):  
`bash
brew install raylib`

## Files

\- `main.c` \- main game source  
\- `CMakeLists.txt` (optional) \- CMake build script

## Build (single file)

Compile and link with frameworks (example using `clang`/`gcc`):

\`\`\`bash
clang `pkg-config --cflags raylib` main.c -o paddle_ball `pkg-config --libs raylib` -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
\`\`\`

Or, if `pkg-config` is not available:

\`\`\`bash
clang main.c -o paddle_ball -lraylib -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
\`\`\`

## Build with CMake

Create a simple `CMakeLists.txt` and then:

\`\`\`bash
mkdir build && cd build
cmake ..
make
\`\`\`

(Adjust `CMakeLists.txt` to link `raylib` on your machine.)

## Run

`bash
./paddle_ball
`
