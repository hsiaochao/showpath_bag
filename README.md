# showpath_bag

#### 介绍
使用rviz绘制.bag文件中的geometry_msgs/PoseStamped格式的path轨迹

#### 软件架构
软件架构说明
使用ROS系统和C++语言，配置参考CMakeLists.txt，通常只需要安装ROS和cmake。

#### 安装教程

下载源码到工作空间的src文件夹：
```
$ cd catkin_ws/src
$  git clone https://gitee.com/hsiaochao/showpath_bag
```
编译项目：
```
$ cd catkin_ws
$ source devel/setup.bash
$ catkin_make
```

#### 使用说明
在一个终端启动该项目：
```
$ roslaunch showpath_bag showpath01.launch
```
在另一个终端播放.bag文件
并将geometry_msgs/PoseStamped格式的话题名映射为/gt_traj，与程序内部对应，举例：
```
$ rosbag play --pause  /usr/myhome/dataset_M2DGR/door_01_gt.bag /door_01:=/gt_traj
```
即可完成在rviz播放轨迹，效果：
![rviz界面](https://foruda.gitee.com/images/1701418087474155652/d36dce14_10693581.png "屏幕截图")

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
