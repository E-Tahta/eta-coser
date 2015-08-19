# eta-coser Setup Guide

### Building

Go to the directory of source code and run the fallowing in order to get application binary file:
```bash
qmake
sudo make
```
Now you should be able to see **etacoser** executable binary file.

### Install

To install the application to the system run the fallowing code in source code directory:

```bash
sudo cp -Rvf etacoser /usr/bin/.
```
and then go to etacoserscripts directory and change mode of setup.sh
and execute.

### Configuration

If you want to change some settings in application go to **/usr/share/eta-coser** directory and modify config.ini file.
