LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:= leak-demo
LOCAL_CPP_FLAGS:= -std=c++11
LOCAL_SRC_FILES:= leak_demo.cc
include $(BUILD_EXECUTABLE)

