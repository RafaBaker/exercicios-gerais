#include "calculadora.h"

/**
 * @brief Ponteiro para função que recebe dois float e realiza uma operação matemática.
 * 
 * @param float resultado da operacao matematica.
 */
typedef float (*CalculatoraCallback)(float, float);

float Calcular(float num1, float num2, CalculatoraCallback operacao);
