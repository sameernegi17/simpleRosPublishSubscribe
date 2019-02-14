#include <TurtleSim.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

class TurtleSimSubscriber : public TurtleSim
{
  private:
    ros::Subscriber commandVelocitySubscriber;
    ros::NodeHandle node_handle;
    static long count;
    void print(const geometry_msgs::Twist::ConstPtr &msg);
    void addCount();

  public:
    TurtleSimSubscriber(int argc, char **argv, const std::string node_name);
    void commandVelocitySubscriberCallback(const geometry_msgs::Twist::ConstPtr &msg);
    void Subscribe();
    ~TurtleSimSubscriber();
};
