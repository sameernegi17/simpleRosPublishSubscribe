#include <TurtleSim.h>
#include <geometry_msgs/Twist.h>
#include <string.h>

class TurtleSimPublisher : public TurtleSim
{
  private:
    ros::Publisher commandVelocityPublisher;
    geometry_msgs::Twist msg;
    ros::NodeHandle node_handle;
    int createRandomLinearVelocity();
    int createRandomAngularVelocity();

  public:
    TurtleSimPublisher(int argc, char **argv, const std::string node_name);
    ~TurtleSimPublisher();
    void createMessage();
    void publishMessage();
};
