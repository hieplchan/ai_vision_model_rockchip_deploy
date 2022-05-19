# 1. Setup
- Test benchmark: https://www.yuque.com/mnn/en/tool_benchmark

# 2. Result
../build/benchmark.out models_folder [loop_count] [warmup] [forwardtype] [numberThread] [precision] [weightSparsity]
forwardtype is in these options: 0->CPU，1->Metal，3->OpenCL，6->OpenGL，7->Vulkan

```
rock@rockpi4b:~/3rdparty/MNN/build$ ./benchmark.out ../benchmark/models/ 20 5 0 4
MNN benchmark
Forward type: **CPU** thread=4** precision=2** sparsity=0** sparseBlockOC=1
--------> Benchmarking... loop = 20, warmup = 5
[ - ] resnet-v2-50.mnn            max =  339.943 ms  min =  336.965 ms  avg =  338.189 ms
[ - ] mobilenet-v1-1.0.mnn        max =   77.896 ms  min =   68.989 ms  avg =   69.652 ms
[ - ] mobilenetV3.mnn             max =   15.802 ms  min =   15.124 ms  avg =   15.222 ms
[ - ] MobileNetV2_224.mnn         max =   43.832 ms  min =   43.486 ms  avg =   43.598 ms
[ - ] inception-v3.mnn            max =  532.256 ms  min =  523.279 ms  avg =  525.446 ms
[ - ] nasnet.mnn                  max =  125.342 ms  min =  124.723 ms  avg =  124.920 ms
[ - ] SqueezeNetV1.0.mnn          max =   81.939 ms  min =   79.771 ms  avg =   80.079 ms
[ - ] squeezenetv1.1.mnn          max =   44.131 ms  min =   42.901 ms  avg =   43.420 ms
```
```
rock@rockpi4b:~/3rdparty/MNN/build$ ./benchmark.out ../benchmark/models/ 20 5 0 2
MNN benchmark
Forward type: **CPU** thread=2** precision=2** sparsity=0** sparseBlockOC=1
--------> Benchmarking... loop = 20, warmup = 5
[ - ] resnet-v2-50.mnn            max =  342.236 ms  min =  338.808 ms  avg =  339.968 ms
[ - ] mobilenet-v1-1.0.mnn        max =   68.837 ms  min =   65.376 ms  avg =   67.170 ms
[ - ] mobilenetV3.mnn             max =   13.817 ms  min =   12.299 ms  avg =   12.780 ms
[ - ] MobileNetV2_224.mnn         max =   44.868 ms  min =   41.486 ms  avg =   42.782 ms
[ - ] inception-v3.mnn            max =  556.495 ms  min =  537.114 ms  avg =  547.174 ms
[ - ] nasnet.mnn                  max =  110.646 ms  min =  107.604 ms  avg =  109.391 ms
[ - ] SqueezeNetV1.0.mnn          max =   88.048 ms  min =   85.995 ms  avg =   87.054 ms
[ - ] squeezenetv1.1.mnn          max =   46.076 ms  min =   45.261 ms  avg =   45.444 ms
```
```
rock@rockpi4b:~/3rdparty/MNN/build$ ./benchmark.out ../benchmark/models/ 20 5 3 2
MNN benchmark
Forward type: **OpenCL** thread=2** precision=2** sparsity=0** sparseBlockOC=1
--------> Benchmarking... loop = 20, warmup = 5
[ - ] resnet-v2-50.mnn            max =  216.442 ms  min =  210.104 ms  avg =  211.818 ms
[ - ] mobilenet-v1-1.0.mnn        max =   53.963 ms  min =   50.238 ms  avg =   51.453 ms
[ - ] mobilenetV3.mnn             max =   27.391 ms  min =   25.015 ms  avg =   25.870 ms
[ - ] MobileNetV2_224.mnn         max =   42.332 ms  min =   36.528 ms  avg =   38.642 ms
```