# 1. Rockchip package
```
sudo su
apt install -y git autoconf libtool automake build-essential libglib2.0-dev autopoint libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev cmake
apt install -y gstreamer1.0-rockchip1* librockchip-* rockchip-mali* rockchip-mpp*
```

# 2. CSI camera basic testing
- Pi Camera V2 IMX219: https://www.raspberrypi.com/products/camera-module-v2/
- Enable camera module: https://wiki.radxa.com/Rockpi4/MIPI_Camera

- Uncomment `#intfc:dtoverlay=imx219` in `/boot/hw_intfc.conf`, reboot
```
gst-launch-1.0 rkv4l2src device=/dev/video0 ! video/x-raw,format=NV12,width=1920,height=1080, framerate=30/1 ! kmssink
```