win32多线程练习  

出现问题:

Create_Thread函数中第四个参数类型必须为无类型 如下  
```
const char* a = "hello";

CreateThread(NULL, 0, &threadfunc1, ( void * )a,0, &threadId[0]);
```

我将字符串传入后在线程中转换回去
```
DWORD WINAPI threadfunc1(void* data) 

{   

  printf("%d", (char*)data); 
  
  return 0;    
  
}
```

此时输出为7109452显然不是我想要的字符串  

**2023/5/13 15：38**

发现问题所在 用了%d输出结果 

结论:可以将指针转化成无类型 再转换回去实现无类型指针传输
