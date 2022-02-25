/* ------------------------------------------------------------------------*/ 
/* Header files */
/* ------------------------------------------------------------------------*/ 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Signal to be processing 
#include "sig.h"
 
// Constant 
#define FFT_SIZE 512


float frequency_analyis(){
    // Half DFT is sufficient 
    int half_dft = SIZE/2;
    // Instantiate the 3 buffers 
    float* BASE_SINE [SIZE];
    float* BASE_COSINE [SIZE];
    float* out_fft [SIZE];
    // Compute half DFT
    for (int i =0 ; i < half_dft ; i++){
        // Instantiate BASE_ with nested for loop
        for (int n = 0; n < SIZE ; n ++){
            f_calc= 2*PI*i*n/FFT_SIZE
            BASE_COSINE[n] = cos(f_calc);
            BASE_SINE[n] = sin(f_calc);
        }
        // Create the current DFT 
        float r_dft = 0;
        float i_dft = 0;
        for (int k = 0; k < SIZE; k++){
            // Accumulate 
            r_dft = r_dft + BASE_COSINE[k]*sig[k];
            r_dft = i_dft + BASE_SINE[k]*sig[k];
        }
        // Calculate modulus 
        out_fft[i] = r_dft*r_dft+i_dft*i_dft;
    }
    // Find the max
    int maxPos = 0;
    float maxVal = 0; 
    for (int i =0 ; i < half_dft; i++){
       // Use maxPos and maxVal  
       if (maxVal<out_fft[i]){
          maxVal = out_fft[i];
          maxPos = i;
       }
    }
    printf("Maximal value is located at bin %d \n",maxPos);
    // Deduce the frequency from bin position
    float f = Fc*i/FFT_SIZE
    printf("Associated frequency is  %f Hz\n",f);
    return f;
}


float amplitude_extraction(float f){
    // Define step size 
    float mu = 0.005;
    // Define buffers 
    float* u = ... 
    float* w = ... 
    float* e = ... 
    // Instantiate w & u 
    for (int n = 0; n < SIZE; n++){
        w[n] = ...
        u[n] = ...
    }
    // LMS Algorithm 
    for (int n = 0; n < SIZE; n++){
        ...
    }
    // Compute final estimate 
    int mean_size = 500;
    float amp = 0;
    for (int n = 0; n < mean_size; n++){
        // Mean on last samples 
        ...
    }
    printf("Estimated amplitude is %f \n",amp);
    return amp;
}


int main(){
    printf("--- Frequency analysis and amplitude extraction\n");
    float f = frequency_analyis();
    float a = amplitude_extraction(f);
    return 0;

}
