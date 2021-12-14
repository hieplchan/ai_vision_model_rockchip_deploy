# 1. Compile
- RK3399 Linux graphic drivers not support Vulkan yet: https://github.com/Tencent/ncnn/issues/1175
- Protobuf
```
git clone --recursive https://github.com/protocolbuffers/protobuf.git
cd protobuf
./autogen.sh
./configure
make -j 6
sudo make install
sudo ldconfig
protoc --version
```

- MNN: https://www.yuque.com/mnn/en/build_linux
```
git clone --recursive https://github.com/alibaba/MNN.git
cd MNN
mkdir build && cd build
cmake -DMNN_OPENCL=ON -DMNN_BUILD_BENCHMARK=ON -DMNN_BUILD_TEST=ON -DMNN_BUILD_CONVERTER=ON -DMNN_BUILD_QUANTOOLS=ON ..
make -j 6
sudo make install
```

- Test benchmark: https://www.yuque.com/mnn/en/tool_benchmark
```
../build/benchmark.out models_folder [loop_count] [warmup] [forwardtype] [numberThread] [precision] [weightSparsity]
./build/benchmark.out ./benchmark/models/ 50 5 0 6
./build/benchmark.out ./benchmark/models/ 50 5 0 4
./build/benchmark.out ./benchmark/models/ 50 5 3 1
```
- Result
```
Forward type: **CPU** thread=6** precision=2** sparsity=0** sparseBlockOC=1
--------> Benchmarking... loop = 50, warmup = 5
[ - ] squeezenetv1.1.mnn          max =   61.632 ms  min =   38.819 ms  avg =   40.068 ms
[ - ] SqueezeNetV1.0.mnn          max =   99.005 ms  min =   71.141 ms  avg =   72.378 ms
[ - ] mobilenetV3.mnn             max =   12.732 ms  min =   12.331 ms  avg =   12.409 ms
[ - ] inception-v3.mnn            max =  455.803 ms  min =  420.186 ms  avg =  430.568 ms
[ - ] resnet-v2-50.mnn            max =  338.663 ms  min =  304.679 ms  avg =  311.082 ms
[ - ] nasnet.mnn                  max =  144.550 ms  min =   94.379 ms  avg =  109.955 ms
[ - ] mobilenet-v1-1.0.mnn        max =   81.690 ms  min =   56.833 ms  avg =   58.051 ms
[ - ] MobileNetV2_224.mnn         max =   61.134 ms  min =   35.890 ms  avg =   37.009 ms

Forward type: **CPU** thread=4** precision=2** sparsity=0** sparseBlockOC=1
--------> Benchmarking... loop = 50, warmup = 5
[ - ] squeezenetv1.1.mnn          max =   47.884 ms  min =   45.040 ms  avg =   45.322 ms
[ - ] SqueezeNetV1.0.mnn          max =   87.797 ms  min =   81.275 ms  avg =   82.201 ms
[ - ] mobilenetV3.mnn             max =   16.632 ms  min =   15.722 ms  avg =   16.080 ms
[ - ] inception-v3.mnn            max =  546.591 ms  min =  530.738 ms  avg =  535.541 ms
[ - ] resnet-v2-50.mnn            max =  410.716 ms  min =  346.209 ms  avg =  358.255 ms
[ - ] nasnet.mnn                  max =  127.889 ms  min =  115.448 ms  avg =  117.827 ms
[ - ] mobilenet-v1-1.0.mnn        max =   76.339 ms  min =   68.760 ms  avg =   69.875 ms
[ - ] MobileNetV2_224.mnn         max =   45.364 ms  min =   43.370 ms  avg =   44.090 ms

Forward type: **OpenCL** thread=1** precision=2** sparsity=0** sparseBlockOC=1
--------> Benchmarking... loop = 50, warmup = 5
[ - ] squeezenetv1.1.mnn          max =  181.762 ms  min =   50.353 ms  avg =   59.227 ms
[ - ] SqueezeNetV1.0.mnn          max =   84.305 ms  min =   78.937 ms  avg =   80.349 ms
[ - ] mobilenetV3.mnn             max =   96.308 ms  min =   28.981 ms  avg =   41.716 ms
[ - ] inception-v3.mnn            max =  688.139 ms  min =  674.696 ms  avg =  680.791 ms
[ - ] resnet-v2-50.mnn            max =  262.893 ms  min =  255.639 ms  avg =  261.116 ms
[ - ] nasnet.mnn                  max =  116.374 ms  min =  107.466 ms  avg =  109.097 ms
[ - ] mobilenet-v1-1.0.mnn        max =   59.256 ms  min =   55.169 ms  avg =   56.439 ms
[ - ] MobileNetV2_224.mnn         max =   48.697 ms  min =   43.669 ms  avg =   46.657 ms
```