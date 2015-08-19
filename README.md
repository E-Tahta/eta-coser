# eta-coser Setup Guide

### Building

Go to the directory of source code and run the fallowing in order to get application binary file:
```bash
cd etacoser
qmake
sudo make
```
Now you should be able to see **etacoser** executable binary file.

### Install

To install the application to the system run the fallowing code in source code directory:

```bash
chmod +x etacoser
sudo cp -Rvf etacoser /usr/bin/.
```
and then go to etacoserscripts directory and run the fallowing code:

```bash
cd ../etacoserscripts
chmod +x setup.sh
./setup.sh
```

### Configuration

If you want to change some settings in application go to **/usr/share/eta-coser** directory and modify config.ini file.
