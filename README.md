[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/d2ClRzof)
# lab5-rtos-skeleton

    * Name: 
    * Github username: 
    * Github Repository URL: 
    * Description of hardware: (embedded hardware, laptop, etc)

## Part A: Introduction to FreeRTOS

### 1. FreeRTOS Documentation Questions

1. Why would an RTOS be required or useful for a system? How is it different from other operating systems?

2. Where is the CPU clock and Tick rate configured? Does a 16MHz tick rate sound reasonable? Why or why not?

3. Briefly explain the purpose of each of the three main files (tasks.c, queue.c, and list.c).

4. What are the different task states possible? What transitions are possible? (You may attach a diagram).

5. Which has a higher priority, a task with priority number “5” or a task with priority number “1”?

6. What is the required prototype for all “task” functions and what are the required parameters needed to create a task?

7. What is the idle task? Is it necessary?

8. TaskA is ready and has a priority of 0. It can use as much CPU as is available and it is the only task available. What percent of the time would it run?

9. What does vTaskDelay() do and how is it different from vTaskSuspend()? From vTaskDelayUntil()?

10. What are software timers? Give an example where a software timer would be useful.

11. What are some ways that can help prevent stack overflow in FreeRTOS?

12. How does the scheduler “block” tasks and cause them to be removed from the ready list until an event has occurred?

13. In the creation of the tasks the usStackDepth is described to be “the number of words (not bytes!) to allocate for use as the task’s stack”. In their example, a 16 bits wide stack with an assigned depth of 100 means 200 bytes will be allocated for use. How did they get 200?

### 2. An Example

14. Why would there be a limit on the number of tasks that can be scheduled on a microcontroller?

15. What is the difference between the stack pointer and the program counter?

16. In your own words, what is the portSAVE_CONTEXT() function and why is it necessary? What would happen if this function wasn’t called?

17. In step 5, why does the stack pointer point to the top of TaskB Stack instead of PC(B) or a lower memory address (e.g. 0x12, 0x34)?

18. What does portRESTORE_CONTEXT() do? Give a more verbose answer than “restore context”.

19. After step 7, what if a third task, TaskC, were to interrupt TaskB? TaskC has a higher priority than TaskB. What would the next step look like? You can either write your answer out in words as an explanation and/or draw a diagram.

## Part B: Implementation

20. What is the tick rate here? I.e. About every how many seconds does the scheduler throw an interrupt and consider all tasks “ready” to run? FreeRTOSBoardDefs.h may be helpful here.

21. Why do you think the watchdog timer is used as the scheduler?

### 1. Task Set

22. Is the task set above RM schedulable? Show your work. Draw out the scheduling diagram. If it is not schedulable, make an adjustment to Task B’s CPU time to make the set RM schedulable.

### 2. RMS - Preemptive

23. Measure the duty cycle of each task. Is it what you expected? If not, why is there a discrepancy? (Hint: It could have something to do with the delayuntil function. There is more than one possible answer here.)

24. How does this affect the schedule? Do any tasks miss their deadlines?

### 3. RMS - Blocking

25. How does this affect the schedule? Do any tasks miss their deadlines?

## Description of AVR ATmega port of freeRTOS

A port of freeRTOS configured to use the Watchdog Timer on AVR ATmega devices and will operate with almost any classic Arduino device from Arduino, SeeedStudio, Sparkfun, Freetronics or Pololu.

<https://github.com/feilipu/miniAVRfreeRTOS>

## Github Repo Submission Resources

* [ESE5160 Example Repo Submission](https://github.com/ese5160/example-repository-submission)
* [Markdown Guide: Basic Syntax](https://www.markdownguide.org/basic-syntax/)
* [Adobe free video to gif converter](https://www.adobe.com/express/feature/video/convert/video-to-gif)
* [Curated list of example READMEs](https://github.com/matiassingers/awesome-readme)
* [VS Code](https://code.visualstudio.com/) is heavily recommended to develop code and handle Git commits
  * Code formatting and extension recommendation files come with this repository.
  * Ctrl+Shift+V will render the README.md (maybe not the images though)
