#include <gazebo/gazebo.hh>

namespace gazebo
{
    class ProjectGazeboPlugin : public WorldPlugin
    {
        public :
            ProjectGazeboPlugin() : WorldPlugin()
            {
                printf("Welcome to Jason’s World! \n");
            }

        public :
            void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {

            }
    };

    GZ_REGISTER_WORLD_PLUGIN(ProjectGazeboPlugin)
}