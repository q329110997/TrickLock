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
} Infor;

#endif  // TYPE_H_
