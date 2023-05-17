#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// training data
float train[][2] =
{
  {0, 0},
  {1, 2},
  {2, 4},
  {3, 6},
  {4, 8}
};
// define the amount of elements in the data
#define train_count (sizeof(train)/sizeof(train[0]))

// generate a psuedo-random float number
float rand_float(void)
{
  // gives random number from 0-1
  return (float) rand()/ (float) RAND_MAX;
}

// compute cost of the model TODO goal is to minimize cost to 0
float cost(float w)
{
  // result is the measure of accuracy of model
  float result = 0.0f;
  for (size_t i = 0; i < train_count; ++i) {
    float x = train[i][0];
    float y = x*w;
    float d = y - train[i][1];
    result += d*d;
    printf("actual: %f, expected: %f\n", y, train[i][1]);
  }
  // take average of the summation of squared differences
  result /= train_count;
	return result;
}

int main()
{
  // randomize number with current time
  // srand(time(0));
  srand(69);
  
  float w = 10.0f*rand_float();
  printf("%f\n", w);
  
  // show results
  printf("%f\n", cost(w));
  
  return 0;
}
