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
mkdir -p ~/ai_vision_model_rockchip_deploy/source/gst-libs/build
cd ~/ai_vision_model_rockchip_deploy/source/gst-libs/build
cmake ..
make -j 6
sudo cp libgstinferdatameta.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0
```

## 3.2 Face detect
```
mkdir -p ~/ai_vision_model_rockchip_deploy/source/gst-rkfacedetect/build
cd ~/ai_vision_model_rockchip_deploy/source/gst-rkfacedetect/build
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
mkdir -p ~/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build
cd ~/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build
cmake ..
make -j 6
sudo cp libgstrkfacevectorize.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0
```

## 3.4 Face enroll new user
```
mkdir -p ~/ai_vision_model_rockchip_deploy/source/gst-rkfaceenroll/build
cd ~/ai_vision_model_rockchip_deploy/source/gst-rkfaceenroll/build
cmake ..
make -j 6
sudo cp libgstrkfaceenroll.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0
```

## 3.5 Face Bounding Box draw
```
mkdir -p ~/ai_vision_model_rockchip_deploy/source/gst-rkbboxdraw/build
cd ~/ai_vision_model_rockchip_deploy/source/gst-rkbboxdraw/build
cmake ..
make -j 6
sudo cp libgstrkbboxdraw.so /usr/lib/aarch64-linux-gnu/gstreamer-1.0/
```

## 3.6 Full flow test
- Enroll new users
```
gst-launch-1.0 rkv4l2src device=/dev/video4 ! video/x-raw,width=640,height=480,framerate=10/1 \
! videoconvert ! video/x-raw,width=640,height=480,format=RGB ! queue \
! rkfacedetect width=640 height=480 using_gpu=false silent=true \
! tee name=videoTee \
    videoTee.src_0 ! queue ! rkbboxdraw ! kmssink \
    videoTee.src_1 ! queue ! rkfacevectorize width=640 height=480 using_gpu=false silent=true \
                   ! queue ! rkfaceenroll file_path="./test_user" user_name="hiep" \
                   ! fakesink
```
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

- Test image
```
gst-launch-1.0 filesrc location=~/ai_vision_model_rockchip_deploy/test_data/face_640_480.jpeg ! jpegdec \
! videoconvert ! video/x-raw,width=640,height=480,format=RGB ! queue \
! imagefreeze ! autovideosink


gst-launch-1.0 filesrc location=~/ai_vision_model_rockchip_deploy/test_data/face_640_480.jpeg ! jpegdec ! imagefreeze \
! videoconvert ! video/x-raw,width=640,height=480,format=RGB ! queue \
! rkfacedetect width=640 height=480 using_gpu=false \
! tee name=videoTee \
    videoTee.src_0 ! queue ! rkbboxdraw ! kmssink \
    videoTee.src_1 ! queue ! rkfacevectorize width=640 height=480 using_gpu=false ! fakesink
```