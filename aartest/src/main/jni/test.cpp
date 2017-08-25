//
// Created by elevoc on 2017/8/24.
//

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