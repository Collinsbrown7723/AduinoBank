import serial
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial('/dev/ttyUSB0', 115200)  # Replace 'COM3' with your Arduino port

plt.ion()
fig, ax = plt.subplots(subplot_kw={'projection': 'polar'})
line, = ax.plot([], [], 'ro')

while True:
    data = ser.readline().decode().strip()
    if data:
        angle, distance = map(int, data.split(','))
        print(angle,distance)
        angle_rad = np.deg2rad(angle)
        line.set_xdata(np.append(line.get_xdata(), angle_rad))
        line.set_ydata(np.append(line.get_ydata(), distance))
        ax.relim()
        ax.autoscale_view()
        plt.draw()
        plt.pause(0.01)
