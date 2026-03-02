#include <stdio.h>

float celsius_to_farenheit(float temp){ 
    return ((9.0/5.0)*temp + 32);
}


float celsius_to_kelvin(float temp){ 
    return (temp + 273.15);
}

float fahrenheit_to_celsius(float temp){
    return ((5.0/9.0)*(temp-32));
}

float kelvin_to_celsius(float temp){
    return (temp - 273.15);
}

float farenheit_to_kelvin (float temp){
    return (celsius_to_kelvin(fahrenheit_to_celsius(temp)));
}

float kelvin_to_farenheit (float temp){
    return (celsius_to_farenheit(kelvin_to_celsius(temp)));
}


int main()
{
    char convertToScale;
    char userScale;
    float userTemp;
    float convertedTemp;
    float tempCelsius; 
    printf("Enter temperature: ");
    scanf("%f", &userTemp);
    printf("Choose temperature scale (enter just one character): Kelvin (K), Fahrenheit (F), Celsius (C): ");
    scanf(" %c", &userScale); //space prevents scanf from reading newline character
    printf("Choose temperature scale to convert to (enter just one character): Kelvin (K), Fahrenheit (F), Celsius (C): ");
    scanf(" %c", &convertToScale);

    
    while (convertToScale == userScale){ //checks for the same scale being entered
        printf("Invalid Convsersion Choice, please choose a new temperature scale to convert to");
        printf("Choose temperature scale (enter just one character): Kelvin (K), Fahrenheit (F), Celsius (C): ");
        scanf(" %c", &convertToScale);
    }
    
    while (userScale == 75 && userTemp < 0){  //if input temp is kelvin chekcs for validity
        printf("Kelvin cannot go below 0, please re-enter your temperature: ");
        scanf("%f", &userTemp);
    }
    
    while (!(userScale == 70|| userScale == 67|| userScale == 75)){ //checks userScale is a valid type
        printf("Invalid input temperature scale \n");
        printf("Choose temperature scale (enter just one character): Kelvin (K), Fahrenheit (F), Celsius (C): ");
        scanf(" %c", &userScale);
    }
    
    
    while (!(convertToScale == 70|| convertToScale == 67|| convertToScale == 75)){ //checks convertToScale is a valid type
        printf("Invalid input temperature scale");
        printf("Choose temperature scale (enter just one character): Kelvin (K), Fahrenheit (F), Celsiues (C): ");
        scanf(" %c", &convertToScale);
        
        
    
    }
    
    switch(convertToScale){
        case 67:
            if (userScale == 70){
    	        convertedTemp = fahrenheit_to_celsius(userTemp);
                printf("worked %f", convertedTemp);
            }           
            else {
                convertedTemp = kelvin_to_celsius(userTemp);
                printf("worked %f", convertedTemp);
            }
            break;
        case 70:
            if (userScale == 67){
                convertedTemp = celsius_to_farenheit(userTemp);
            }
            else{
                convertedTemp = kelvin_to_farenheit(userTemp);
            }
            break;
        case 75:
            if (userScale == 67){
                convertedTemp = celsius_to_kelvin(userTemp);
            }
            else{
                convertedTemp = farenheit_to_kelvin(userTemp);
            }
            break;
            
            
        }
        
    
    printf("Converted temperature: %f\n", convertedTemp);
    
    if (userScale == 70){
        tempCelsius = fahrenheit_to_celsius(userTemp);
    }
        
    if (userScale == 75){
        tempCelsius = kelvin_to_celsius(userTemp);
    }
    
    if (tempCelsius < 0.0) {
        printf("Freezing: Stay indoors\n");
        }
    else if (tempCelsius >= 0.0 && tempCelsius <= 10.0) {
        printf("Cold: Make sure to wear a coat\n");
    }
    else if (tempCelsius > 10.0 && tempCelsius <= 25.0) {
        printf("Comfortable: Wear anything you'd like\n");
    }
    else if (tempCelsius > 25.0 && tempCelsius <= 35.0) {
        printf("Hot: Make sure to wear something light and breathable\n");
    }
    else {  // Above 35 celsius
        printf("Extreme Heat:Stay indoors and stay cool\n");
    }
        
    return 0;
}