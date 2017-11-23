#!/usr/bin/python
# -*- coding:utf8 -*-

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

tsTemperatureForm = np.dtype({
	'names':['iTemperature','iResister'],
	'formats':['i','i']
})

data_m = np.array([(-40, 308163),(-39, 288660),(-38, 270634),(-37, 253947),(-36, 238474),
(-35, 224106),(-34, 210745),(-33, 198306),(-32, 186710),(-31, 175888),
(-30, 165777),(-29, 156322),(-28, 147471),(-27, 139180),(-26, 131406),
(-25, 124112),(-24, 117264),(-23, 110829),(-22, 104781),(-21, 99092),
(-20, 93738),(-19, 88698),(-18, 83950),(-17, 79477),(-16, 75260),
(-15, 71284),(-14, 67534),(-13, 63996),(-12, 60656),(-11, 57504),
(-10, 54528),(-9, 51717),(-8, 49061),(-7, 46553),(-6, 44182),
(-5, 41942),(-4, 39824),(-3, 37822),(-2, 35929),(-1, 34139),
(0, 32446),(1, 30844),(2, 29329),(3, 27895),(4, 26538),
(5, 25254),(6, 24039),(7, 22889),(8, 21799),(9, 20768),
(10, 19791),(11, 18866),(12, 17990),(13, 17160),(14, 16373),
(15, 15628),(16, 14921),(17, 14252),(18, 13617),(19, 13015),
(20, 12444),(21, 11902),(22, 11389),(23, 10901),(24, 10439),
(25, 10000),(26, 9595),(27, 9205),(28, 8831),(29, 8472),
(30, 8127),(31, 7797),(32, 7480),(33, 7177),(34, 6886),
(35, 6608),(36, 6341),(37, 6086),(38, 5842),(39, 5608),
(40, 5385),(41, 5171),(42, 4966),(43, 4771),(44, 4584),
(45, 4405),(46, 4233),(47, 4070),(48, 3913),(49, 3763),
(50, 3620),(51, 3483),(52, 3352),(53, 3226),(54, 3106),
(55, 2991),(56, 2881),(57, 2775),(58, 2674),(59, 2578),
(60, 2485),(61, 2396),(62, 2311),(63, 2230),(64, 2152),
(65, 2077),(66, 2005),(67, 1936),(68, 1870),(69, 1807),
(70, 1746),(71, 1687),(72, 1631),(73, 1577),(74, 1525),
(75, 1475),(76, 1428),(77, 1381),(78, 1337),(79, 1295),
(80, 1254),(81, 1214),(82, 1176),(83, 1140),(84, 1104),
(85, 1070),(86, 1058),(87, 1006),(88, 956),(89, 946),
(90, 918),(91, 891),(92, 864),(93, 839),(94, 814),
(95, 791),(96, 768),(97, 768),(98, 724),(99, 704),
(100, 684),(101, 664),(102, 646),(103, 627),(104, 610),
(105, 593),(106, 577),(107, 561),(108, 545),(109, 530),
(110, 516),(111, 502),(112, 488),(113, 475),(114, 462),
(115, 450),(116, 438),(117, 426),(118, 415),(119, 404),
(120, 393),(121, 383),(122, 373),(123, 363),(124, 353),
(125, 344),(126, 335),(127, 326),(128, 318),(129, 310),
(130, 302),(131, 294),(132, 286),(133, 279),(134, 272),
(135, 265),(136, 258),(137, 251),(138, 245),(139, 238),
(140, 232),(141, 226),(142, 221),(143, 253),(144, 209),
(145, 204),(146, 199),(147, 194),(148, 189),(149, 184),
(150, 179)],dtype=tsTemperatureForm)

def main():
    print '温度传感器表格'
    x=[]
    y=[]
    for index in range(len(data_m)):
        #print data_m[index]['iTemperature'], data_m[index]['iResister']
        x.append(data_m[index]['iTemperature'])
    	y.append(data_m[index]['iResister'])

    print x
    print y

    plt.figure(figsize=(400,200))  # 创建绘图对象
    plt.plot(x,y, "b", linewidth=2)  # 在当前绘图对象绘图（X轴，Y轴，蓝色虚线，线宽度）
    plt.ylabel("Resister")  # X轴标签
    plt.xlabel("Temperature")  # Y轴标签
    plt.title("Temp Sensor")  # 图标题
    plt.xlim(-50, 150)
    plt.ylim(0, 350000)
    plt.gca().xaxis.set_major_formatter(ticker.FormatStrFormatter('%.6f'))

    plt.show()  # 显示图
    plt.savefig("line.jpg")  # 保存图


if __name__ == '__main__':
    main()