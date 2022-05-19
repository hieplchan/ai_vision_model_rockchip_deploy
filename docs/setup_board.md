# 1. Board first run
- Ubuntu OS: https://wiki.radxa.com/Rockpi4/getting_started
- Default user: rock/rock
- Wifi setting: https://wiki.radxa.com/Rockpi4/Debian#WIFI_Connection

```
sudo apt-get update && sudo apt-get -y upgrade
sudo apt install -y wget cmake git clinfo build-essential

# Add Testing Radxa APT
export DISTRO=focal-testing
echo "deb http://apt.radxa.com/$DISTRO/ ${DISTRO%-*} main" | sudo tee -a /etc/apt/sources.list.d/apt-radxa-com.list
wget -O - apt.radxa.com/$DISTRO/public.key | sudo apt-key add -
sudo apt-get update && sudo apt-get upgrade
sudo apt-get install -y rockchip-overlay

# Install Mali GPU lib
sudo apt-get install -y rockchip-mali-midgard14
sudo apt-get install -y rockchip-mali-midgard-dev

# Install GUI for ubuntu
sudo apt install -y ubuntu-mate-core && sudo apt install ubuntu-mate-desktop

# Check OpenCL & OpenGL info
glxinfo | grep version
clinfo
```

# 3. USB Camera
```
sudo apt install -y ffmpeg
ffplay /dev/video4
gst-launch-1.0 rkv4l2src device=/dev/video4 ! videoconvert ! kmssink
```