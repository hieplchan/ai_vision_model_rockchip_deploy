# 1. Setup
https://wiki.radxa.com/Rockpi4/dev/install-opencl#Sanity_Checkout_with_clpeak

# 2. Result
rock@rockpi4b:~/utils/clpeak$ ./clpeak

Platform: ARM Platform
  Device: Mali-T860
    Driver version  : 1.2 (Linux ARM64)
    Compute units   : 4
    Clock frequency : 200 MHz

    Global memory bandwidth (GBPS)
      float   : 5.28
      float2  : 7.17
      float4  : 8.71
      float8  : 7.27
      float16 : 6.53

    Single-precision compute (GFLOPS)
      float   : 25.38
      float2  : 50.38
      float4  : 50.33
      float8  : 49.83
      float16 : 32.00

    Half-precision compute (GFLOPS)
      half   : 50.88
      half2  : 100.83
      half4  : 99.21
      half8  : 98.53
      half16 : 95.10

    Double-precision compute (GFLOPS)
      double   : 12.62
      double2  : 24.63
      double4  : 24.49
      double8  : 16.13
      double16 : 7.01

    Integer compute (GIOPS)
      int   : 25.33
      int2  : 50.18
      int4  : 50.09
      int8  : 49.29
      int16 : 31.27

    Integer compute Fast 24bit (GIOPS)
      int   : 25.38
      int2  : 50.40
      int4  : 50.07
      int8  : 49.29
      int16 : 31.27

    Transfer bandwidth (GBPS)
      enqueueWriteBuffer              : 1.33
      enqueueReadBuffer               : 1.33
      enqueueWriteBuffer non-blocking : 1.30
      enqueueReadBuffer non-blocking  : 1.33
      enqueueMapBuffer(for read)      : 5.08
        memcpy from mapped ptr        : 2.08
      enqueueUnmap(after write)       : 4.71
        memcpy to mapped ptr          : 1.91

    Kernel launch latency : 260.81 us
