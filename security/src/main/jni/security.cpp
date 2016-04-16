//
// Created by Mrljdx on 16/4/16.
//

#include "security.h"

/**
 * Native MD5 security method
 */
JNIEXPORT jstring JNICALL Java_com_mrljdx_security_SecurityUtils_nativeMD5Str
        (JNIEnv *env, jclass clazz, jstring str) {
    static_helloJni(env);
    const char *data = env->GetStringUTFChars(str, NULL);
    string result = md5(data);
    transform(result.begin(), result.end(), result.begin(), touppercase);
    env->ReleaseStringUTFChars(str,data);
    return char2jstring(env, result.c_str());
}

/**
 * Native SHA! security method
 */
JNIEXPORT jstring JNICALL Java_com_mrljdx_security_SecurityUtils_nativeSHAStr
        (JNIEnv *env, jclass clazz, jstring str) {
    static_helloJni(env);
    const char *data = env->GetStringUTFChars(str, NULL);
    string result;
    CSHA1 sha1;
    sha1.Update((UINT_8 *) (data), strlen(data));
    sha1.Final();
    sha1.ReportHashStl(result, CSHA1::REPORT_HEX_SHORT);

    env->ReleaseStringUTFChars(str,data);
    return char2jstring(env, result.c_str());


}
