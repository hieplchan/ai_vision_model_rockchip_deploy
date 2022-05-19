# 1. Setup
https://github.com/Tencent/ncnn/blob/master/benchmark/README.md

# 2. Result
./benchncnn [loop count] [num threads] [powersave] [gpu device] [cooling down]

```
rock@rockpi4b:~/3rdparty/ncnn/benchmark$ ../build/benchmark/benchncnn 100 2 2 -1 1
loop_count = 100
num_threads = 2
powersave = 2
gpu_device = -1
cooling_down = 1

          squeezenet  min =   51.53  max =   53.63  avg =   52.40
     squeezenet_int8  min =   45.13  max =   47.10  avg =   45.63
           mobilenet  min =   72.45  max =   74.34  avg =   73.30
      mobilenet_int8  min =   47.69  max =   49.06  avg =   47.98
        mobilenet_v2  min =   60.05  max =   62.28  avg =   60.69
        mobilenet_v3  min =   47.80  max =   49.41  avg =   48.10
          shufflenet  min =   30.55  max =   31.46  avg =   30.87
       shufflenet_v2  min =   28.46  max =   29.36  avg =   28.68
             mnasnet  min =   52.90  max =   54.85  avg =   53.25
     proxylessnasnet  min =   59.33  max =   94.58  avg =   60.23
     efficientnet_b0  min =   96.62  max =   97.92  avg =   97.06
   efficientnetv2_b0  min =  107.43  max =  110.15  avg =  108.15
        regnety_400m  min =   68.94  max =   70.88  avg =   69.54
           blazeface  min =   10.78  max =   13.19  avg =   11.11
           googlenet  min =  145.04  max =  149.35  avg =  145.92
      googlenet_int8  min =  128.15  max =  130.81  avg =  128.76
            resnet18  min =  136.17  max =  139.10  avg =  137.30
       resnet18_int8  min =   95.26  max =   97.50  avg =   95.90
             alexnet  min =  121.25  max =  123.92  avg =  121.76
               vgg16  min =  749.58  max =  838.30  avg =  802.49
          vgg16_int8  min =  518.45  max =  539.98  avg =  535.37
            resnet50  min =  337.38  max =  354.43  avg =  350.12
       resnet50_int8  min =  264.03  max =  274.13  avg =  271.24
      squeezenet_ssd  min =  135.08  max =  142.82  avg =  139.17
 squeezenet_ssd_int8  min =  112.18  max =  123.00  avg =  115.53
       mobilenet_ssd  min =  144.80  max =  161.31  avg =  154.24
  mobilenet_ssd_int8  min =   96.20  max =  105.46  avg =  102.88
      mobilenet_yolo  min =  322.86  max =  362.62  avg =  349.55
  mobilenetv2_yolov3  min =  197.29  max =  211.12  avg =  206.25
         yolov4-tiny  min =  254.29  max =  271.48  avg =  266.16
           nanodet_m  min =   74.32  max =   79.41  avg =   77.22
    yolo-fastest-1.1  min =   40.08  max =   42.14  avg =   40.52
      yolo-fastestv2  min =   34.64  max =   37.03  avg =   35.07
  vision_transformer  min = 8037.16  max = 8926.04  avg = 8537.66
```

```
rock@rockpi4b:~/3rdparty/ncnn/benchmark$ ../build/benchmark/benchncnn 100 4 1 -1 1
loop_count = 100
num_threads = 4
powersave = 1
gpu_device = -1
cooling_down = 1
          squeezenet  min =   59.44  max =   77.27  avg =   60.50
     squeezenet_int8  min =   50.98  max =   60.46  avg =   51.52
           mobilenet  min =   74.91  max =   77.83  avg =   75.52
      mobilenet_int8  min =   52.93  max =   57.16  avg =   53.31
        mobilenet_v2  min =   66.43  max =   71.37  avg =   67.01
        mobilenet_v3  min =   57.82  max =   59.05  avg =   58.30
          shufflenet  min =   40.38  max =   41.64  avg =   40.68
       shufflenet_v2  min =   41.53  max =   51.17  avg =   42.28
             mnasnet  min =   60.55  max =   62.70  avg =   60.90
     proxylessnasnet  min =   72.70  max =   76.77  avg =   73.29
     efficientnet_b0  min =  109.12  max =  112.11  avg =  109.89
   efficientnetv2_b0  min =  123.27  max =  126.47  avg =  124.43
        regnety_400m  min =   89.10  max =   91.93  avg =   89.58
           blazeface  min =   13.59  max =   20.25  avg =   13.98
           googlenet  min =  167.14  max =  180.08  avg =  167.87
      googlenet_int8  min =  141.43  max =  183.68  avg =  142.71
            resnet18  min =  157.59  max =  159.70  avg =  158.11
       resnet18_int8  min =  106.37  max =  108.82  avg =  107.15
             alexnet  min =  168.99  max =  174.21  avg =  170.18
               vgg16  min =  851.57  max =  877.18  avg =  867.28
          vgg16_int8  min =  497.58  max =  507.81  avg =  499.75
            resnet50  min =  347.95  max =  356.99  avg =  349.51
       resnet50_int8  min =  276.44  max =  286.28  avg =  277.86
      squeezenet_ssd  min =  162.28  max =  165.70  avg =  163.54
 squeezenet_ssd_int8  min =  130.59  max =  133.64  avg =  131.47
       mobilenet_ssd  min =  154.50  max =  157.43  avg =  155.24
  mobilenet_ssd_int8  min =  106.14  max =  108.62  avg =  106.62
      mobilenet_yolo  min =  333.88  max =  341.84  avg =  336.15
  mobilenetv2_yolov3  min =  216.93  max =  226.20  avg =  218.17
         yolov4-tiny  min =  295.78  max =  299.07  avg =  296.87
           nanodet_m  min =  107.58  max =  109.99  avg =  108.48
    yolo-fastest-1.1  min =   50.23  max =   54.85  avg =   50.83
      yolo-fastestv2  min =   40.99  max =   45.18  avg =   41.47
```