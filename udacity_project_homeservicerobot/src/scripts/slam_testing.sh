#!/bin/sh
export PARENT_DIR=$(cd $(dirname $0); cd .. ; pwd)
export TURTLEBOT_GAZEBO_WORLD_FILE=$PARENT_DIR/map/worlds/empty_world.world;

echo "PARENT_DIR="$PARENT_DIR
echo "TURTLEBOT_GAZEBO_WORLD_FILE="$TURTLEBOT_GAZEBO_WORLD_FILE

xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 10

xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch" &
sleep 5

xterm -e "roslaunch gmapping slam_gmapping_pr2.launch" &
sleep 5

xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
