#include "type.h"

// static 函数部分, 对应成员函数
static Sts _infor_get_sts(Infor* self) { return self->sts; }

static void _infor_set_sts(Infor* self, Sts status) { self->sts = status; }

static uint8 _infor_get_n(Infor* self) { return self->n; }

static void _infor_set_n(Infor* self, uint8 n) { self->n = n; }

static uint16 _infor_get_s(Infor* self) { return self->s; }

static void _infor_set_s(Infor* self, uint16 s) { self->s = s; }

static void _infor_get_passwd(Infor* self, char passwd[4]) {
  passwd = self->passwd;
}

static void _infor_set_passwd(Infor* self, char passwd[4]) {
  uint8 i;
  for (i = 0; i < 4; ++i) {
    self->passwd[i] = passwd[i];
  }
}

// @func 判断输入的密码和原本密码是否相同
// @param passwd char[4] 输入的密码
// @return bit 如果为0则不相等(false), 为1则相等(true)
static bit _infor_diff_passwd(Infor* self, char passwd[4]) {
  uint8 i;
  for (i = 0; i < 4; ++i) {
    if (self->passwd[i] != passwd[i]) {
      return 0;
    }
  }
  return 1;
}

// 密码锁信息对象 (单例对象)
static Infor infor = {
  LOCK, 3, 30, {'0', '0', '0', '0'}, _infor_get_sts, _infor_set_sts,
  _infor_get_n, _infor_set_n, _infor_get_s, _infor_set_s,
  _infor_get_passwd, _infor_set_passwd, _infor_diff_passwd
};

Infor* generator_infor(void) {
  return &infor;
}