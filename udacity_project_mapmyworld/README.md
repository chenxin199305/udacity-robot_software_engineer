# Introduction to this workspace folder 
This is the project "Map My World".

The "src" folder contains all the source code.
The "devel" is for setup the PATH.
The "build" is for saving the files for CMake build process.

# Introduction to the "workspace - src" folder
## my_robot
It is the catkin_package for setup the Gazebo environment, and also the Rviz environment.
It uses the world and the robot built in the last project.
Run "roslaunch my_robot world.launch" to start the Gazebo and the Rviz worlds.

## teleop_twist_keyboard
It is the catkin_package for teleoperating the robot.
Run "rosrun teleop_twist_keyboard teleop_twist_keyboard" to make the teleoperation work.

## map_my_world
It is the catkin_package for mapping the virtual world.
Run "roslaunch map_my_world mapping.launch" to start the RTAB-map algorithm and prepare the database to store the map data.

# Problems
When running the map_my_world package, I get error message :

[ERROR] (2020-02-28 22:45:43.618) OccupancyGrid.cpp:1091::update() Large map size!! map min=(0.254994, -0.405777) max=(1282494093672912722161039310848.000000,29264923023776925352875524096.000000). There's maybe an error with the poses provided! The map will not be created!

Then, I can not have my map saved and no database created.

However, I think my map is just 1000 x 1000 pixel size. It is not that big?
I searched the Internet, but have no results of solving it. I have no idea of the "pose" it mentioned. Can you help me with that? Thank you.
