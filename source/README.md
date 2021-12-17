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
## 3.1 Infer meta data
```
sudo cp libgstinferdatameta.so  /usr/lib/aarch64-linux-gnu/gstreamer-1.0
```

## 3.2 Face detect
```
sudo cp libgstrk3399facedetect.so  /usr/lib/aarch64-linux-gnu/gstreamer-1.0

gst-launch-1.0 rkv4l2src device=/dev/video4 \
! videoconvert ! video/x-raw,width=1280,height=720,format=RGB \
! rk3399facedetect width=1280 height=720 \
! autovideosink
```

## 3.3 Face Bounding Box draw
```
sudo cp libgstrkbboxdraw.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0/

gst-launch-1.0 rkv4l2src device=/dev/video4 ! queue \
! videoconvert ! video/x-raw,width=1280,height=720,format=RGB ! queue \
! rk3399facedetect width=1280 height=720 ! queue \
! rkbboxdraw ! queue \
! autovideosink
```