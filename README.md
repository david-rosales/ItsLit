Its gonna be lit

## Running the demo
```
cd object_tracker_nvxcu
make
./bin/nvx_sample_object_tracker_nvxcu --source="device:///v4l2?index=0"
```

## Beware of a terrible bug
So apparently there is a really weird linking bug do to CMake's configuration file of OpenCV

To patch this bug run these commands
```
cmake -DWITH_CUDA=ON -DCUDA_ARCH_BIN="3.2" -DCUDA_ARCH_PTX="" -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF -DCUDA_USE_STATIC_CUDA_RUNTIME=OFF
ccmake .
```

And then magic happens
