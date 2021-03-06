#!/usr/bin/python
# -*- coding:utf8 -*-

import matplotlib.pyplot as plt

def main():
    print '联通手机营业厅大作战'
    y = [0,0,2,0,0,2,3,0,0,0,0,2,3,0,0,3,3,0,0,3,2,3,2,0,0,2,3,2,0,2,2,0,3,0,0,2,2,0,0,3,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,
         0,0,2,0,0,3,3,0,0,3,0,3,2,0,3,2,2,0,2,3,3,2,2,0,3,2,0,2,3,3,2,2,3,2,2,0,0,0,0,3,3,2,0,2,2,2,0,0,0,0,0,0,0,0,0,
         0,0,0,2,0,2,0,3,0,0,0,2,2,3,0,2,2,2,0,0,2,0,2,0,0,3,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0,3,2,0,0,0,3,0,0,0,0,0,2,0,
         0,2,2,0,3,0,0,0,0,0,0,0,0,3,0,3,0,2,2,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,3,0,0,3,0,2,0,]
    x = range(len(y))
    plt.figure(figsize=(60,6))  # 创建绘图对象
    plt.plot(x, y, "b", linewidth=2)  # 在当前绘图对象绘图（X轴，Y轴，蓝色虚线，线宽度）
    plt.xlabel("Time(s)")  # X轴标签
    plt.ylabel("Volt")  # Y轴标签
    plt.title("Line plot")  # 图标题
    plt.ylim(-5, 5)
    plt.xlim(0, 200)

    plt.show()  # 显示图
    plt.savefig("line.jpg")  # 保存图


if __name__ == '__main__':
    main()