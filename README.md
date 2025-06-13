# ProblemStatement1 - FreeRTOS Tasks and Queue

## Overview:
This program demonstrates the use of FreeRTOS tasks and queues. It creates:
- A sender task that sends a structure every 500ms.
- A receiver task that handles the data based on values of `dataID` and `DataValue`.

## Logic Summary:

### Task1 (ExampleTask1):
- Runs every 500ms using `vTaskDelayUntil`.
- Sends data (`G_DataID`, `G_DataValue`) to `Queue1`.

### Task2 (ExampleTask2):
- Waits for data from `Queue1`.
- Applies logic:
  - `dataID == 0` → Delete task.
  - `dataID == 1`:
    - `DataValue == 0` → Increase task priority by 2.
    - `DataValue == 1` → Restore original priority.
    - `DataValue == 2` → Delete task.
- Prints the received values.

## Tools Used:
- FreeRTOS
- C Language

## Note:
Global variables `G_DataID` and `G_DataValue` are assumed to be updated by some other part of the system.
