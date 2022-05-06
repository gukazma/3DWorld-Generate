# Generate 3D world
This project shows how to use the Stone engine to generate a 3D world

## How to build

```bash
git clone https://github.com/StoneHappy/3DWorld-Generate.git

cd 3DWorld-Generate

mkdir build

cd build 

cmake .. -DCMAKE_TOOLCHAIN_FILE=path to/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=your target triplet

cmake --build ./ --config Release --target Generate3DWorld -j 10
```