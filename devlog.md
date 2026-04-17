## April 17th 9:35AM
Program Objective:
The goal of this program is to simulate a bank using multithreading. The bank has 3 teller threads and 50 customer threads. Customers randomly choose either a deposit or withdrawal, arrive after a small delay, wait for the bank to open, enter through a door that only allows two customers at a time, get in line, interact with a teller, and leave after the transaction is complete. Tellers repeatedly serve customers, request manager approval for withdrawals, use the safe to complete transactions, and continue until all 50 customers have been served and have left the bank. 

## April 17th 10:15 AM
Devlog Step 1 — Set up the Program structure
What I did

In the first step, I created the basic program structure for the simulation. I included the libraries needed for threads, mutexes, queues, semaphores, timing, and strings. I also defined constants for the number of tellers and customers.

At this point, the goal was not to fully implement all synchronization, but to establish the framework of the project:

3 tellers
50 customers
a customer thread function
a teller thread function
thread creation in main()

This step lays the groundwork for everything else. It makes sure the program can launch the correct number of threads and gives the project a clear starting point.

Why this step matters

This follows the project suggestion to start with the interaction structure first rather than immediately trying to solve all synchronization at once. Before handling manager access, safe access, line order, and customer-teller coordination, the program first needs the thread-based skeleton.

## April 17th 11:45 AM
Step 2 — Add shared resources, semaphores, and logging helpers

In this step, I added the shared resources and helper functions that the program will need. I introduced semaphores for:

the door, which allows only two customers at once
the manager, which allows only one teller at a time
the safe, which allows only two tellers at a time
a customer-ready semaphore to tell tellers when someone is waiting

I also added:

shared mutexes for protecting output, the customer queue, and the served counter
a queue to store waiting customers
arrays of semaphores so each customer and teller can coordinate directly
helper functions logLine() and logResource() for producing consistent output
a passThroughDoor() helper to model the doorway behavior

This step is important because the project depends a lot on synchronization. These resources are the main tools that make the simulation safe and correct.

This is important because the project requires shared resources such as the manager and safe to be protected and also says other semaphores will be needed so customers and tellers wait for each other at the correct times. This step is where the synchronization tools have to be added.