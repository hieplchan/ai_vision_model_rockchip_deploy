# 1. Setup
https://www.tensorflow.org/lite/performance/measurement
https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/tools/benchmark#on-android

# 2. Result
```
rock@rockpi4b:~/3rdparty/tensorflow/build/tools/benchmark$ ./benchmark_model   --num_threads=4   --graph=mobilenet_quant_v1_224.tflite   --warmup_runs=5   --num_runs=50   --use_gpu=true
Inference timings in us: Init: 495671, First inference: 157848, Warmup (avg): 161194, Inference (avg): 48976.5
Memory footprint delta from the start of the tool (MB): init=73.3438 overall=73.3438
```
```
rock@rockpi4b:~/3rdparty/tensorflow/build/tools/benchmark$ ./benchmark_model   --num_threads=4   --graph=mobilenet_quant_v1_224.tflite   --warmup_runs=5   --num_runs=50
Inference timings in us: Init: 5183, First inference: 85262, Warmup (avg): 69344.4, Inference (avg): 110385
Memory footprint delta from the start of the tool (MB): init=4.58984 overall=7.82031
```
```
rock@rockpi4b:~/3rdparty/tensorflow/build/tools/benchmark$ ./benchmark_model   --num_threads=4   --graph=mobilenet_v1_1.0_224.tflite   --warmup_runs=5   --num_runs=50   --use_gpu=true
Inference timings in us: Init: 453475, First inference: 155221, Warmup (avg): 62753.9, Inference (avg): 42638.8
Memory footprint delta from the start of the tool (MB): init=84.8555 overall=84.8555
```
```
rock@rockpi4b:~/3rdparty/tensorflow/build/tools/benchmark$ ./benchmark_model   --num_threads=4   --graph=mobilenet_v1_1.0_224.tflite   --warmup_runs=5   --num_runs=50
Inference timings in us: Init: 77363, First inference: 93280, Warmup (avg): 65912.6, Inference (avg): 60056.3
Memory footprint delta from the start of the tool (MB): init=36.7422 overall=43.5039
```
```
rock@rockpi4b:~/3rdparty/tensorflow/build/tools/benchmark$ ./benchmark_model   --num_threads=4   --graph=inception_resnet_v2.tflite   --warmup_runs=5   --num_runs=50   --use_gpu=true
Inference timings in us: Init: 1766054, First inference: 897739, Warmup (avg): 691754, Inference (avg): 643692
Memory footprint delta from the start of the tool (MB): init=411.906 overall=411.906
```
```
rock@rockpi4b:~/3rdparty/tensorflow/build/tools/benchmark$ ./benchmark_model   --num_threads=4   --graph=inception_resnet_v2.tflite   --warmup_runs=5   --num_runs=50
Inference timings in us: Init: 359558, First inference: 1058110, Warmup (avg): 1.02913e+06, Inference (avg): 1.10134e+06
Memory footprint delta from the start of the tool (MB): init=236.438 overall=261.926
```