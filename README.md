# VehicleMonitor
Monitoring system using Raspberry Pi

Grand Plan: 
  Video Capture:
    1. Fix Framerate issues
    2. Investigate NMAL/OpenMAX for access to GPU 
      see https://github.com/gagle/raspberrypi-omxcam  or http://elinux.org/Raspberry_Pi_VideoCore_APIs  for more details
    3. Video preview is very slow.. conversion from Mat to QImage for display is very slow too.
    4. Some image processing maybe cool to play with here. possibly after 2. is done.
    
  Telemetry system:
    1. Gyro scope interface
    2. Accelerometer
    3. GPS (uart adafruit breakout)
    4. OBD 2 bluetooth interface:
      i. get fuel consumption information
      ii. Graph and log all of this.
