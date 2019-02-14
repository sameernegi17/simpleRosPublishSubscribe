#include <globalConstants.h>
#include <string.h>
#include <topicNameConstants.h>
#include <ros/ros.h>
#include <TurtleSimSubscriber.h>

long TurtleSimSubscriber::count = 0;

TurtleSimSubscriber::TurtleSimSubscriber(int argc, char **argv, const std::string node_name) : TurtleSim::TurtleSim(argc, argv, node_name)
{
}

void TurtleSimSubscriber::Subscribe()
{
    std::cout << "Inside Subscribe" << std::endl;
    commandVelocitySubscriber = node_handle.subscribe(CommandVelocityTopic, queueSize, &TurtleSimSubscriber::commandVelocitySubscriberCallback, this);
    ros::spin();
}
void TurtleSimSubscriber::commandVelocitySubscriberCallback(const geometry_msgs::Twist::ConstPtr &msg)
{
    print(msg);
    addCount();
}
void TurtleSimSubscriber::print(const geometry_msgs::Twist::ConstPtr &msg)
{
    std::cout << "Count : " << TurtleSimSubscriber::count << std::endl;
    std::cout << "  Linear" << std::endl;
    std::cout << "      x: " << msg->linear.x << "  y: " << msg->linear.y << "    z: " << msg->linear.z << std::endl;
    std::cout << "  Angular" << std::endl;
    std::cout << "      x: " << msg->angular.x << "  y: " << msg->angular.y << "    z: " << msg->angular.z << std::endl;
}

void TurtleSimSubscriber::addCount()
{
    TurtleSimSubscriber::count = TurtleSimSubscriber::count + 1;
}
TurtleSimSubscriber::~TurtleSimSubscriber()
{
}