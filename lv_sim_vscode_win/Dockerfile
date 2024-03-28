# To build:
#    docker build -t lvgl .
#
# To see how to do GUI forwarding in macOS:
#     https://cntnr.io/running-guis-with-docker-on-mac-os-x-a14df6a76efc
#
# To do GUI forwarding on linux, the following may work (easiest method, but unsafe)
#     xhost + && docker run --network=host --env DISPLAY=$DISPLAY lvgl

FROM ubuntu:18.04

RUN apt update && apt install -y \
    build-essential \
    cmake \
    gcc \
    git \
    libsdl2-dev \
    mesa-utils \
    libgl1-mesa-glx \
    x11-apps

ENV DISPLAY=:0

COPY . .

RUN make -j3

CMD ["./demo"]
