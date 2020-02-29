#include "ros/ros.h"
#include <sensor_msgs/Image.h>
//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"

// Define a global client that can request services
ros::ServiceClient client;
ros::ServiceServer server;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;
    client.call(srv);
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;
    
    // ROS_INFO("img: height=%d, width=%d", img.height, img.width);

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            unsigned char pixel_value = img.data[i * img.width + j];

            // As it is camera, due to light noise, it is really hard for it to get 255 value
            if (pixel_value > (white_pixel - 100))
            {
                ROS_INFO("img: position height=%d, width=%d, pixel_value=%d", i, j, pixel_value);

                if (j >= 0 && j < (img.width * 1 / 3))
                {
                    ROS_INFO("L");
                    drive_robot(0.1, 0.5);
                    goto result_success;
                }
                else if (j >= (img.width * 1 / 3) && j < (img.width * 2 / 3))
                {
                    ROS_INFO("M");
                    drive_robot(0.1, 0.0);
                    goto result_success;
                }
                else if (j > (img.width * 2 / 3) && j <= (img.width * 3 / 3))
                {
                    ROS_INFO("R");
                    drive_robot(0.1, -0.5);
                    goto result_success;
                }
                else
                {
                    ROS_INFO("M");
                    drive_robot(0.1, 0.0);
                    goto result_success;
                }
            }
            else 
            {
            }
        }
    }

    // ROS_INFO("Nothing");
    drive_robot(0.0, 0.0);

result_success:
result_fail:
    return;
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    ROS_INFO("Ready to start process_image node.");

    // Test Service communication
    /*
    while(ros::ok()) 
    {
        drive_robot(0.1, 0.0);
    }
    */

    // Handle ROS communication events
    ros::spin();

    return 0;
}