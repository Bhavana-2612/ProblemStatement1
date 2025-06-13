#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// Define the data structure
typedef struct {
    uint8_t dataID;
    int32_t DataValue;
} Data_t;

// Global variables assumed to be updated elsewhere
uint8_t G_DataID;
int32_t G_DataValue;

// Task handles
TaskHandle_t TaskHandle_1;
TaskHandle_t TaskHandle_2;

// Queue handle
QueueHandle_t Queue1;

// Task 1: Sender Task - sends data to queue every 500ms
void ExampleTask1(void *pV) {
    Data_t dataToSend;
    TickType_t lastWakeTime = xTaskGetTickCount();

    while (1) {
        dataToSend.dataID = G_DataID;
        dataToSend.DataValue = G_DataValue;

        xQueueSend(Queue1, &dataToSend, portMAX_DELAY);
        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(500));  // Wait exactly 500ms
    }
}

// Task 2: Receiver Task - processes received data and acts on logic
void ExampleTask2(void *pV) {
    Data_t receivedData;
    UBaseType_t originalPriority = uxTaskPriorityGet(NULL);
    bool priorityIncreased = false;

    while (1) {
        if (xQueueReceive(Queue1, &receivedData, portMAX_DELAY) == pdPASS) {
            printf("Received: ID=%d, Value=%ld\n", receivedData.dataID, receivedData.DataValue);

            if (receivedData.dataID == 0) {
                vTaskDelete(NULL);  // Delete self
            } else if (receivedData.dataID == 1) {
                if (receivedData.DataValue == 0 && !priorityIncreased) {
                    vTaskPrioritySet(NULL, originalPriority + 2);
                    priorityIncreased = true;
                } else if (receivedData.DataValue == 1 && priorityIncreased) {
                    vTaskPrioritySet(NULL, originalPriority);
                    priorityIncreased = false;
                } else if (receivedData.DataValue == 2) {
                    vTaskDelete(NULL);  // Delete self
                }
            }
        }
    }
}

// Main function - create queue, tasks, and start scheduler
int main(void) {
    // Create the queue
    Queue1 = xQueueCreate(5, sizeof(Data_t));
    if (Queue1 == NULL) {
        printf("Queue creation failed.\n");
        while (1);  // Stop if queue creation fails
    }

    // Create tasks
    xTaskCreate(ExampleTask1, "Task1", 1000, NULL, 2, &TaskHandle_1);
    xTaskCreate(ExampleTask2, "Task2", 1000, NULL, 2, &TaskHandle_2);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // If scheduler fails to start
    while (1);
}
