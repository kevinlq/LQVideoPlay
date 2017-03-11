## 视频播放器的简单实现

### 编写原因

在2017年1月22日晚上，坐火车回家，本来想下载一部电影在火车上看，曾想到，新配的电脑没有安装任何播放器，这样就比较尴尬了，window自带的播放器是不能播放RMVB格式视频的，无奈之下想到了自己写一个，以前没有编写过，这次想使用一个第三方库来实现，由于对VLC相对了解，所以选择了这个库。

### 效果图

![整体效果图1](https://github.com/kevinlq/LQVideoPlay/tree/master/LQVideoPlay/screen/1.png)
![整体效果图2](https://github.com/kevinlq/LQVideoPlay/tree/master/LQVideoPlay/screen/2.png)
![整体效果图3](https://github.com/kevinlq/LQVideoPlay/tree/master/LQVideoPlay/screen/3.png)

### 环境介绍
windows 7 64位
Qt 4.8.6(mingw32)

### 功能介绍
1.自定义标题栏；
2.自定义底部播放控制栏；
3.封装了第三方库VLC，可以方便进行播放控制；
4.可以添加视频文件，支持多选了单选；
5.实现了快进快退操作

### 注意事项
编译完成后需要拷贝一些VLC库文件，具体路径根据自己版本进行拷贝：
1.debug版本：拷贝到$$PWD/bin/debug/
2.release版本：拷贝到$$PWD/bin/release/


  [1]: https://github.com/kevinlq/LQVideoPlay/tree/master/LQVideoPlay/screen/1.png
  [2]: ./images/2017-02-03_21-09-54.png "2017-02-03_21-09-54.png"
  [3]: ./images/2017-02-03_21-15-29.png "2017-02-03_21-15-29.png"