# showpath_bag

#### introduce

Use rviz to draw path trajectories in geometry_msgs/PoseStamped format in. bag files

#### Software architecture

Software Architecture Description Using ROS system and C++language, refer to CMakeLists.txt for configuration, usually only ROS and cmake need to be installed.

#### Installation and Compilation

Download this source code into the src folder of your catkin worksapce  and catkin_make::
```
cd ~/catkin_ws/src
git clone https://github.com/hsiaochao/showpath_bag
cd ../
catkin_make
source ~/catkin_ws/devel/setup.bash
```

#### How to use it

1.Start the project on a terminal:
```
$ roslaunch showpath_bag showpath01.launch
```
2.Play. bag file on another terminal, And map the topic names in geometry_msgs/PoseStamped format to/gt_ Traj, corresponding to the internal program, for example:
```
$ rosbag play --pause  /usr/myhome/dataset_M2DGR/door_01_gt.bag /door_01:=/gt_traj
```
You can complete the playback trajectory in rviz.
#### Participate in contributions

    Fork warehouse
    Create a new Feature_ Xxx branch
    Submit code
    Create a new Pull Request
