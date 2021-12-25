/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 *
 */
#pragma once

class AxisSettingsHandler {
  private:
    static AxisEnum current_axis;

  public:
    static uint16_t axis_settings_title_icon;

    static float axis_steps_mm;
    static uint16_t max_acceleration_mm_per_s2;

    static float jerk;
    static feedRate_t max_feedrate;

    static bool has_tmc_settings;
    static uint16_t tmc_current;
    static bool stealthchop;
    static uint32_t hybrid_threshold;

  public:
    static void HandleNavigation(DGUS_VP_Variable &var, void *val_ptr);
    static void HandleBackNavigation(DGUS_VP_Variable &var, void *val_ptr);
    static void HandleTMCNavigation(DGUS_VP_Variable &var, void *val_ptr);
};
