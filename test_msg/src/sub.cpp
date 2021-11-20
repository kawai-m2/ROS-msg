#include <ros/ros.h>

///パッケージ名/メッサージファイル.h
#include <test_msg/test.h>

int sub_i;
float sub_f;
double dd[6][6];


void massegeCallbnack(const test_msg::test & test_sub){
  sub_i = test_sub.i;
  sub_f = test_sub.f;
  ROS_INFO("%d,%f",sub_i,sub_f);
 

  for (int i=0;i<6;i++){
    for(int j=0;j<6;j++)
      dd[i][j]=test_sub.darray[i*6+j];
      ROS_INFO("%d: %f,%f,%f,%f,%f,%f,",i,dd[i][0],dd[i][1],dd[i][2],dd[i][3],dd[i][4],dd[i][5]);
  }
}
int main(int argc, char** argv)
{
  ros::init(argc, argv, "sub");
  ros::NodeHandle nh;
//<パッケージ名::使いたいメッセージファイル名>
  ros::Subscriber sub = nh.subscribe("msg/test",10,massegeCallbnack);

  ros::Rate loop_rate(1);
  while (ros::ok())
  {
    
    ros::spinOnce();
    loop_rate.sleep();
  }
}