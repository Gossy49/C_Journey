#include <stdio.h>


int main (){

    int sensor_reading [20]= {62, 78, 55, 91, 84, 67, 73, 96, 73, 88, 70, 81, 53, 99, 75, 64, 86, 60, 92, 69};
    float sumvalue  = 0;
    int length_array  = sizeof(sensor_reading)/ sizeof(sensor_reading[0]);

    for (int i =0; i < length_array; i++){
        printf("Temperature Sensor: %d\n", sensor_reading[i]);
    }

    for (int i = 0; i < length_array; i++){
        sumvalue = sumvalue + sensor_reading[i];
    }
    float average = sumvalue / length_array;
    printf("\nTemperature Average: %.2f\n", average);    

    return 0;

}