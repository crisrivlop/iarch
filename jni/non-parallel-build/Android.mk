LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ia_test_non_parallel

LOCAL_SRC_FILES := main.cpp math/iavector.cpp math/matrix.cpp test/vector_test.cpp test/matrix_test.cpp
LOCAL_SRC_FILES += ia/NeuralNetwork.cpp ia/layer.cpp ia/sigmoid.cpp ia/activation.cpp ia/relu.cpp 
LOCAL_SRC_FILES += test/ia_test.cpp


ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    # LOCAL_ARM_NEON := true
    LOCAL_CFLAGS :=  -fopenmp -I./ 
    LOCAL_CFLAGS += -O3
    # LOCAL_CFLAGS += -DANDROID_ARM_NEON=ON -DHAVE_NEON=1
endif


LOCAL_STATIC_LIBRARIES := cpufeatures

LOCAL_LDLIBS := -llog -fopenmp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/
LOCAL_CPP_EXTENSION := .cxx .cpp .cc
LOCAL_CPPFLAGS := -fexceptions -frtti
LOCAL_CPPFLAGS += -std=c++11 -D__cplusplus=201103L -DANDROID_STL=c++_shared


include $(BUILD_EXECUTABLE)

$(call import-module,android/cpufeatures)
