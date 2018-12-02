# MAZEBOARD

## Welcome to DBMS Mazeboard Mania!!! By Group 1

##### Names: 
-    Joddian Allen -- 20121358, 
-    Bryanna Chang -- 20112213, 
-    Schana Beckford -- 20151316,
-    Gerard Francis -- 20142119, 
-    Mark Dennis -- 2012686, 
-    Garson Anglin -- 20142037,
-    Christopher Howe -- 20141522, 
-    Shanika Ferguson -- 20141916

 
##### About our game:

> Our Mazeboard mania program is a simple interactive game that test the player memory when played with the intention for the user to navigate from one room at a time to find the exit point. This program was created using the C++ object-oriented programing language to establish the necessary functions thatis needed to create the maze effect and its functions.  

##### Algorithm:

> The algorithm that  was used to find the shortness path is  Dijkstra’s. Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. Like Prim’s MST, we generate a SPT (shortest path tree) with given source as root. We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.

##### What Could Be Done Better:
- The run time of the game is inefficient as it takes too long to run (7 secs).
- We could have used a counter function that would be able to clear the room once a user  enters a new room. We used 5 for loop counters. 
- The code allows the user to select any room while it should have allow them to complete a room before entering another.
- Whenever you re-enter a room after playing the room should rest. However, as the game is it does not refresh, it is stored in memory. 
- The exit does not all you to enter a room whenever you exit. It should be able to allow you to enter another room once you exit.

This is the GitHub Link: https://github.com/DSAFM2/MAZEBOARD 
