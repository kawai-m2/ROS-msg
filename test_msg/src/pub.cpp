#include <ros/ros.h>

///パッケージ名/メッサージファイル.h
#include <test_msg/test.h>


double dd[6][6];

int main(int argc, char** argv)
{
  ros::init(argc, argv, "pub");
  ros::NodeHandle nh;
//<パッケージ名::使いたいメッセージファイル名>
  ros::Publisher pub = nh.advertise<test_msg::test>("msg/test", 10);

  ros::Rate loop_rate(1);
  while (ros::ok())
  {
    
    test_msg::test test_pub;
    test_pub.std ="Hello world";
    test_pub.i = 32;
    test_pub.f = 64.0;

    for (int i=0;i<6;i++)
      for(int j=0;j<6;j++)
        dd[i][j]=i+j*0.1;

    test_pub.darray.resize(36);
    for(int i=0;i<6;i++)
      for(int j=0;j<6;j++)
        test_pub.darray[i*6+j]=dd[i][j];

    pub.publish(test_pub);
    ros::spinOnce();
    loop_rate.sleep();
  }
}