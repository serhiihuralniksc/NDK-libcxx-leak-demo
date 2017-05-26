#!/bin/bash

ndk-build NDK_APPLICATION_MK=./Application.mk NDK_PROJECT_PATH=./
adb push ./libs/armeabi-v7a/leak-demo /data/local/tmp/
adb shell chmod +x /data/local/tmp/leak-demo
adb shell /data/local/tmp/leak-demo
adb shell rm /data/local/tmp/leak-demo

