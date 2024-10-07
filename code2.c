// Name: Peter Barybin
// KUID: 3057437
// LAB Session: Thursday 4 p.m.
// LAB Assignment: 04
// Description: Program that takes in a temperature, scale, and conversion scale (Celsius, Fahrenheit, and Kelvin options) and outputs
// the converted temp, a categorization of that temp based on predefined ranges, and a weather advisory. User input is error checked.

#include <stdio.h>
#include <stdbool.h>

//C to F function
float celsius_to_fahrenheit (float celsius){
    return (9.0/5.0)*celsius + 32.0;
}

//F to C function
float fahrenheit_to_celsius (float fahrenheit){
    return (5.0/9.0)*(fahrenheit - 32.0);
}

//C to K function
float celsius_to_kelvin (float celsius){
    return celsius + 273.15;
}

//K to C function
float kelvin_to_celsius (float kelvin){
    return kelvin - 273.15;
}

//function that categorizes the temperature given in celsius into one of five levels and gives a weather advisory (prints results)
void categorize_temperature(float celsius){
    if (celsius < 0){
        printf("Temperature category: Freezing\nWeather advisory: Wear layers and a heavy coat.\n");
    }
    if (celsius >= 0 && celsius <= 10){
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket.\n");
    }
    if (celsius > 10 && celsius < 25){
        printf("Temperature category: Comfortable\nWeather advisory: You should feel comfortable.\n");
    }
    if (celsius >= 25 && celsius <= 35){
        printf("Temperature category: Hot\nWeather advisory: Wear short clothing if possible, hydrate.\n");
    }
    if (celsius > 35){
        printf("Temperature category: Extreme Heat\nWeather advisory: Stay indoors and in shade, hydrate.\n");
    }
}

int main(){
    //declare variables for input
    float temp;
    int scale;
    int conversion;
    bool correct_inputs = false;
    int check;
    //get temperature, current scale, and conversion scale from user and store within the declared variables
    while (correct_inputs == false){
        printf("Enter the temperature: ");
        check = scanf("%f", &temp);
        //error check to make sure a float was entered
        if (check == 0){
            printf("Invalid entry: temperature must be entered as a number only (decimals allowed). Please re-enter value.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &scale);
        //error check for C temp below absolute zero
        if (scale == 1 && temp < -273.15){
            printf("Invalid temperature: Celsius temperature cannot be less than -273.15ºC (absolute zero). Please re-enter values.\n");
            continue;
        }
        //error check for high C temp using highest temp ever recorded on Earth + 5ºC
        if (scale == 1 && temp > 61.7){
            printf("Invalid temperature: Celsius temperature too high for Earth. Please re-enter values.\n");
            continue;
        }
        //error check for F temp below absolute zero
        if (scale == 2 && temp < -459.67){
            printf("Invalid temperature: Fahrenheit temperature cannot be less than -459.67ºF (absolute zero). Please re-enter values.\n");
            continue;
        }
        //error check for high F temp using highest temp ever recorded on Earth + 5ºC converted to F
        if (scale == 2 && temp > 143.06){
            printf("Invalid temperature: Fahrenheit temperature too high for Earth. Please re-enter values.\n");
            continue;
        }
        //error check for negative K temp
        if (scale == 3 && temp < 0){
            printf("Invalid temperature: Kelvin temperature cannot be negative. Please re-enter values.\n");
            continue;
        }
        //error check for high K temp using highest temp ever recorded on Earth + 5ºC converted to K
        if (scale == 3 && temp > 334.85){
            printf("Invalid temperature: Kelvin temperature too high for Earth. Please re-enter values.\n");
            continue;
        }
        //error check for invalid option
        if (scale != 1 && scale != 2 && scale != 3){
            printf("Invalid entry: must enter either '1', '2', or '3'. Please re-enter values.\n");
            continue;
        }

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &conversion);
        //error check for invalid option
        if (conversion != 1 && conversion != 2 && conversion != 3){
            printf("Invalid entry: must enter either '1', '2', or '3'. Please re-enter values.\n");
            continue;
        }
        //error check for same scale and conversion scale
        if (scale == conversion){
            printf("Invalid conversion: converting to same scale. Please re-enter values.\n");
            continue;
        }
        //all inputs valid
        correct_inputs = true;
    }

    //all errors handled
    //calculate and print converted temp, then print categorization and weather advisory
    //given celsius
    if (scale == 1){
        //convert to F
        if (conversion == 2){
            printf("\nConverted temperature: %.2fºF\n", celsius_to_fahrenheit(temp));
        }
        //convert to K
        else{
            printf("\nConverted temperature: %.2fK\n", celsius_to_kelvin(temp));
        }
        categorize_temperature(temp);
    }
    //given fahrenheit
    else if (scale == 2){
        //convert to C
        if (conversion == 1){
            printf("\nConverted temperature: %.2fºC\n", fahrenheit_to_celsius(temp));
        }
        //convert to K
        else{
            printf("\nConverted temperature: %.2fK\n", celsius_to_kelvin(fahrenheit_to_celsius(temp)));
        }
        categorize_temperature(fahrenheit_to_celsius(temp));
    }
    //given kelvin
    else{
        //convert to C
        if (conversion == 1){
            printf("\nConverted temperature: %.2fºC\n", kelvin_to_celsius(temp));
        }
        //convert to F
        else{
            printf("\nConverted temperature: %.2fºF\n", celsius_to_fahrenheit(kelvin_to_celsius(temp)));
        }
        categorize_temperature(kelvin_to_celsius(temp));
    }
}