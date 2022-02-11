#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_4391333410375007465);
void live_err_fun(double *nom_x, double *delta_x, double *out_3940639469994771400);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_1694960292761865224);
void live_H_mod_fun(double *state, double *out_42904283348084181);
void live_f_fun(double *state, double dt, double *out_7874582835499815417);
void live_F_fun(double *state, double dt, double *out_3722726511211153758);
void live_h_4(double *state, double *unused, double *out_5976239961768354351);
void live_H_4(double *state, double *unused, double *out_1122121832531392526);
void live_h_9(double *state, double *unused, double *out_1712402462391807216);
void live_H_9(double *state, double *unused, double *out_880932185901801881);
void live_h_10(double *state, double *unused, double *out_6207543687465342535);
void live_H_10(double *state, double *unused, double *out_1776259619404371354);
void live_h_12(double *state, double *unused, double *out_707597690636180498);
void live_H_12(double *state, double *unused, double *out_3897334575500569269);
void live_h_31(double *state, double *unused, double *out_8774465680980263829);
void live_H_31(double *state, double *unused, double *out_6642897607825582978);
void live_h_32(double *state, double *unused, double *out_6387039080365586005);
void live_H_32(double *state, double *unused, double *out_4998058098114683376);
void live_h_13(double *state, double *unused, double *out_2725471883186757127);
void live_H_13(double *state, double *unused, double *out_5593973629908948762);
void live_h_14(double *state, double *unused, double *out_1712402462391807216);
void live_H_14(double *state, double *unused, double *out_880932185901801881);
void live_h_33(double *state, double *unused, double *out_207473313627453862);
void live_H_33(double *state, double *unused, double *out_8653289461245111034);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}