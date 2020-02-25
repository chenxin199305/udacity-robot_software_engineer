# 首先将export命令保存至export.sh文件，然后将文件修改为可执行权限，最后运行 source export.sh[2]即可。由于子shell对变量的修改无法影响到父shell，因此需要采用source或者.执行，而不是直接运行./export.sh[2]。
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_buildmyworld/world/build/
