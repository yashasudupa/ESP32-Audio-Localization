#include "kalman_filter.h"
#include <math.h>
#include <stdlib.h>

static const char *TAG = "KalmanFilter";

float x = 0, v = 0; // Position and velocity
float P[2][2] = {{1, 0}, {0, 1}}; // Covariance matrix
float Q[2][2] = {{0.1, 0}, {0, 0.1}}; // Process noise
float R = 0.5; // Measurement noise

void kalman_filter(float z) {
    float x_pred = x + v;  
    float v_pred = v;  
    float P_pred[2][2] = {
        {P[0][0] + Q[0][0], P[0][1] + Q[0][1]},
        {P[1][0] + Q[1][0], P[1][1] + Q[1][1]}
    };
    float y = z - x_pred; 
    float S = P_pred[0][0] + R;
    float K[2] = {P_pred[0][0] / S, P_pred[1][0] / S};
    x = x_pred + K[0] * y;
    v = v_pred + K[1] * y;
    P[0][0] -= K[0] * P_pred[0][0];
    P[1][0] -= K[1] * P_pred[0][0];
    ESP_LOGI(TAG, "Estimated Position: %.2f", x);
}

float generate_radar_measurement() {
    return 10.0 + ((rand() % 100) / 10.0) - 5.0; 
}

float generate_sound_measurement() {
    return 10.0 + ((rand() % 100) / 10.0) - 5.0; 
}
