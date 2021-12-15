# 1. Face detect
- Pretrained: https://github.com/Linzaer/Ultra-Light-Fast-Generic-Face-Detector-1MB

- Test bbox is correct or not
```
cd ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/build

./Ultra-face-mnn ../model/version-RFB/RFB-320.mnn /home/rock/data/hiep.jpg
./Ultra-face-mnn ../model/version-RFB/RFB-320.mnn /home/rock/data/hiep_mask.jpg 

./Ultra-face-mnn ../model/version-RFB/RFB-320-quant-KL-5792.mnn /home/rock/data/hiep.jpg
./Ultra-face-mnn ../model/version-RFB/RFB-320-quant-KL-5792.mnn /home/rock/data/hiep_mask.jpg

./Ultra-face-mnn ../model/version-RFB/RFB-320-quant-ADMM-32.mnn /home/rock/data/hiep.jpg
./Ultra-face-mnn ../model/version-RFB/RFB-320-quant-ADMM-32.mnn /home/rock/data/hiep_mask.jpg

./Ultra-face-mnn ../model/version-slim/slim-320.mnn /home/rock/data/hiep.jpg
./Ultra-face-mnn ../model/version-slim/slim-320.mnn /home/rock/data/hiep_mask.jpg

./Ultra-face-mnn ../model/version-slim/slim-320-quant-ADMM-50.mnn /home/rock/data/hiep.jpg
./Ultra-face-mnn ../model/version-slim/slim-320-quant-ADMM-50.mnn /home/rock/data/hiep_mask.jpg
```

- Test model performance CPU
```
./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-RFB/RFB-320.mnn 500 0 0 4 1x3x320x240
Avg= 18.360878 ms, min= 17.710001 ms, max= 55.742004 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-RFB/RFB-320-quant-KL-5792.mnn 500 0 0 4 1x3x320x240
Avg= 16.813805 ms, min= 14.868001 ms, max= 50.635002 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-RFB/RFB-320-quant-ADMM-32.mnn 500 0 0 4 1x3x320x240
Avg= 16.887383 ms, min= 16.382000 ms, max= 58.674004 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-slim/slim-320.mnn 500 0 0 4 1x3x320x240
Avg= 15.697287 ms, min= 14.466001 ms, max= 37.217003 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-slim/slim-320-quant-ADMM-50.mnn 500 0 0 4 1x3x320x240
Avg= 14.157244 ms, min= 12.280001 ms, max= 28.441002 ms
```

- Test model performance GPU
```
./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-RFB/RFB-320.mnn 500 0 3 1 1x3x320x240
Avg= 41.099632 ms, min= 22.623001 ms, max= 82.611008 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-RFB/RFB-320-quant-KL-5792.mnn 500 0 3 1 1x3x320x240
Avg= 86.239632 ms, min= 49.941002 ms, max= 144.320007 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-RFB/RFB-320-quant-ADMM-32.mnn 500 0 3 1 1x3x320x240
Avg= 86.296928 ms, min= 40.287003 ms, max= 129.964005 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-slim/slim-320.mnn 500 0 3 1 1x3x320x240
Avg= 44.309338 ms, min= 23.903002 ms, max= 69.896004 ms

./MNNV2Basic.out ~/work/Ultra-Light-Fast-Generic-Face-Detector-1MB/MNN/model/version-slim/slim-320-quant-ADMM-50.mnn 500 0 3 1 1x3x320x240
Avg= 47.054485 ms, min= 29.338001 ms, max= 99.879005 ms
```

# 2. Arcface
- Insight face MBF@WebFace600K: https://github.com/deepinsight/insightface/tree/master/model_zoo
- Model convert
``` 
./MNNConvert -f ONNX --modelFile /home/rock/model/w600k_mbf.onnx --MNNModel /home/rock/model/w600k_mbf.mnn --bizCode biz
```
- Test model performance CPU
```
./MNNV2Basic.out /home/rock/model/w600k_mbf.mnn 500 0 0 4 1x3x112x112
Avg= 65.154274 ms, min= 64.681000 ms, max= 71.795006 ms
```
- Test model performance GPU
```
./MNNV2Basic.out /home/rock/model/w600k_mbf.mnn 500 0 3 1 1x3x112x112
Avg= 85.770653 ms, min= 82.876007 ms, max= 103.386002 ms
```
