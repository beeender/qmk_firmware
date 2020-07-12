#pragma once

#include "quantum.h"


/*
  Matrix col/row mapping

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  | J6 |    | I4 | H4 | H2 | H6 | | A7 | E6 | D2 | D4 | | B4 | B7 | B6 | B0 | | C7 | C5 | A5 |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  | J4 | J7 | I7 | H7 | G7 | G4 | F4 | F7 | E7 | D7 | R7 | R4 | E4 |     B2 | | L4 | O4 | Q4 | | K1 | L1 | Q1 | Q0 |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  | J2   | J5 | I5 | H5 | G5 | G2 | F2 | F5 | E5 | D5 | R5 | R2 | E2 |   B3 | | K4 | O7 | Q7 | | K5 | L5 | Q5 | O5 |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  | O5    | J3 | I3 | H3 | G3 | G6 | F6 | F3 | E3 | D3 | R3 | R6 |       B1 |                  | K2 | L2 | Q2 |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  | N2      | J1 | I1 | H1 | G1 | G0 | F0 | F1 | E1 | D1 | R0 |          N3 |      | O6 |      | K3 | L3 | Q3 | O3 |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  | A4 | P2 | C6 |                  K6                  | C0 | M3 | D0 | A1 | | O0 | K0 | L0 | | L6      | Q6 |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'
*/
#define LAYOUT_104( \
  KO7,      KB4, KP4, KP2, KP7, KJ7, KK7, KM2, KM4, KJ4, KJ5, KG5, KF5,   KI5, KI3, KH6,                       \
  KO4, KO5, KB5, KP5, KQ5, KQ4, KN4, KN5, KK5, KM5, KL5, KL4, KK4, KJ2,   KF4, KH4, KE4,   KG6, KF6, KE6, KE0, \
  KO2, KO3, KB3, KP3, KQ3, KQ2, KN2, KN3, KK3, KM3, KL3, KL2, KK2, KJ1,   KG4, KH5, KE5,   KG3, KF3, KE3, KH3, \
  KB2, KO1, KB1, KP1, KQ1, KQ7, KN7, KN1, KK1, KM1, KL1, KL7,      KJ6,                    KG2, KF2, KE2,      \
  KD2, KO6, KB6, KP6, KQ6, KQ0, KN0, KN6, KK6, KM6, KL0,           KD6,        KH7,        KG1, KF1, KE1, KH1, \
  KC4, KR7, KI7,                KJ0,                KI0, KA0, KH2, KC6,   KH0, KG0, KF0,   KF7,      KE7      \
) \
{ \
/* Columns and rows need to be swapped in the below definition */ \
/*          0       1       2       3       4       5       6       7       8       9       A       B       C       D       E       F       0       1       */ \
/*          A       B       C       D       E       F       G       H       I       J       K       L       M       N       O       P       Q       R       */ \
/* 0 */ {   KA0,    KC_NO,  KC_NO,  KC_NO,  KE0,    KF0,    KG0,    KH0,    KI0,    KJ0,    KC_NO,  KL0,    KC_NO,  KN0,    KC_NO,  KC_NO,  KQ0,    KC_NO   }, \
/* 1 */ {   KC_NO,  KB1,    KC_NO,  KC_NO,  KE1,    KF1,    KG1,    KH1,    KC_NO,  KJ1,    KK1,    KL1,    KM1,    KN1,    KO1,    KP1,    KQ1,    KC_NO   }, \
/* 2 */ {   KC_NO,  KB2,    KC_NO,  KD2,    KE2,    KF2,    KG2,    KH2,    KC_NO,  KJ2,    KK2,    KL2,    KM2,    KN2,    KO2,    KP2,    KQ2,    KC_NO   }, \
/* 3 */ {   KC_NO,  KB3,    KC_NO,  KC_NO,  KE3,    KF3,    KG3,    KH3,    KI3,    KC_NO,  KK3,    KL3,    KM3,    KN3,    KO3,    KP3,    KQ3,    KC_NO   }, \
/* 4 */ {   KC_NO,  KB4,    KC4,    KC_NO,  KE4,    KF4,    KG4,    KH4,    KC_NO,  KJ4,    KK4,    KL4,    KM4,    KN4,    KO4,    KP4,    KQ4,    KC_NO   }, \
/* 5 */ {   KC_NO,  KB5,    KC_NO,  KC_NO,  KE5,    KF5,    KG5,    KH5,    KI5,    KJ5,    KK5,    KL5,    KM5,  KN5,    KO5,    KP5,    KQ5,  KC_NO   }, \
/* 6 */ {   KC_NO,  KB6,    KC6,    KD6,    KE6,    KF6,    KG6,    KH6,    KC_NO,  KJ6,    KK6,    KC_NO,  KM6,    KN6,    KO6,    KP6,    KQ6,    KC_NO   }, \
/* 7 */ {   KC_NO,  KC_NO,  KC_NO,  KC_NO,    KE7,    KF7,    KC_NO,  KH7,    KI7,    KJ7,    KK7,    KL7,    KC_NO,  KN7,    KO7,    KP7,    KQ7,    KR7     }  \
}
