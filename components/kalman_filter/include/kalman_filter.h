#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#include <esp_log.h>

void kalman_filter(float z);
float generate_radar_measurement();
float generate_sound_measurement();

#endif // KALMAN_FILTER_H
