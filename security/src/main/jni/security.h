//
// Created by Mrljdx on 16/4/16.
//

#ifndef SECURITY_H
#define SECURITY_H

#include "com_mrljdx_security_SecurityUtils.h"
#include "MD5.h"
#include "SHA1.h"
#include <algorithm>

using namespace std;

/**
 * jstring 转 string
 */
static string jstring2string(JNIEnv *env, jstring str) {
    const char *c_str1 = NULL;
    c_str1 = env->GetStringUTFChars(str, NULL); //获取Java中的string类型变量的值
    string result(c_str1); //将jstring的值转换为string，对应于C/C++中相应的变量类型
    env->ReleaseStringUTFChars(str, c_str1); //释放字符串指针
    return result;
}

/**
 * char 转 jstring
 */
static jstring char2jstring(JNIEnv *env, const char *str) {
    jsize len = strlen(str); //转换java string对应的长度大小
    jclass clsstring = env->FindClass("java/lang/String"); //获取String类
    jstring strencode = env->NewStringUTF("utf-8"); //utf-8编码
    //获取String类中的初始化方法ID
    jmethodID mid = env->GetMethodID(clsstring, "<init>", "([BLjava/lang/String;)V");
    jbyteArray barr = env->NewByteArray(len);
    env->SetByteArrayRegion(barr, 0, len, (jbyte *) str);
    return (jstring) env->NewObject(clsstring, mid, barr, strencode);
}

/**
 * 字符串大写转换
 */
char touppercase(char in) {
    if (in <= 'z' && in >= 'a')
        return in + ('Z' - 'z');
    return in;
}

static void static_helloJni(JNIEnv *env) {
    jclass clazz = env->FindClass("com/mrljdx/security/SecurityUtils");
    jmethodID mid = env->GetStaticMethodID(clazz, "helloFromJNI", "()V");
    env->CallStaticVoidMethod(clazz, mid);
}

#endif //SECURITY_H
