/* 
 * MVisor
 * Copyright (C) 2021 Terrence <terrence@tenclass.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _MVISOR_UI_FONT_H
#define _MVISOR_UI_FONT_H

unsigned char __font8x16[256][16] = {
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 0
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0, 126, 129, 165, 129, 129, 189,    // 1
    153, 129, 129, 126,   0,   0,   0,   0 },
  {   0,   0, 126, 255, 219, 255, 255, 195,    // 2
    231, 255, 255, 126,   0,   0,   0,   0 },
  {   0,   0,   0,   0, 108, 254, 254, 254,    // 3
    254, 124,  56,  16,   0,   0,   0,   0 },
  {   0,   0,   0,   0,  16,  56, 124, 254,    // 4
    124,  56,  16,   0,   0,   0,   0,   0 },
  {   0,   0,   0,  24,  60,  60, 231, 231,    // 5
    231,  24,  24,  60,   0,   0,   0,   0 },
  {   0,   0,   0,  24,  60, 126, 255, 255,    // 6
    126,  24,  24,  60,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,  24,  60,    // 7
     60,  24,   0,   0,   0,   0,   0,   0 },
  { 255, 255, 255, 255, 255, 255, 231, 195,    // 8
    195, 231, 255, 255, 255, 255, 255, 255 },
  {   0,   0,   0,   0,   0,  60, 102,  66,    // 9
     66, 102,  60,   0,   0,   0,   0,   0 },
  { 255, 255, 255, 255, 255, 195, 153, 189,    // 10
    189, 153, 195, 255, 255, 255, 255, 255 },
  {   0,   0,  30,  14,  26,  50, 120, 204,    // 11
    204, 204, 204, 120,   0,   0,   0,   0 },
  {   0,   0,  60, 102, 102, 102, 102,  60,    // 12
     24, 126,  24,  24,   0,   0,   0,   0 },
  {   0,   0,  63,  51,  63,  48,  48,  48,    // 13
     48, 112, 240, 224,   0,   0,   0,   0 },
  {   0,   0, 127,  99, 127,  99,  99,  99,    // 14
     99, 103, 231, 230, 192,   0,   0,   0 },
  {   0,   0,   0,  24,  24, 219,  60, 231,    // 15
     60, 219,  24,  24,   0,   0,   0,   0 },
  {   0, 128, 192, 224, 240, 248, 254, 248,    // 16
    240, 224, 192, 128,   0,   0,   0,   0 },
  {   0,   2,   6,  14,  30,  62, 254,  62,    // 17
     30,  14,   6,   2,   0,   0,   0,   0 },
  {   0,   0,  24,  60, 126,  24,  24,  24,    // 18
    126,  60,  24,   0,   0,   0,   0,   0 },
  {   0,   0, 102, 102, 102, 102, 102, 102,    // 19
    102,   0, 102, 102,   0,   0,   0,   0 },
  {   0,   0, 127, 219, 219, 219, 123,  27,    // 20
     27,  27,  27,  27,   0,   0,   0,   0 },
  {   0, 124, 198,  96,  56, 108, 198, 198,    // 21
    108,  56,  12, 198, 124,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 22
    254, 254, 254, 254,   0,   0,   0,   0 },
  {   0,   0,  24,  60, 126,  24,  24,  24,    // 23
    126,  60,  24, 126,   0,   0,   0,   0 },
  {   0,   0,  24,  60, 126,  24,  24,  24,    // 24
     24,  24,  24,  24,   0,   0,   0,   0 },
  {   0,   0,  24,  24,  24,  24,  24,  24,    // 25
     24, 126,  60,  24,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  24,  12, 254,    // 26
     12,  24,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  48,  96, 254,    // 27
     96,  48,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0, 192, 192,    // 28
    192, 254,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  40, 108, 254,    // 29
    108,  40,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,  16,  56,  56, 124,    // 30
    124, 254, 254,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0, 254, 254, 124, 124,    // 31
     56,  56,  16,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 32
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,  24,  60,  60,  60,  24,  24,    // 33
     24,   0,  24,  24,   0,   0,   0,   0 },
  {   0, 102, 102, 102,  36,   0,   0,   0,    // 34
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0, 108, 108, 254, 108, 108,    // 35
    108, 254, 108, 108,   0,   0,   0,   0 },
  {  24,  24, 124, 198, 194, 192, 124,   6,    // 36
      6, 134, 198, 124,  24,  24,   0,   0 },
  {   0,   0,   0,   0, 194, 198,  12,  24,    // 37
     48,  96, 198, 134,   0,   0,   0,   0 },
  {   0,   0,  56, 108, 108,  56, 118, 220,    // 38
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,  48,  48,  48,  96,   0,   0,   0,    // 39
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,  12,  24,  48,  48,  48,  48,    // 40
     48,  48,  24,  12,   0,   0,   0,   0 },
  {   0,   0,  48,  24,  12,  12,  12,  12,    // 41
     12,  12,  24,  48,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 102,  60, 255,    // 42
     60, 102,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  24,  24, 126,    // 43
     24,  24,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 44
      0,  24,  24,  24,  48,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0, 254,    // 45
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 46
      0,   0,  24,  24,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   2,   6,  12,  24,    // 47
     48,  96, 192, 128,   0,   0,   0,   0 },
  {   0,   0,  56, 108, 198, 198, 214, 214,    // 48
    198, 198, 108,  56,   0,   0,   0,   0 },
  {   0,   0,  24,  56, 120,  24,  24,  24,    // 49
     24,  24,  24, 126,   0,   0,   0,   0 },
  {   0,   0, 124, 198,   6,  12,  24,  48,    // 50
     96, 192, 198, 254,   0,   0,   0,   0 },
  {   0,   0, 124, 198,   6,   6,  60,   6,    // 51
      6,   6, 198, 124,   0,   0,   0,   0 },
  {   0,   0,  12,  28,  60, 108, 204, 254,    // 52
     12,  12,  12,  30,   0,   0,   0,   0 },
  {   0,   0, 254, 192, 192, 192, 252,   6,    // 53
      6,   6, 198, 124,   0,   0,   0,   0 },
  {   0,   0,  56,  96, 192, 192, 252, 198,    // 54
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 254, 198,   6,   6,  12,  24,    // 55
     48,  48,  48,  48,   0,   0,   0,   0 },
  {   0,   0, 124, 198, 198, 198, 124, 198,    // 56
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 124, 198, 198, 198, 126,   6,    // 57
      6,   6,  12, 120,   0,   0,   0,   0 },
  {   0,   0,   0,   0,  24,  24,   0,   0,    // 58
      0,  24,  24,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,  24,  24,   0,   0,    // 59
      0,  24,  24,  48,   0,   0,   0,   0 },
  {   0,   0,   0,   6,  12,  24,  48,  96,    // 60
     48,  24,  12,   6,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 126,   0,   0,    // 61
    126,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,  96,  48,  24,  12,   6,    // 62
     12,  24,  48,  96,   0,   0,   0,   0 },
  {   0,   0, 124, 198, 198,  12,  24,  24,    // 63
     24,   0,  24,  24,   0,   0,   0,   0 },
  {   0,   0,   0, 124, 198, 198, 222, 222,    // 64
    222, 220, 192, 124,   0,   0,   0,   0 },
  {   0,   0,  16,  56, 108, 198, 198, 254,    // 65
    198, 198, 198, 198,   0,   0,   0,   0 },
  {   0,   0, 252, 102, 102, 102, 124, 102,    // 66
    102, 102, 102, 252,   0,   0,   0,   0 },
  {   0,   0,  60, 102, 194, 192, 192, 192,    // 67
    192, 194, 102,  60,   0,   0,   0,   0 },
  {   0,   0, 248, 108, 102, 102, 102, 102,    // 68
    102, 102, 108, 248,   0,   0,   0,   0 },
  {   0,   0, 254, 102,  98, 104, 120, 104,    // 69
     96,  98, 102, 254,   0,   0,   0,   0 },
  {   0,   0, 254, 102,  98, 104, 120, 104,    // 70
     96,  96,  96, 240,   0,   0,   0,   0 },
  {   0,   0,  60, 102, 194, 192, 192, 222,    // 71
    198, 198, 102,  58,   0,   0,   0,   0 },
  {   0,   0, 198, 198, 198, 198, 254, 198,    // 72
    198, 198, 198, 198,   0,   0,   0,   0 },
  {   0,   0,  60,  24,  24,  24,  24,  24,    // 73
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,   0,  30,  12,  12,  12,  12,  12,    // 74
    204, 204, 204, 120,   0,   0,   0,   0 },
  {   0,   0, 230, 102, 102, 108, 120, 120,    // 75
    108, 102, 102, 230,   0,   0,   0,   0 },
  {   0,   0, 240,  96,  96,  96,  96,  96,    // 76
     96,  98, 102, 254,   0,   0,   0,   0 },
  {   0,   0, 198, 238, 254, 254, 214, 198,    // 77
    198, 198, 198, 198,   0,   0,   0,   0 },
  {   0,   0, 198, 230, 246, 254, 222, 206,    // 78
    198, 198, 198, 198,   0,   0,   0,   0 },
  {   0,   0, 124, 198, 198, 198, 198, 198,    // 79
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 252, 102, 102, 102, 124,  96,    // 80
     96,  96,  96, 240,   0,   0,   0,   0 },
  {   0,   0, 124, 198, 198, 198, 198, 198,    // 81
    198, 214, 222, 124,  12,  14,   0,   0 },
  {   0,   0, 252, 102, 102, 102, 124, 108,    // 82
    102, 102, 102, 230,   0,   0,   0,   0 },
  {   0,   0, 124, 198, 198,  96,  56,  12,    // 83
      6, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 126, 126,  90,  24,  24,  24,    // 84
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,   0, 198, 198, 198, 198, 198, 198,    // 85
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 198, 198, 198, 198, 198, 198,    // 86
    198, 108,  56,  16,   0,   0,   0,   0 },
  {   0,   0, 198, 198, 198, 198, 214, 214,    // 87
    214, 254, 238, 108,   0,   0,   0,   0 },
  {   0,   0, 198, 198, 108, 124,  56,  56,    // 88
    124, 108, 198, 198,   0,   0,   0,   0 },
  {   0,   0, 102, 102, 102, 102,  60,  24,    // 89
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,   0, 254, 198, 134,  12,  24,  48,    // 90
     96, 194, 198, 254,   0,   0,   0,   0 },
  {   0,   0,  60,  48,  48,  48,  48,  48,    // 91
     48,  48,  48,  60,   0,   0,   0,   0 },
  {   0,   0,   0, 128, 192, 224, 112,  56,    // 92
     28,  14,   6,   2,   0,   0,   0,   0 },
  {   0,   0,  60,  12,  12,  12,  12,  12,    // 93
     12,  12,  12,  60,   0,   0,   0,   0 },
  {  16,  56, 108, 198,   0,   0,   0,   0,    // 94
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 95
      0,   0,   0,   0,   0, 255,   0,   0 },
  {   0,  48,  24,  12,   0,   0,   0,   0,    // 96
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 120,  12, 124,    // 97
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,   0, 224,  96,  96, 120, 108, 102,    // 98
    102, 102, 102, 124,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 124, 198, 192,    // 99
    192, 192, 198, 124,   0,   0,   0,   0 },
  {   0,   0,  28,  12,  12,  60, 108, 204,    // 100
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 124, 198, 254,    // 101
    192, 192, 198, 124,   0,   0,   0,   0 },
  {   0,   0,  28,  54,  50,  48, 120,  48,    // 102
     48,  48,  48, 120,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 118, 204, 204,    // 103
    204, 204, 204, 124,  12, 204, 120,   0 },
  {   0,   0, 224,  96,  96, 108, 118, 102,    // 104
    102, 102, 102, 230,   0,   0,   0,   0 },
  {   0,   0,  24,  24,   0,  56,  24,  24,    // 105
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,   0,   6,   6,   0,  14,   6,   6,    // 106
      6,   6,   6,   6, 102, 102,  60,   0 },
  {   0,   0, 224,  96,  96, 102, 108, 120,    // 107
    120, 108, 102, 230,   0,   0,   0,   0 },
  {   0,   0,  56,  24,  24,  24,  24,  24,    // 108
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 236, 254, 214,    // 109
    214, 214, 214, 198,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 220, 102, 102,    // 110
    102, 102, 102, 102,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 124, 198, 198,    // 111
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 220, 102, 102,    // 112
    102, 102, 102, 124,  96,  96, 240,   0 },
  {   0,   0,   0,   0,   0, 118, 204, 204,    // 113
    204, 204, 204, 124,  12,  12,  30,   0 },
  {   0,   0,   0,   0,   0, 220, 118, 102,    // 114
     96,  96,  96, 240,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 124, 198,  96,    // 115
     56,  12, 198, 124,   0,   0,   0,   0 },
  {   0,   0,  16,  48,  48, 252,  48,  48,    // 116
     48,  48,  54,  28,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 204, 204, 204,    // 117
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 198, 198, 198,    // 118
    198, 198, 108,  56,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 198, 198, 214,    // 119
    214, 214, 254, 108,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 198, 108,  56,    // 120
     56,  56, 108, 198,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 198, 198, 198,    // 121
    198, 198, 198, 126,   6,  12, 248,   0 },
  {   0,   0,   0,   0,   0, 254, 204,  24,    // 122
     48,  96, 198, 254,   0,   0,   0,   0 },
  {   0,   0,  14,  24,  24,  24, 112,  24,    // 123
     24,  24,  24,  14,   0,   0,   0,   0 },
  {   0,   0,  24,  24,  24,  24,  24,  24,    // 124
     24,  24,  24,  24,   0,   0,   0,   0 },
  {   0,   0, 112,  24,  24,  24,  14,  24,    // 125
     24,  24,  24, 112,   0,   0,   0,   0 },
  {   0, 118, 220,   0,   0,   0,   0,   0,    // 126
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,  16,  56, 108, 198,    // 127
    198, 198, 254,   0,   0,   0,   0,   0 },
  {   0,   0,  60, 102, 194, 192, 192, 192,    // 128
    192, 194, 102,  60,  24, 112,   0,   0 },
  {   0,   0, 204,   0,   0, 204, 204, 204,    // 129
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,  12,  24,  48,   0, 124, 198, 254,    // 130
    192, 192, 198, 124,   0,   0,   0,   0 },
  {   0,  16,  56, 108,   0, 120,  12, 124,    // 131
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,   0, 204,   0,   0, 120,  12, 124,    // 132
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,  96,  48,  24,   0, 120,  12, 124,    // 133
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,  56, 108,  56,   0, 120,  12, 124,    // 134
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 124, 198, 192,    // 135
    192, 192, 198, 124,  24, 112,   0,   0 },
  {   0,  16,  56, 108,   0, 124, 198, 254,    // 136
    192, 192, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 198,   0,   0, 124, 198, 254,    // 137
    192, 192, 198, 124,   0,   0,   0,   0 },
  {   0,  96,  48,  24,   0, 124, 198, 254,    // 138
    192, 192, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 102,   0,   0,  56,  24,  24,    // 139
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,  24,  60, 102,   0,  56,  24,  24,    // 140
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,  96,  48,  24,   0,  56,  24,  24,    // 141
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0, 198,   0,  16,  56, 108, 198, 198,    // 142
    254, 198, 198, 198,   0,   0,   0,   0 },
  {  56, 108,  56,  16,  56, 108, 198, 198,    // 143
    254, 198, 198, 198,   0,   0,   0,   0 },
  {  12,  24,   0, 254, 102,  98, 104, 120,    // 144
    104,  98, 102, 254,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 236,  54,  54,    // 145
    126, 216, 216, 110,   0,   0,   0,   0 },
  {   0,   0,  62, 108, 204, 204, 254, 204,    // 146
    204, 204, 204, 206,   0,   0,   0,   0 },
  {   0,  16,  56, 108,   0, 124, 198, 198,    // 147
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 198,   0,   0, 124, 198, 198,    // 148
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,  96,  48,  24,   0, 124, 198, 198,    // 149
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,  48, 120, 204,   0, 204, 204, 204,    // 150
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,  96,  48,  24,   0, 204, 204, 204,    // 151
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,   0, 198,   0,   0, 198, 198, 198,    // 152
    198, 198, 198, 126,   6,  12, 120,   0 },
  {   0, 198,   0, 124, 198, 198, 198, 198,    // 153
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0, 198,   0, 198, 198, 198, 198, 198,    // 154
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 124, 206, 222,    // 155
    246, 230, 198, 124,   0,   0,   0,   0 },
  {   0,  56, 108, 100,  96, 240,  96,  96,    // 156
     96,  96, 230, 252,   0,   0,   0,   0 },
  {   0,   4, 124, 206, 206, 214, 214, 214,    // 157
    214, 230, 230, 124,  64,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 198, 108,  56,    // 158
     56, 108, 198,   0,   0,   0,   0,   0 },
  {   0,  14,  27,  24,  24,  24, 126,  24,    // 159
     24,  24, 216, 112,   0,   0,   0,   0 },
  {   0,  24,  48,  96,   0, 120,  12, 124,    // 160
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,  12,  24,  48,   0,  56,  24,  24,    // 161
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0,  24,  48,  96,   0, 124, 198, 198,    // 162
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,  24,  48,  96,   0, 204, 204, 204,    // 163
    204, 204, 204, 118,   0,   0,   0,   0 },
  {   0,   0, 118, 220,   0, 220, 102, 102,    // 164
    102, 102, 102, 102,   0,   0,   0,   0 },
  { 118, 220,   0, 198, 230, 246, 254, 222,    // 165
    206, 198, 198, 198,   0,   0,   0,   0 },
  {   0,   0,  60, 108, 108,  62,   0, 126,    // 166
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,  56, 108, 108,  56,   0, 124,    // 167
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,  48,  48,   0,  48,  48,  96,    // 168
    192, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 124, 130, 178, 170, 178, 170,    // 169
    170, 130, 124,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0, 254,   6,    // 170
      6,   6,   6,   0,   0,   0,   0,   0 },
  {   0,  96, 224,  98, 102, 108,  24,  48,    // 171
     96, 220, 134,  12,  24,  62,   0,   0 },
  {   0,  96, 224,  98, 102, 108,  24,  48,    // 172
    102, 206, 154,  63,   6,   6,   0,   0 },
  {   0,   0,  24,  24,   0,  24,  24,  24,    // 173
     60,  60,  60,  24,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  54, 108, 216,    // 174
    108,  54,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 216, 108,  54,    // 175
    108, 216,   0,   0,   0,   0,   0,   0 },
  {  17,  68,  17,  68,  17,  68,  17,  68,    // 176
     17,  68,  17,  68,  17,  68,  17,  68 },
  {  85, 170,  85, 170,  85, 170,  85, 170,    // 177
     85, 170,  85, 170,  85, 170,  85, 170 },
  { 221, 119, 221, 119, 221, 119, 221, 119,    // 178
    221, 119, 221, 119, 221, 119, 221, 119 },
  {  24,  24,  24,  24,  24,  24,  24,  24,    // 179
     24,  24,  24,  24,  24,  24,  24,  24 },
  {  24,  24,  24,  24,  24,  24,  24, 248,    // 180
     24,  24,  24,  24,  24,  24,  24,  24 },
  {  96, 192,  16,  56, 108, 198, 198, 254,    // 181
    198, 198, 198, 198,   0,   0,   0,   0 },
  { 124, 198,  16,  56, 108, 198, 198, 254,    // 182
    198, 198, 198, 198,   0,   0,   0,   0 },
  {  12,   6,  16,  56, 108, 198, 198, 254,    // 183
    198, 198, 198, 198,   0,   0,   0,   0 },
  {   0,   0, 124, 130, 154, 162, 162, 162,    // 184
    154, 130, 124,   0,   0,   0,   0,   0 },
  {  54,  54,  54,  54,  54, 246,   6, 246,    // 185
     54,  54,  54,  54,  54,  54,  54,  54 },
  {  54,  54,  54,  54,  54,  54,  54,  54,    // 186
     54,  54,  54,  54,  54,  54,  54,  54 },
  {   0,   0,   0,   0,   0, 254,   6, 246,    // 187
     54,  54,  54,  54,  54,  54,  54,  54 },
  {  54,  54,  54,  54,  54, 246,   6, 254,    // 188
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,  24,  24, 124, 198, 192, 192,    // 189
    198, 124,  24,  24,   0,   0,   0,   0 },
  {   0,   0,   0, 102, 102,  60,  24, 126,    // 190
     24, 126,  24,  24,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0, 248,    // 191
     24,  24,  24,  24,  24,  24,  24,  24 },
  {  24,  24,  24,  24,  24,  24,  24,  31,    // 192
      0,   0,   0,   0,   0,   0,   0,   0 },
  {  24,  24,  24,  24,  24,  24,  24, 255,    // 193
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0, 255,    // 194
     24,  24,  24,  24,  24,  24,  24,  24 },
  {  24,  24,  24,  24,  24,  24,  24,  31,    // 195
     24,  24,  24,  24,  24,  24,  24,  24 },
  {   0,   0,   0,   0,   0,   0,   0, 255,    // 196
      0,   0,   0,   0,   0,   0,   0,   0 },
  {  24,  24,  24,  24,  24,  24,  24, 255,    // 197
     24,  24,  24,  24,  24,  24,  24,  24 },
  {   0,   0, 118, 220,   0, 120,  12, 124,    // 198
    204, 204, 204, 118,   0,   0,   0,   0 },
  { 118, 220,   0,  56, 108, 198, 198, 254,    // 199
    198, 198, 198, 198,   0,   0,   0,   0 },
  {  54,  54,  54,  54,  54,  55,  48,  63,    // 200
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  63,  48,  55,    // 201
     54,  54,  54,  54,  54,  54,  54,  54 },
  {  54,  54,  54,  54,  54, 247,   0, 255,    // 202
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 255,   0, 247,    // 203
     54,  54,  54,  54,  54,  54,  54,  54 },
  {  54,  54,  54,  54,  54,  55,  48,  55,    // 204
     54,  54,  54,  54,  54,  54,  54,  54 },
  {   0,   0,   0,   0,   0, 255,   0, 255,    // 205
      0,   0,   0,   0,   0,   0,   0,   0 },
  {  54,  54,  54,  54,  54, 247,   0, 247,    // 206
     54,  54,  54,  54,  54,  54,  54,  54 },
  {   0,   0,   0,   0, 198, 124, 198, 198,    // 207
    198, 198, 124, 198,   0,   0,   0,   0 },
  {   0,   0,  52,  24,  44,   6,  62, 102,    // 208
    102, 102, 102,  60,   0,   0,   0,   0 },
  {   0,   0, 248, 108, 102, 102, 246, 102,    // 209
    102, 102, 108, 248,   0,   0,   0,   0 },
  {  56, 108,   0, 254, 102,  98, 104, 120,    // 210
    104,  98, 102, 254,   0,   0,   0,   0 },
  {   0, 198,   0, 254, 102,  98, 104, 120,    // 211
    104,  98, 102, 254,   0,   0,   0,   0 },
  {  48,  24,   0, 254, 102,  98, 104, 120,    // 212
    104,  98, 102, 254,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  56,  24,  24,    // 213
     24,  24,  24,  60,   0,   0,   0,   0 },
  {  12,  24,   0,  60,  24,  24,  24,  24,    // 214
     24,  24,  24,  60,   0,   0,   0,   0 },
  {  60, 102,   0,  60,  24,  24,  24,  24,    // 215
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0, 102,   0,  60,  24,  24,  24,  24,    // 216
     24,  24,  24,  60,   0,   0,   0,   0 },
  {  24,  24,  24,  24,  24,  24,  24, 248,    // 217
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,  31,    // 218
     24,  24,  24,  24,  24,  24,  24,  24 },
  { 255, 255, 255, 255, 255, 255, 255, 255,    // 219
    255, 255, 255, 255, 255, 255, 255, 255 },
  {   0,   0,   0,   0,   0,   0,   0, 255,    // 220
    255, 255, 255, 255, 255, 255, 255, 255 },
  {   0,  24,  24,  24,  24,  24,   0,   0,    // 221
     24,  24,  24,  24,  24,   0,   0,   0 },
  {  48,  24,   0,  60,  24,  24,  24,  24,    // 222
     24,  24,  24,  60,   0,   0,   0,   0 },
  { 255, 255, 255, 255, 255, 255, 255,   0,    // 223
      0,   0,   0,   0,   0,   0,   0,   0 },
  {  24,  48,   0, 124, 198, 198, 198, 198,    // 224
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 120, 204, 204, 204, 216, 204,    // 225
    198, 198, 198, 204,   0,   0,   0,   0 },
  {  56, 108,   0, 124, 198, 198, 198, 198,    // 226
    198, 198, 198, 124,   0,   0,   0,   0 },
  {  48,  24,   0, 124, 198, 198, 198, 198,    // 227
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0, 118, 220,   0, 124, 198, 198,    // 228
    198, 198, 198, 124,   0,   0,   0,   0 },
  { 118, 220,   0, 124, 198, 198, 198, 198,    // 229
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0, 102, 102, 102,    // 230
    102, 102, 102, 124,  96,  96, 192,   0 },
  {   0,   0, 224,  96,  96, 124, 102, 102,    // 231
    102, 102, 102, 124,  96,  96, 240,   0 },
  {   0,   0, 240,  96, 124, 102, 102, 102,    // 232
    102, 124,  96, 240,   0,   0,   0,   0 },
  {  24,  48,   0, 198, 198, 198, 198, 198,    // 233
    198, 198, 198, 124,   0,   0,   0,   0 },
  {  56, 108,   0, 198, 198, 198, 198, 198,    // 234
    198, 198, 198, 124,   0,   0,   0,   0 },
  {  48,  24,   0, 198, 198, 198, 198, 198,    // 235
    198, 198, 198, 124,   0,   0,   0,   0 },
  {   0,  12,  24,  48,   0, 198, 198, 198,    // 236
    198, 198, 198, 126,   6,  12, 248,   0 },
  {  12,  24,   0, 102, 102, 102, 102,  60,    // 237
     24,  24,  24,  60,   0,   0,   0,   0 },
  {   0, 255,   0,   0,   0,   0,   0,   0,    // 238
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,  12,  24,  48,   0,   0,   0,   0,    // 239
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0, 254,    // 240
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,  24,  24, 126,  24,    // 241
     24,   0,   0, 126,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 242
      0,   0,   0,   0, 255,   0, 255,   0 },
  {   0, 224,  48,  98,  54, 236,  24,  48,    // 243
    102, 206, 154,  63,   6,   6,   0,   0 },
  {   0,   0, 127, 219, 219, 219, 123,  27,    // 244
     27,  27,  27,  27,   0,   0,   0,   0 },
  {   0, 124, 198,  96,  56, 108, 198, 198,    // 245
    108,  56,  12, 198, 124,   0,   0,   0 },
  {   0,   0,   0,   0,   0,  24,   0, 126,    // 246
      0,  24,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 247
      0,   0,   0,  24,  12, 120,   0,   0 },
  {   0,  56, 108, 108,  56,   0,   0,   0,    // 248
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0, 198,   0,   0,   0,   0,   0,   0,    // 249
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,  24,    // 250
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,  24,  56,  24,  24,  24,  60,   0,    // 251
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0, 124,   6,  60,   6,   6, 124,   0,    // 252
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,  60, 102,  12,  24,  50, 126,   0,    // 253
      0,   0,   0,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0, 126, 126, 126, 126,    // 254
    126, 126, 126,   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0,   0,   0,   0,    // 255
      0,   0,   0,   0,   0,   0,   0,   0 }};

#endif // _MVISOR_UI_FONT_H
