#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

using namespace std;

static TaskHandle_t slaveTaskHandle;

static void slaveTask(void *pvParameters) {

    while(1) {

        vTaskDelay(pdMS_TO_TICKS(10));
        
    }
}

extern "C" void app_main() {

    xTaskCreate(slaveTask, "slave", 1024*6, NULL, configMAX_PRIORITIES-1, &slaveTaskHandle);

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(20));
    }
    
}
