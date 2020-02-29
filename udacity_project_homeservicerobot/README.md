# Introduction to this workspace folder 
This is the project "Home Service Robot".

The "src" folder contains all the source code.
The "devel" is for setup the PATH.
The "build" is for saving the files for CMake build process.

# Introduction to the "workspace - src" folder
## scripts
The "scripts" folder is for storing all the shell files

### launch.sh
"launch.sh" is for complete the "Shell Script" test in this project. It just start the Gazebo and Rviz at the same time, and do nothing else.

### slam_testing.sh
"slam_testing.sh" is for complete the "SLAM Testing" test in this project. It launchs the:
1. turtlebot_world.launch file to deploy a turtlebot in my environment.
2. gmapping_demo.launch file to run slam_gmapping to perform SLAM.
3. view_navigation.launch to observe the map in rviz.
4. keyboard_teleop.launch to manually control the robot with keyboard commands.

**However, when I try this slam_testing.sh, I cannot control the robot using the teleop package. I checked the Gazebo and the Rviz, and I find that the Tranform value has error on Rviz. It says it can not find the transform from Base_Link to the Left_Wheel_Link and the Right_Wheel_Link. I think that's why I cannot control these two wheels, but I not sure how to fix it, because the robot model, the urdf file, is predefined. I don't think I should change it? Can you help me with that problem? Thanks.**

### home_service_robot.sh
"home_service_robot.sh" is for starting all the nodes related to this project tasks.


## turtlebot_simulator
It is the catkin_package for setup the Gazebo environment.
It uses the world built in the last project, but using the robot turtlebot.
Run `roslaunch turtlebot_gazebo turtlebot_world.launch` to start the Gazebo world.

## turtlebot
It is the catkin_package for teleoperating the robot.
Run `roslaunch turtlebot_teleop keyboard_teleop.launch` to make the teleoperation work.

## slam_gmapping
It is the catkin_package for mapping the virtual world.
Run `roslaunch gmapping slam_gmapping_pr2.launch` to start the mapping algorithm.

## turtlebot_interaction
It is the catkin_package for start the rviz.
Run `roslaunch turtlebot_rviz_launchers view_navigation.launch` to start the rviz world.

## map
It is the catkin_package for store gazebo world file and map generated from SLAM.

## rvizConfig
It is the catkin_package for store customized rviz configuration files.

## pick_objects
It is the catkin_package for drive the robot to do pickup and drop off operations.

## add_markers
It is the catkin_package for write a node to model the object with a marker in rviz.

# Problems
When running the map_my_world package, I get error message :

[ERROR] (2020-02-28 22:45:43.618) OccupancyGrid.cpp:1091::update() Large map size!! map min=(0.254994, -0.405777) max=(1282494093672912722161039310848.000000,29264923023776925352875524096.000000). There's maybe an error with the poses provided! The map will not be created!

Then, I can not have my map saved and no database created.

** However, I think my map is just 1000 x 1000 pixel size. It is not that big?
I searched the Internet, but have no results of solving it. I have no idea of the "pose" it mentioned. Can you help me with that? Thank you.
