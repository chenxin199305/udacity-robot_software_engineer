# README FIRST
## Notice
In order to realize printing "Welcome to Jason's World", 
- you need to export the /build path to GAZEBO_PLUGIN_PATH at first.
   - This command need to run directly in the command line tool.
   - Notice : Can use "echo $GAZEBO_PLUGIN_PATH" to view whether the path has set successfully or not.
   - `export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_buildmyworld/world/build/`


- use "gazebo world --verbose" to the print information.

## Info
1. /model containts the robot and wall model.
2. /script contains the script.cpp file for gazebo plugin.
3. /world contains the gazebo world file, with robot and wall mode in it.
