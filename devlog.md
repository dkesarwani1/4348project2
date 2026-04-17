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