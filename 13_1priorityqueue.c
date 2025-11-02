//  Write an algorithm and a program to implement priority queue (also known as heap). Priority
//  queue has following properties:
//  a) Each item has a priority associated with it. 
//  b) Element which has heighest priority is dequeued before an element with low priority.
//  c) If two elements have the same priority, they are served according to their order in the queue.
//  d) It is always in the form of complete tree.
//  e) Element which has highest priority should be at root, element which has priority less than
//     root but more than other elements comes at level 2. Hence as the level increases, priority of
//     element decreases.
//     The program should implement following operations:
//  a) create() - create root node of priority heap
//  b) insert() - insert an element into the priority queue. Everytime when a node is inserted, tree
//               should be balanced according to its priority.
//  c) getHighestPriority() - finds the element which has highest priority
//  d) deleteHeighestPriority() - delete the element which has highest priority
