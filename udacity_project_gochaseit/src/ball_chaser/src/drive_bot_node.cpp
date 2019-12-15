#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;
ros::ServiceServer command_robot_service;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities
bool handle_drive_request(
    ball_chaser::DriveToTarget::Request &request,
    ball_chaser::DriveToTarget::Response &response)
{
    ROS_INFO("request: linear_x=%f, angular_z=%f", request.linear_x, request.angular_z);
    // ROS_INFO("response: msg_feedback=%s", response.msg_feedback);
    
    // Create a motor_command object of type geometry_msgs::Twist
    geometry_msgs::Twist motor_command;
        
    // Set wheel velocities, forward [0.5, 0.0]
    motor_command.linear.x = 0.5;
    motor_command.angular.z = 0.0;
        
    // Publish angles to drive the robot
    motor_command_publisher.publish(motor_command);
}

int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    command_robot_service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);

    // TODO: Delete the loop, move the code to the inside of the callback function and make the necessary changes to publish the requested velocities instead of constant values
    // while (ros::ok()) {
    // }

    ROS_INFO("Ready to start /command_robot service.");

    // TODO: Handle ROS communication events
    ros::spin();

    return 0;
}