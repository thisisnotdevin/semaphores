# Semaphores

Semaphores are a good practice for process synchronization and can be implemented using C++. Multiple processes are running at the same time in this project, all using the same data.
Semaphores are more sophisticated than mutex locks, and it can only be accessed via two indivisible atomic opeartions `wait()` and `signal()`

designing the waiting operation:


![image](https://user-images.githubusercontent.com/66978846/159145433-450627e3-21a7-4530-9c37-6e26faf94db5.png)



designing the signal operation:


![image](https://user-images.githubusercontent.com/66978846/159145447-bccc6ece-8ccb-480b-8f05-502ee8318b3d.png)



## Critical sections
It's easy to get confused when multiple processes are running at the same time and sharing the same resource, so no other processes should be allowed to start their critical sections while one process is executing its critical section.

![image](https://user-images.githubusercontent.com/66978846/159145200-4b7823eb-7e59-465d-ae56-ab08b7988bca.png)

## Mutex locks
Similar to semaphores, mutex lock stands for mutual exclusion, to protect the critical session it must first `acquire()` and the `release()` the lock.

**Here is an example code**

![image](https://user-images.githubusercontent.com/66978846/159145159-3eb160ed-1a65-498c-a9ea-d782f4f5f19a.png)
