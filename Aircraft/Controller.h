/**
* @Filename: Controller.h
* @Author: Kelly Hwong
* @Update: 2015.7.2
* @Description: 飞行器姿态控制器
*/

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "Utilities/Controller.h"

class Controller {
  unsigned int interval_unit_; // 调度时间单位，in mS，用来各个输出计算
  // 与调度器有关
  unsigned int interval_ticks_; // 调度间隔，in ticks
  unsigned int interval_counter_; // 调度计数
private:
  // 调度器的参数
  float routine_flag_;
  uint8_t routine_flag_int_;
  uint8_t routine_counter_;
  // 设置的三个角度
  float set_pitch_;
  float set_row_;
  float set_yaw_;
  // 测量的三个角度
  float measured_pitch_;
  float measured_row_;
  float measured_yaw_;

  // 控制器输出的电机的占空比，然后要接口给主函数中的Motor类（setduty）
  float motor1_duty_;
  float motor2_duty_;
  float motor3_duty_;
  float motor4_duty_;
public:
  /* 只能public了，虽然封装性不好，但是不这么做不能初始化 */
  // 实例化的PID类
  PID pid_pitch;
  PID pid_roll;
  PID pid_yaw;
  Controller();
  void InputParams(float pitch, float row, float yaw);
  void Routine(void); // 控制器控制例程（用调度器调度）
}; // class Stick

#ifdef __cplusplus
}
#endif

#endif
