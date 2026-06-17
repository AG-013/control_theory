/**
 * @brief Computes PID controller output
 * 
 * @param setpoint Target value
 * @param measurement Current measured value
 * 
 * Preset params:
 * @param kp Proportional gain
 * @param ki Integral gain
 * @param kd Derivative gain
 * @return Control output
 */
#include <cmath>

double pid(double setpoint, double measurement, double kp, double ki, double kd) {
	static double integral = 0.0;
	static double previous_error = 0.0;

	double error = setpoint - measurement;
	integral += error;
	double derivative = error - previous_error;

	previous_error = error;

	return (kp * error) + (ki * integral) + (kd * derivative);
}

