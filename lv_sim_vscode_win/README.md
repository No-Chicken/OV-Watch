# Simulator project for LVGL embedded GUI Library

The [LVGL](https://github.com/lvgl/lvgl) is written mainly for microcontrollers and embedded systems however you can run the library **on your PC** as well without any embedded hardware. The code written on PC can be simply copied when your are using an embedded system.

Using a PC simulator instead of an embedded hardware has several advantages:
* **Costs $0** because you you don't have to buy or design PCB
* **Fast** because you don't have to design an manufacture PCB
* **Collaborative** because any number of developers can work in the same environment
* **Developer friendly** because much easier and faster to debug on PC

## Requirements
The PC simulator is cross platform.  **Windows, Linux and OSX** are supported, however on Windows it's easier to get started with a [another simulator](https://docs.lvgl.io/latest/en/html/get-started/pc-simulator.html) project. 

* **SDL** a low level driver library to use graphics, handle mouse, keyboard etc.
* This project (configured for **Eclipse CDT IDE**)

## Usage

### Get the PC project

Clone the PC project and the related sub modules:

```
git clone --recursive https://github.com/littlevgl/pc_simulator_sdl_eclipse.git
```

### Install SDL
You can download SDL from https://www.libsdl.org/

On on Linux you can install it via terminal:
```
sudo apt-get update && sudo apt-get install -y build-essential libsdl2-dev
```

### Install Eclipse CDT
Download and install Eclipse CDT from  http://www.eclipse.org/cdt/

### Import the PC simulator project
1. Open Eclipse CDT
2. Click **File->Import** and choose **General->Existing project into Workspace**
3. Browse the root directory of the project and click Finish
4. Build your project and run it

## CMake

The following steps can be used with CMake on a Unix-like system. This may also work on other OSes but has not been tested.

1. Ensure CMake is installed, i.e. the `cmake` command works on the terminal.
2. Make a new directory. The name doesn't matter but `build` will be used for this tutorial.
3. Type `cd build`.
4. Type `cmake ..`. CMake will generate the appropriate build files.
5. Type `make -j4` or (more portable) `cmake --build . --parallel`.

**NOTE:** `--parallel` is supported from CMake v3.12 onwards. If you are using an older version of CMake, remove `--parallel` from the command or use the make option.

6. The binary will be in `../bin/main`, and can be run by typing that command.

## Docker
1. Build the docker container
```
docker build -t lvgl_simulator .
```
2. Run the docker container
```
docker run lvgl_simulator
```
GUI with docker is platform dependent. For example, on macOS you can follow 
[this tutorial](https://cntnr.io/running-guis-with-docker-on-mac-os-x-a14df6a76efc) 
and run a command similar to:
```
docker run -e DISPLAY=10.103.56.101:0 lvgl_simulator
```

Note that on macOS, you may need to enable indirect GLX rendering before starting Xquartz:
```
defaults write org.macosforge.xquartz.X11 enable_iglx -bool true
open -a Xquartz
```

For Linux environments with X Server, the following will the `docker run` command. Note that the first command, `xhost +` grants access to X server to everyone.

```
xhost +
docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix:ro -t lvgl_simulator
```

## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request!

If you find an issue, please report it via GitHub!
