### 4. simple-3d-ascii-engine

# simple-3d-ascii-engine

A minimal 3D terminal graphics engine written in pure C. It projects and rasterizes a 3D wireframe/solid cube directly into your terminal using ASCII characters and a dynamic directional light source.

## Features
- Real-time 3D projection pipeline (rotation matrices, perspective division, buffer clearing).
- Configurable cube dimensions and camera distance.
- Dynamic directional lighting with character-density shading (`.` `:` `-` `=` `+` `*` `#` `%` `@`).
- Zero external libraries: depends only on the standard C math library (`math.h`).

## Build & Run

**Requirements:** Any standard C compiler (`gcc`, `clang`) and `make`.

```bash
# Clone the repository
git clone [https://github.com/adiyn/simple-3d-ascii-engine.git](https://github.com/adiyn/simple-3d-ascii-engine.git)
cd simple-3d-ascii-engine

# Build
make

# Or compile manually
gcc -O2 main.c -lm -o ascii-engine

# Run
./ascii-engine
```

## License
- see LICENSE

## Author
- Nils Maréchal (@adiyn)
