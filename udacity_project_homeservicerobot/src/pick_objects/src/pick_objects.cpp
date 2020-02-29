#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

// Position Information
int robot_current_state = 0; // 0: from origin to target; 1: from target to origin

float origin[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float target[6] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  while (true)
  {
    
    move_base_msgs::MoveBaseGoal goal;

    // set up the frame parameters
    goal.target_pose.header.frame_id = "base_link";
    goal.target_pose.header.stamp = ros::Time::now();

    switch (robot_current_state)
    {
    case 0:
      // Define a position and orientation for the robot to reach
      goal.target_pose.pose.position.x = target[0];
      goal.target_pose.pose.position.y = target[1];
      goal.target_pose.pose.orientation.w = target[2];
      break;
    case 1:
      // Define a position and orientation for the robot to reach
      goal.target_pose.pose.position.x = origin[0];
      goal.target_pose.pose.position.y = origin[1];
      goal.target_pose.pose.orientation.w = origin[2];
      break;
    default:
      // Define a position and orientation for the robot to reach
      goal.target_pose.pose.position.x = target[0];
      goal.target_pose.pose.position.y = target[1];
      goal.target_pose.pose.orientation.w = target[2];
      break;
    }

    // Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its goal
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      ROS_INFO("Hooray, the base moved 1 meter forward");

      switch (robot_current_state)
      {
      case 0:
        robot_current_state = 1;
        break;
      case 1:
        robot_current_state = 0;
        break;    
      default:
        robot_current_state = 0;
        break;
      }

      ros::Duration(5).sleep();
    }
    else
    {
      ROS_INFO("The base failed to move forward 1 meter for some reason");
      return -1;
    }
  }
  
  return 0;
}