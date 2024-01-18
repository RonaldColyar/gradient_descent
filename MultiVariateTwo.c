// Author: Ronald Colyar 
// Date: 1/17/2024
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static float LEARNING_RATE = 0.1;
static int NUMBER_OF_STEPS = 20;

// We define a struct here that will act as the tuple for our optimal points
struct xy {
    float optimal_x;
    float optimal_y;
};

// First STEP:First we need to define our multivariate function and its partial derivatives.
// if you don't understand derivatives I recommend checking out 
// this amazing book https://rodrigopacios.github.io/mrpacios/download/Thomas_Calculus.pdf
float f(float x, float y){
    return 2*pow(x,2) + 2*pow(y,2);
}

float df_dx(float x,float y){
    return 4*x;
}

float df_dy(float y, float x){
    return 4*y;
}
struct xy gradient_descent(){
    // we will define our starting points
    struct xy data;
    float starting_x = 22.0;
    float starting_y = 22.0;

    float x = starting_x;
    float y = starting_y;
    int i;
    for(i = 0; i < NUMBER_OF_STEPS; i++){
        float gradient_x = df_dx(x, y);
        float gradient_y = df_dy(y, x);
        y = y - LEARNING_RATE * gradient_y;
        x = x - LEARNING_RATE * gradient_x;
    }
    data.optimal_x = x;
    data.optimal_y = y;
    return data;
}
 
int main(){
    struct xy data = gradient_descent();
    printf("%9.6f", data.optimal_x);
    printf("%9.6f", data.optimal_y);
    return 0;
} 