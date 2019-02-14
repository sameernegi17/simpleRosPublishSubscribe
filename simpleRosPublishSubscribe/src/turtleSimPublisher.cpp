#include <geometry_msgs/Twist.h>
#include <string.h>
#include <topicNameConstants.h>
#include <globalConstants.h>
#include <TurtleSimPublisher.h>
#include <ros/ros.h>

TurtleSimPublisher::TurtleSimPublisher(int argc, char **argv, const std::string node_name) : TurtleSim::TurtleSim(argc, argv, node_name)
{
    commandVelocityPublisher = node_handle.advertise<geometry_msgs::Twist>(CommandVelocityTopic, queueSize);
}

void TurtleSimPublisher::publishMessage()
{
    commandVelocityPublisher.publish(msg);
}

void TurtleSimPublisher::createMessage()
{
    msg.linear.x = createRandomLinearVelocity();
    msg.angular.z = createRandomAngularVelocity();
}

int TurtleSimPublisher::createRandomLinearVelocity()
{
    return (rand() % velocity::max__linear_Velocity) + velocity::min__linear_Velocity;
}

int TurtleSimPublisher::createRandomAngularVelocity()
{
    return (rand() % velocity::max__angular_Velocity) + velocity ::min__angular_Velocity;
}

TurtleSimPublisher::~TurtleSimPublisher()
{
}
