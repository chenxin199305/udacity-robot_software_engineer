#!/bin/sh
export PARENT_DIR=$(cd $(dirname $0); cd .. ; pwd)
export TURTLEBOT_GAZEBO_WORLD_FILE=$PARENT_DIR/map/worlds/empty_world.world;

set -e pipefail

xterm -e "source /opt/ros/kinetic/setup.bash; roscore" &
sleep 5

xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 10

xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5

xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch" &
sleep 5
