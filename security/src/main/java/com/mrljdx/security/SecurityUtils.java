package com.mrljdx.security;

import android.util.Log;

/**
 * Created by Mrljdx on 16/4/16.
 * 加密工具类，调用JNI中的加密算法对数据进行加密
 *
 */
public class SecurityUtils {

    private static boolean useNative;

    static {
        boolean isSuccess;
        try {
            System.loadLibrary("security");
            isSuccess = true;
        } catch (Exception e) {
            isSuccess = false;
            e.printStackTrace();
        }
        useNative = isSuccess;
    }

    public static native String nativeMD5Str(String rawData);

    public static native String nativeSHAStr(String rawData);

    public static void helloFromJNI(){
        Log.d("JavaClz","Hello from Jni");
    }

}
