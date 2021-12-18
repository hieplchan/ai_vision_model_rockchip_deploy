# 1. Board first run
- Debian OS: https://wiki.radxa.com/Rockpi4/getting_started
- Default user: rock/rock
- Wifi setting: https://wiki.radxa.com/Rockpi4/Debian#WIFI_Connection 

```
sudo apt update && sudo apt upgrade
sudo apt install -y wget git autoconf libtool automake build-essential libglib2.0-dev autopoint libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev cmake ffmpeg opencl-headers xfce4-power-manager curl make g++ unzip libfreeimage-dev libglew-dev
```
- Using `xfce4-power-manager` to turn off power saving

# 2. OpenGL - OpenCL Test
- Using glmark2-es2-drm: https://wiki.radxa.com/Rockpi4/Debian#Test_OpenGL_ES
- Using clpeak: https://wiki.radxa.com/Rockpi4/dev/install-opencl#Sanity_Checkout_with_clpeak

# 3. USB Camera
```
sudo apt install -y gstreamer1.0-rockchip1* librockchip-* rockchip-mpp*
gst-launch-1.0 rkv4l2src device=/dev/video4 ! videoconvert ! kmssink
gst-launch-1.0 rkv4l2src device=/dev/video4 ! videoconvert ! jpegenc ! multifilesink location=image_%06d.jpg
```

# 4. OpenCV build
- Guide: https://wiki.radxa.com/Rockpi4/dev/build-opencv