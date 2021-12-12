# 1. Board first run
- Debian OS: https://wiki.radxa.com/Rockpi4/getting_started
- Default user: rock/rock
- Wifi setting: https://wiki.radxa.com/Rockpi4/Debian#WIFI_Connection 

```
sudo su
apt update && apt upgrade
apt install -y wget
```

## 1.1  Radxa package
- Radxa APT: https://wiki.radxa.com/Rockpi4/radxa-apt

```
export DISTRO=buster-stable
echo "deb http://apt.radxa.com/$DISTRO/ ${DISTRO%-*} main" | sudo tee -a /etc/apt/sources.list.d/apt-radxa-com.list
wget -O - apt.radxa.com/$DISTRO/public.key | sudo apt-key add -
apt update && apt upgrade
apt install -y rockchip-overlay
apt install -y rockpi4b-rk-u-boot-latest
apt install -y linux-base linux-4.4-latest
reboot
```