#include <TurtleSimPublisher.h>
#include <nodesNameConstants.h>

int main(int argc, char **argv)
{
    TurtleSimPublisher *turtleSimPublisherObj = new TurtleSimPublisher(argc, argv, VelocityPublisherNode);
    while (ros::ok())
    {
        turtleSimPublisherObj->createMessage();
        turtleSimPublisherObj->publishMessage();
    }
}