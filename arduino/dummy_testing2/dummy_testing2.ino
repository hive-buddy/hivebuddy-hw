// #include <cJSON.h>
// #include <cJSON_Utils.h>

// #include "cJSON.h"


// char *string = NULL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

//NOTE: Returns a heap allocated string, you are required to free it after use.
// char *test(void)
// {
//     const unsigned int resolution_numbers[3][2] = {
//         {1280, 720},
//         {1920, 1080},
//         {3840, 2160}
//     };
//     // cJSON *resolutions = NULL;
//     size_t index = 0;

//     cJSON *monitor = cJSON_CreateObject();

//     if (cJSON_AddStringToObject(monitor, "name", "Awesome 4K") == NULL)
//     {
//         goto end;
//     }

    // resolutions = cJSON_AddArrayToObject(monitor, "resolutions");
    // if (resolutions == NULL)
    // {
    //     goto end;
    // }

    // for (index = 0; index < (sizeof(resolution_numbers) / (2 * sizeof(int))); ++index)
    // {
    //     cJSON *resolution = cJSON_CreateObject();

    //     if (cJSON_AddNumberToObject(resolution, "width", resolution_numbers[index][0]) == NULL)
    //     {
    //         goto end;
    //     }

    //     if (cJSON_AddNumberToObject(resolution, "height", resolution_numbers[index][1]) == NULL)
    //     {
    //         goto end;
    //     }

    //     // cJSON_AddItemToArray(resolutions, resolution);
    // }

//     string = cJSON_PrintUnformatted(monitor);
//     if (string == NULL)
//     {
//         fprintf(stderr, "Failed to print monitor.\n");
//     }

// end:
//     cJSON_Delete(monitor);
//     return string;
// }

// void loop() {
//   // Serial.flush();

//   // put your main code here, to run repeatedly:
//   // char greeting[] = "Hello, World\n";
//   // printf(greeting);
//   // sleep(5);
//   // unsigned long currentTime = millis();
//   float tempC = 20.5;
//   float humi = 88.13;
//   int id = 1;
  
//   // Serial.print(currentTime);
//   // Serial.print(",");
//   Serial.print(id);
//   Serial.print(";");

//   // // Serial.print("Tempertaut: ")
//   Serial.print(tempC);
//   Serial.print(",");
//   Serial.print(humi);
//   Serial.print(",");
//   Serial.print(tempC);
//   // Serial.print(";");
//   // Serial.println();

//   // Serial.print(test());
//   // cJSON_free(string);
//   // Serial.print("{\"name\":\"Awesome5K\"}");
//   // Serial.print("{name | mkyong | lol}");
//   Serial.println();

//   delay(1000);
// }

void loop(){
  // SensorType Ids - order for printing after ";"
  // 1 - temperatureOut, 2 - temperatureIn, 3 - humidityIn, 4 - weight, 5 - mic

  // Dummy data
  int hive_id = 1;
  double temperatureOut = 20.500;
  double temperatureIn = 2309.0;
  double humidityIn = 88.131;
  double weight = 48.1;
  double mic = 13233213.37231308;

  // 1;20.50,2309.00,88.13,48.10,1323.97

  // Output General Info
  Serial.print(hive_id);
  Serial.print(";");

  // Output Sensor Values
  Serial.print(temperatureOut);
  Serial.print(",");
  Serial.print(temperatureIn);
  Serial.print(",");
  Serial.print(humidityIn);
  Serial.print(",");
  Serial.print(weight);
  Serial.print(",");
  Serial.print(mic);
  // Serial.print(",");


  Serial.println();
  delay(5000);
}
