#include "ros/ros.h" //this is  a comment
#include "std_msgs/String.h"
#include <sstream> // to write somethingin the terminal


int main(int argc, char **argv){
    
	ros::init(argc, argv, "odom_node"); //, ros::init_options::AnonymousName);

	ros::NodeHandle n; // object that will be used to start the ros component

	ros::Publisher odom_node = n.advertise<std_msgs::String>("odometry", 1000);

	ros::Rate loop_rate(10);

	int count = 0;

  	while (ros::ok()){//same as TRUE, but ros ok will handle the shutdown of the nodes

	    	std_msgs::String msg;
    		std::stringstream ss;
    		ss << "hello world " << count;

    		msg.data = ss.str();
    		ROS_INFO("%s", msg.data.c_str());
    		chatter_pub.publish(msg);
    		ros::spinOnce();
    		loop_rate.sleep();
    		++count;
  	}
  	return 0;

}