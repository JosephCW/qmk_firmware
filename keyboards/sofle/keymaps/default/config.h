// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

// Determine L/R half based on data in EEPROM https://docs.qmk.fm/features/split_keyboard#handedness-by-eeprom
#define SPLIT_USB_DETECT

// Setup homerow mods for ctrl/alt/win
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 400
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
