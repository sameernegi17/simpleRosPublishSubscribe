#include <TurtleSimSubscriber.h>
#include <nodesNameConstants.h>

int main(int argc, char **argv)
{
    TurtleSimSubscriber *turtleSimSubscriberObj = new TurtleSimSubscriber(argc, argv, VelocitySuscriberNode);
    turtleSimSubscriberObj->Subscribe();
}