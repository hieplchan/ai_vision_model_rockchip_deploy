# 1. Setup
- Create model path
```
sudo mkdir /opt/model
sudo chmod 777 /opt/model
```
- Copy libMNN.so to system
```
sudo cp 3rdparty/mnn/libMNN.so /usr/local/lib
sudo cp 3rdparty/mnn/libMNN_cL.so /usr/local/lib
```

# 2. Face Detect
- Pretrained model: https://github.com/Linzaer/Ultra-Light-Fast-Generic-Face-Detector-1MB

## 2.1 Setup
- Copy model to `/opt`
```
cp model/facedetect/* /opt/model
cp model/facevectorize/* /opt/model
```

## 2.2 Compile & test
- Compile
```
cd gst-facedetect-mnn
mkdir build && cd build
cmake ..
make -j 6
```
- Test
```
./rk3399-facedetect /opt/model/RFB-320.mnn /home/rock/data/hiep.jpg
```

# 3. Gstreamer plugin
- Camera video convert test
```
gst-launch-1.0 rkv4l2src device=/dev/video4 ! video/x-raw,width=640,height=480,framerate=10/1 \
! videoconvert ! video/x-raw,width=640,height=480,format=RGB ! queue \
! kmssink
```

## 3.1 Infer meta data
```
mkdir -p /home/rock/workspace/rockchip-deeplearning-practices/source/gst-libs/build
cd /home/rock/workspace/rockchip-deeplearning-practices/source/gst-libs/build
cmake ..
make -j 6
sudo cp libgstinferdatameta.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0
```

## 3.2 Face detect
```
mkdir -p /home/rock/workspace/rockchip-deeplearning-practices/source/gst-rkfacedetect/build
cd /home/rock/workspace/rockchip-deeplearning-practices/source/gst-rkfacedetect/build
cmake ..
make -j 6
sudo cp libgstrkfacedetect.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0
```

```
gst-launch-1.0 rkv4l2src device=/dev/video4 ! video/x-raw,width=640,height=480,framerate=10/1 \
! videoconvert ! video/x-raw,width=640,height=480,format=RGB ! queue \
! rkfacedetect width=640 height=480 using_gpu=false ! queue \
! kmssink
```

## 3.3 Face vectorize
```
mkdir -p /home/rock/workspace/rockchip-deeplearning-practices/source/gst-rkfacevectorize/build
cd /home/rock/workspace/rockchip-deeplearning-practices/source/gst-rkfacevectorize/build
cmake ..
make -j 6
sudo cp libgstrkfacevectorize.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0
```

## 3.4 Face Bounding Box draw
```
mkdir -p /home/rock/workspace/rockchip-deeplearning-practices/source/gst-rkbboxdraw/build
cd /home/rock/workspace/rockchip-deeplearning-practices/source/gst-rkbboxdraw/build
cmake ..
make -j 6
sudo cp libgstrkbboxdraw.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0/
```

## 3.4 Full flow test
- Live debug video
```
gst-launch-1.0 rkv4l2src device=/dev/video4 ! video/x-raw,width=640,height=480,framerate=10/1 \
! videoconvert ! video/x-raw,width=640,height=480,format=RGB ! queue \
! rkfacedetect width=640 height=480 using_gpu=false \
! tee name=videoTee \
    videoTee.src_0 ! queue ! rkbboxdraw ! kmssink \
    videoTee.src_1 ! queue ! rkfacevectorize width=640 height=480 using_gpu=false ! fakesink
```

- No live video
```
gst-launch-1.0 rkv4l2src device=/dev/video4 ! video/x-raw,width=640,height=480,framerate=10/1 \
! videoconvert ! video/x-raw,width=640,height=480,format=RGB ! queue \
! rkfacedetect width=640 height=480 using_gpu=true ! queue \
! rkfacevectorize width=640 height=480 using_gpu=false \
! fakesink
```