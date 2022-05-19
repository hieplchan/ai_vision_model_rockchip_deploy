# 1. OpenCV
```
sudo apt install libopencv-dev
```

# 2. MNN
```
sudo apt install protobuf-compiler ocl-icd-opencl-dev libglew-dev
git clone --recursive https://github.com/alibaba/MNN.git
cd MNN
mkdir build && cd build
cmake -DMNN_BUILD_BENCHMARK=ON -DCMAKE_BUILD_TYPE=Release -DMNN_BUILD_CONVERTER=ON -DMNN_BUILD_QUANTOOLS=ON -DMNN_OPENCL=ON -DMNN_BUILD_SHARED_LIBS=OFF -DMNN_PORTABLE_BUILD=ON -DMNN_SEP_BUILD=OFF ..
make -j$(nproc)
sudo make install
```

# 3. NCNN
- RK3399 Linux graphic drivers not support Vulkan yet: https://github.com/Tencent/ncnn/issues/1175
```
git clone https://github.com/Tencent/ncnn.git
cd ncnn
sudo apt install build-essential git cmake libprotobuf-dev protobuf-compiler
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
sudo make install
```

# 4. TF Lite
```
git clone https://github.com/tensorflow/tensorflow.git
cd tensorflow
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=OFF -DTFLITE_ENABLE_GPU=ON ../tensorflow/lite
make -j$(nproc)
sudo make install
cmake --build . -j -t benchmark_model
```