#!/bin/bash

echo "installing codeblocks and opengl on debian 13"

sudo apt update
sudo apt install mesa-utils

glxinfo | grep "OpenGL version"

sudo apt install build-essential libglu1-mesa-dev freeglut3-dev mesa-common-dev g++ cmake pkg-config

sudo apt install libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev

sudo apt install libglfw3-dev libglew-dev

apt install codeblocks

apt install codeblocks codeblocks-contrib
