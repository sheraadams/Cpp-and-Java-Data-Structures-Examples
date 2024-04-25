## Data Structures & Algorithms Cpp

Data Structures &amp; Algorithms practice in C++ for vector, hash table, binary search tree, and linked list. The algorithms solve reading bids from a text file and efficiently storing, soring, inserting, and deleting from the chosen structure when applicable. 

### XCode Usage

1. Open a terminal in the project directory and run the code: 

```bash
mkdir build
cd build
cmake -G Xcode ..
```

2. Set the working directory in Xcode using Product > Scheme > Edit Scheme > Run Debug > Options > Working Directory > (Check Set Custom) > Project directory/build.

3. Build and run the project.

## Another Data Structure Example 

I improved a slideshow wireframe which was an early iteration of a vacation booking site. I improved the resource usage and maintainability of the codebase by using an efficient data structure to replace the if-else conditional branching currently controlling the view of the slideshow. Before my contributions, the slideshow operated on a conditional statement that defined the contents of 10 JLabels that were created for each user based on the value of the index variable.  I improved the application by changing this hard-to-maintain conditional statement to an appropriate data structure and ensured that with each slide, only two JLabels were created and subsequently clearing and adding the contents to the panes according to the value the index. My work improved the adaptability, reusability, and scalability of this application by conforming to software engineering best practices. 

Though the wireframe slideshow application data started out small and our improved data structure may not noticeably increase the run-time efficiency of the application (the current run-time cost to create the GUI contents for one user is 35 and it is 11n with the ArrayList – see below for the cost analysis), as the application scales and the logic is adopted by the larger application, several issues would arise. If the number of users accessing their top five would scale largely, the dependence on a solid data structure would become increasingly impactful in terms of memory, performance, and code maintenance. With the ArrayList, the average runtime space complexity is still linear and it is comparable to the conditional branching in place (before enhancement, the run time space complexity was 0(1)) and after, it is expected to be O(1) to O(N) with the added benefit of better resource management and better maintainability). Further, as we are most concerned about access, the ArrayList runtime space complexity for access would be O(1), which is the same. 

Overall, Java’s ArrayList is good for fast random access to elements by index, it has linear average run-time space complexity, and it preserves the order of elements. In terms of access, when sorting and insertion are not a primary need, the ArrayList structure performs very well. My enhancement increased the code maintainability and resource efficiency of the application by implementing an appropriate data structure. In the end, I solved the problem using algorithmic principles and computer science best practices using documentation, algorithm analysis, Java programming, and HTML programming.**

<div align="center">
  <p><strong>Algorithm Analysis</strong></p>
  <img src="https://sheraadams.github.io/assets/img/analysis.jpg" width="800" alt="Algorithm Analysis">
</div>

### Challenges and Lessons Learned

In my work with data structures, I have learned to be holistic in my approach when considering an appropriate data structure for applications. It is always important to consider the context, the intended use, resources available, and the expected scale of the application first when considering a data structure as run time efficiency alone is not usually enough information. 

Specifically for the slideshow wireframe, I initially considered the ArrayList, the Binary Search Tree, and the Linked List for this application as each of these structures offer the benefits of order preservation and fast access. Ultimately, I decided that the Linked List and Binary Search Tree bring additional overhead storage requirements that may not be reasonable for daily insertions and sorting with a primary use of access alone. Quantifying algorithmic differences (especially when they are relatively small) can be challenging at times, however, I found an algorithmic analysis exercise as shown below to be a helpful tool for comparing the space complexity before and after enhancement. 

In the end, I learned that it is always important to consider the needs of the end-user and the context of the application carefully first before choosing an appropriate structure. Additionally, it is always crucial to weigh the trade-offs associated with a data structure. Doing so can prevent unnecessary revision, cost, and maintenance.

<div align="center">
  <p><strong>Java Slide Show</strong></p>
  <img src="https://sheraadams.github.io/assets/img/slideshow.jpeg" width="800" alt="Java Slide Show">
</div>

### Data Structures and Algorithms Artifacts
The artifact for this project includes a zipped folder with the .jar executable and the Eclipse Java project.

  - You can find the [original artifact](https://github.com/sheraadams/sheraadams.github.io/blob/main/artifacts/DSA_Example.zip) here.  
  - You can find the [enhanced artifact](https://github.com/sheraadams/sheraadams.github.io/blob/main/artifacts/DSA_Enhanced.zip) here.  
