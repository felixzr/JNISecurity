## Security Library 说明

Security Library 库是基于C/C++的底层加密算法，避免在Java代码中进行加密算法容易被反编译破解的问题。

其中MD5和SHA1算法是基于通用的算法实现，算法实现取自网络。Mrljdx仅对算法调用和JNI层的实现，代码位于security.cpp中。

## 后续扩展

1. Base64加密算法
2. Native基础工具库丰富
3. Native加入调试Log日志


