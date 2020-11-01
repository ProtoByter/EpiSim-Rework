
# EpiSim-Rework

![Build CMake](https://github.com/ProtoByter/EpiSim-Rework/workflows/CMake/badge.svg)

## How to build

1 - Clone the repo with submodules:
`git clone --recurse-submodules https://github.com/protobyter/EpiSim-Rework.git`

2 - Setup the build environment:
 ```
mkdir build 
cd build
```

#### With OpenCL

3 - Run CMake with OpenCL on
```
cmake .. -DOPENCL=yes
```

#### Without OpenCL

3 - Run CMake with OpenCL off
```
cmake ..
```

### Building

4 - Build:
```
make -j<NUMBER OF CORES>
```
