Its gonna be lit

## Running main project
The main project is under the opencv_tracker folder.
To build the project:
```
cd opencv_tracker
cmake .
make
./its_lit [serial-device]
```
Running the binary `./its-lit` without the serial device argument will displace
a list of serial device to choose from.

## Tools used
### Hardware
Jetson TX1 used for most of the tracking and computer vision.
Arduino for controlling lights and servos.
Random webcam (Logitech C270) for computer vision.

### Software
OpenCV for general computer vision and tracking
CSerial for communication for controlling the camera / light angle
And lots of C++ crying.

## Future plans
So the code + hardware used are a bit over kill at the moment. The idea here
was that we wanted to be able to use a single Jetson board to power plenty of
lights and handle the tracking. We are currently caping out the framerate of
the webcam and really only need to be taking 1/3 or 1/5 of the frames we are
taking and processig.

## Running the nvidia demo
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
