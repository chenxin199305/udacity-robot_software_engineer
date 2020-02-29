# Introduction to this workspace folder
The "src" folder contains all the source code.
The "screenshot" contains the screenshot of the localized robot in rviz.
The "devel" is for setup the PATH.
The "build" is for saving the files for CMake build process.

# Introduction to the "workspace - src" folder
## my_robot
It is the catkin_package for setup the Gazebo environment.
It uses the world built in the last project.
Run "roslaunch my_robot world.launch" to start the Gazebo world.

## pgm_map_creator
It is for generate the map pgm file.
However, it seems that, even I just "git pull" this project from github, I still can not make this procject to create the pgm I want. I just draw one myself using the Photoshop tool.

## teleop_twist_keyboard
It is for teleoperation the robot.
Run "rosrun teleop_twist_keyboard teleop_twist_keyboard" to make the teleoperation work.

## where_am_i
It is for amcl --> localization.
Run "roslaunch where_am_i amcl" to start the amcl.

## The reason for not reach a very good performance localization
In the task, the reviewer said that the performance of the localization is not good. However, even I tried to change the map parameter and also the sensor sensing frequency, the localization is still bad. I think this is because my map is too simple, so the MCL can not actually feel quite sure about where the robot is. Will this be the reason, can you, the reviewer help me to figure it out?
