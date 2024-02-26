# -*- coding: utf-8 -*-
"""
example on how to plot decoded sensor data from crazyflie
@author: jsschell
"""
import cfusdlog
import matplotlib.pyplot as plt
import re
import argparse
import cv2
import numpy as np

parser = argparse.ArgumentParser()
parser.add_argument("filename")
args = parser.parse_args()

# decode binary log data
logData = cfusdlog.decode(args.filename)

#only focus on regular logging
logData = logData['fixedFrequency']

# set window background to white
plt.rcParams['figure.facecolor'] = 'w'
    
# number of columns and rows for suplot
plotCols = 1
plotRows = 1

# let's see which keys exists in current data set
keys = ""
for k, v in logData.items():
    keys += k

# get plot config from user
plotGyro = 0
if re.search('gyro', keys):
    inStr = input("plot gyro data? ([Y]es / [n]o): ")
    if ((re.search('^[Yy]', inStr)) or (inStr == '')):
        plotGyro = 1
        plotRows += 1

plotAccel = 0
if re.search('acc', keys):
    inStr = input("plot accel data? ([Y]es / [n]o): ")
    if ((re.search('^[Yy]', inStr)) or (inStr == '')):
        plotAccel = 1
        plotRows += 1

plotBaro = 0
if re.search('baro', keys):
    inStr = input("plot barometer data? ([Y]es / [n]o): ")
    if ((re.search('^[Yy]', inStr)) or (inStr == '')):
        plotBaro = 1
        plotRows += 1

plotCtrl = 0
if re.search('ctrltarget', keys):
    inStr = input("plot control data? ([Y]es / [n]o): ")
    if ((re.search('^[Yy]', inStr)) or (inStr == '')):
        plotCtrl = 1
        plotRows += 1

plotStab = 0
if re.search('stabilizer', keys):
    inStr = input("plot stabilizer data? ([Y]es / [n]o): ")
    if ((re.search('^[Yy]', inStr)) or (inStr == '')):
        plotStab = 1
        plotRows += 1

plotToF = 0
if re.search('ToF', keys):
    inStr = input("plot ToF data? ([Y]es / [n]o): ")
    if ((re.search('^[Yy]', inStr)) or (inStr == '')):
        plotToF = 1
        plotRows += 1
    
# current plot for simple subplot usage
plotCurrent = 0
print(keys)
# new figure
plt.figure(0)

if plotGyro:
    plotCurrent += 1
    plt.subplot(plotRows, plotCols, plotCurrent)
    plt.plot(logData['timestamp'], logData['gyro.x'], '-', label='X')
    plt.plot(logData['timestamp'], logData['gyro.y'], '-', label='Y')
    plt.plot(logData['timestamp'], logData['gyro.z'], '-', label='Z')
    plt.xlabel('timestamp [ms]')
    plt.ylabel('Gyroscope [°/s]')
    plt.legend(loc=9, ncol=3, borderaxespad=0.)
 
if plotAccel:
    plotCurrent += 1
    plt.subplot(plotRows, plotCols, plotCurrent)
    plt.plot(logData['timestamp'], logData['acc.x'], '-', label='X')
    plt.plot(logData['timestamp'], logData['acc.y'], '-', label='Y')
    plt.plot(logData['timestamp'], logData['acc.z'], '-', label='Z')
    plt.xlabel('timestamp [ms]')
    plt.ylabel('Accelerometer [g]')
    plt.legend(loc=9, ncol=3, borderaxespad=0.)
 
if plotBaro:
    plotCurrent += 1
    plt.subplot(plotRows, plotCols, plotCurrent)
    plt.plot(logData['timestamp'], logData['baro.pressure'], '-')
    plt.xlabel('timestamp [ms]')
    plt.ylabel('Pressure [hPa]')
    
    plotCurrent += 1
    plt.subplot(plotRows, plotCols, plotCurrent)
    plt.plot(logData['timestamp'], logData['baro.temp'], '-')
    plt.xlabel('timestamp [ms]')
    plt.ylabel('Temperature [degC]')

if plotCtrl:
    plotCurrent += 1
    plt.subplot(plotRows, plotCols, plotCurrent)
    plt.plot(logData['timestamp'], logData['ctrltarget.roll'], '-', label='roll')
    plt.plot(logData['timestamp'], logData['ctrltarget.pitch'], '-', label='pitch')
    plt.plot(logData['timestamp'], logData['ctrltarget.yaw'], '-', label='yaw')
    plt.xlabel('timestamp [ms]')
    plt.ylabel('Control')
    plt.legend(loc=9, ncol=3, borderaxespad=0.)

if plotStab:
    plotCurrent += 1
    plt.subplot(plotRows, plotCols, plotCurrent)
    plt.plot(logData['timestamp'], logData['stabilizer.roll'], '-', label='roll')
    plt.plot(logData['timestamp'], logData['stabilizer.pitch'], '-', label='pitch')
    plt.plot(logData['timestamp'], logData['stabilizer.yaw'], '-', label='yaw')
    plt.plot(logData['timestamp'], logData['stabilizer.thrust'], '-', label='thrust')
    plt.xlabel('timestamp [ms]')
    plt.ylabel('Stabilizer')
    plt.legend(loc=9, ncol=4, borderaxespad=0.)

if plotToF:
    plotCurrent += 1
    plt.subplot(plotRows, plotCols, plotCurrent)
    plt.plot(logData['timestamp'], logData['ToF_f_Data.ToF_0'], '-', label='0')
    plt.plot(logData['timestamp'], logData['ToF_f_Data.ToF_15'], '-', label='15')
    plt.plot(logData['timestamp'], logData['ToF_f_Data.ToF_31'], '-', label='31')
    plt.plot(logData['timestamp'], logData['ToF_f_Data.ToF_47'], '-', label='47')
    plt.xlabel('timestamp [ms]')
    plt.ylabel('ToF')
    plt.legend(loc=9, ncol=4, borderaxespad=0.)

    i = 47*15
    img = np.array((logData['ToF_f_Data.ToF_0'][i],
        logData['ToF_f_Data.ToF_1'][i],
        logData['ToF_f_Data.ToF_2'][i],
        logData['ToF_f_Data.ToF_3'][i],
        logData['ToF_f_Data.ToF_4'][i],
        logData['ToF_f_Data.ToF_5'][i],
        logData['ToF_f_Data.ToF_6'][i],
        logData['ToF_f_Data.ToF_7'][i],
        logData['ToF_f_Data.ToF_8'][i],
        logData['ToF_f_Data.ToF_9'][i],
        logData['ToF_f_Data.ToF_10'][i],
        logData['ToF_f_Data.ToF_11'][i],
        logData['ToF_f_Data.ToF_12'][i],
        logData['ToF_f_Data.ToF_13'][i],
        logData['ToF_f_Data.ToF_14'][i],
        logData['ToF_f_Data.ToF_15'][i],
        logData['ToF_f_Data.ToF_16'][i],
        logData['ToF_f_Data.ToF_17'][i],
        logData['ToF_f_Data.ToF_18'][i],
        logData['ToF_f_Data.ToF_19'][i],
        logData['ToF_f_Data.ToF_20'][i],
        logData['ToF_f_Data.ToF_21'][i],
        logData['ToF_f_Data.ToF_22'][i],
        logData['ToF_f_Data.ToF_23'][i],
        logData['ToF_f_Data.ToF_24'][i],
        logData['ToF_f_Data.ToF_25'][i],
        logData['ToF_f_Data.ToF_26'][i],
        logData['ToF_f_Data.ToF_27'][i],
        logData['ToF_f_Data.ToF_28'][i],
        logData['ToF_f_Data.ToF_29'][i],
        logData['ToF_f_Data.ToF_30'][i],
        logData['ToF_f_Data.ToF_31'][i],
        logData['ToF_f_Data.ToF_32'][i],
        logData['ToF_f_Data.ToF_33'][i],
        logData['ToF_f_Data.ToF_34'][i],
        logData['ToF_f_Data.ToF_35'][i],
        logData['ToF_f_Data.ToF_36'][i],
        logData['ToF_f_Data.ToF_37'][i],
        logData['ToF_f_Data.ToF_38'][i],
        logData['ToF_f_Data.ToF_39'][i],
        logData['ToF_f_Data.ToF_40'][i],
        logData['ToF_f_Data.ToF_41'][i],
        logData['ToF_f_Data.ToF_42'][i],
        logData['ToF_f_Data.ToF_43'][i],
        logData['ToF_f_Data.ToF_44'][i],
        logData['ToF_f_Data.ToF_45'][i],
        logData['ToF_f_Data.ToF_46'][i],
        logData['ToF_f_Data.ToF_47'][i],
        logData['ToF_f_Data.ToF_48'][i],
        logData['ToF_f_Data.ToF_49'][i],
        logData['ToF_f_Data.ToF_50'][i],
        logData['ToF_f_Data.ToF_51'][i],
        logData['ToF_f_Data.ToF_52'][i],
        logData['ToF_f_Data.ToF_53'][i],
        logData['ToF_f_Data.ToF_54'][i],
        logData['ToF_f_Data.ToF_55'][i],
        logData['ToF_f_Data.ToF_56'][i],
        logData['ToF_f_Data.ToF_57'][i],
        logData['ToF_f_Data.ToF_58'][i],
        logData['ToF_f_Data.ToF_59'][i],
        logData['ToF_f_Data.ToF_60'][i],
        logData['ToF_f_Data.ToF_61'][i],
        logData['ToF_f_Data.ToF_62'][i],
        logData['ToF_f_Data.ToF_63'][i]))
    img = img
    img = img.reshape(8,8)
    # img = img.astype(np.uint8)
    print(img)
    print(logData['timestamp'])
    cv2.imshow("tof",img)



plt.show()
