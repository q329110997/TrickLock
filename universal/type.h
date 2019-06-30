/*
 * type.h
 * 密码锁项目的通用类型
 * 2019.06.27 00:00, 刘鑫 <ginshio78@gmail.com>
 */

#ifndef TYPE_H_
#define TYPE_H_

#include <reg52.h>

// 基础类型定义
typedef signed char int8;     // 8位有符号整型: int8
typedef unsigned char uint8;  // 8位无符号整型: uint8
typedef signed int int16;     // 16位有符号整型: int16
typedef unsigned int uint16;  // 16位无符号整型: uint16

////////////////////////////////////

// 类型: 枚举密码锁状态
// 锁(LOCK), 解锁(UNLOCK), 错误等待(ERROR)
// 设置N(SET_N), 设置S(SET_S), 设置密码(SET_PASSWD)
typedef enum Status {LOCK, UNLOCK, ERROR, SET_N, SET_S, SET_PASSWD} Sts;

// 应用类型: 密码锁信息
typedef struct Information {
  //////////// 成员变量 ////////////
  Sts sts;  // 密码锁当前状态
  uint16 n: 5;   // 可错误次数
  uint16 s: 11;  // 错误等待时间
  char passwd[4];  // 密码

  /////////// 成员函数 /////////////
  // 获取当前锁状态
  Sts (* const get_sts)(struct Information* self);
  // 设置当前锁状态
  void (* const set_sts)(struct Information* self, Sts status);
  // 获取可错误次数n
  uint8 (* const get_n)(struct Information* self);
  // 修改可错误次数n
  void (* const set_n)(struct Information* self, uint8 n);
  // 获取错误等待时间s
  uint16 (* const get_s)(struct Information* self);
  // 修改错误等待时间s
  void (* const set_s)(struct Information* self, uint16 s);
  // 获取当前密码passwd
  void (* const get_passwd)(struct Information* self, char passwd[4]);
  // 修改当前密码passwd
  void (* const set_passwd)(struct Information* self, char passwd[4]);
  // 对比输入密码和当前密码
  void (* const diff_passwd)(struct Information* self, char passwd[4]);
} Infor;

// 生成密码锁信息对象 (单例模式)
Infor* generator_infor(void);

#endif  // TYPE_H_
