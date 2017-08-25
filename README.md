# GetAAR

### 获取.aar步骤

1.新建一个工程，new project,命名为GetAAR

2.在这个工程里新建一个module，new module，命名为aartest,在AndroidManifest.xml第一行可以看出build之后会生成什么

3.在module中，src/main/文件夹下新建一个文件夹jni

4.在jni文件夹中新建Android.mk,Application.mk,test.cpp,test.h

5.Android.mk

```
LOCAL_PATH := $(call my-dir)

//模块
include $(CLEAR_VARS)
LOCAL_MODULE := test
LOCAL_SRC_FILES := test.cpp

include $(BUILD_SHARED_LIBRARY)
```

6.Application.mk

```
APP_PLATFORM := android-14
APP_ABI := all
```

7.
在aartest模型的 java/com/example/aartest/ 下新建一个.java文件，HelloWorld.java，并写一个native函数

public native String TestGetString()

8.在aartest项目的java文件夹下执行javah，javah 包名.类名,这里是javah com.example.aartest.HelloWorld

9.在java文件夹下会生成一个.h文件

10.将这个文件拷到aartest模型下的jni文件夹，在test.cpp中 include “xxx.h”

11.在test.cpp中实现上述的函数TestGetString()

```
#include "test.h"
#include "com_example_aartest_HelloWorld.h"

extern "C"

/*
 * Class:     com_example_aartest_HelloWorld
 * Method:    testGetString
 * Signature: ()Ljava/lang/String;
 */
jstring Java_com_example_aartest_HelloWorld_testGetString(JNIEnv *env, jobject){
    jstring ans=env->NewStringUTF("hello world!->testGetString()");
    return ans;
}
```

12.到aartest/,执行gradle build

13.aartest/build/outputs/aar/中有debug和release版本的aar
