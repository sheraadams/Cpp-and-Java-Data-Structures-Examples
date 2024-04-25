## Data Structures & Algorithms Cpp

Data Structures &amp; Algorithms practice in C++ for vector, hash table, binary search tree, and linked list. The algorithms solve reading bids from a text file and efficiently storing, soring, inserting, and deleting from the chosen structure when applicable. To compare the data structures, I have written out the menu functionality in pseudocode and given a runtime analysis for the loadBids() function. 

### Menu Pseudocode

![image](https://github.com/sheraadams/Cpp-Data-Structures-Examples/assets/110789514/9cd947bf-5512-43dc-bc4a-38eca0c0b9da)

<img src="https://github.com/sheraadams/Cpp-Data-Structures-Examples/assets/110789514/670827d2-c975-40d6-bfb3-d49380c48c45" alt="Shera Adams Project 2 Runtime Analysis 2" style="width:70%; height:70%;">

<img src="https://github.com/sheraadams/Cpp-Data-Structures-Examples/assets/110789514/44cf28f0-b05f-4c02-b566-5bbb4f02626e" alt="Shera Adams Project 2 Runtime Analysis 3" style="width:70%; height:70%;">

<img src="https://github.com/sheraadams/Cpp-Data-Structures-Examples/assets/110789514/16c95f64-6e68-471a-8628-8fd62193ec7d" alt="Shera Adams Project 2 Runtime Analysis 1" style="width:70%; height:70%;">


### Runtime Analysis

For the loadBids function, the Hash Table, Vector, and Binary Search Tree data types all yield similar worst-case scenario runtime results, but there are other benefits and drawbacks to using each of these data types. The difference between each of these data structures lies primarily the Insert() function cost. For the vector data structure, the cost of insertion is 0(1), for the hash table data structure it is 0(N), and for the binary search tree structure, it is 0(log(N)) (Big-O Algorithm Complexity Cheat Sheet (Know Thy Complexities!) @Ericdrowell, n.d.). At first glance, this would tell us that the hash table (O(1)) should perform the best, binary search tree O(log(N)) should perform the second best, and the vector data structure (O(N)) would perform the worse, but other factors should also be considered.

I considered using the vector data structure at first as this structure offers advantages in terms of pure runtime and space complexity, but there are drawbacks to using a vector data type. Vectors are expensive in terms of memory allocation, and they require a large amount of storage to be allocated. If the vector is to be sorted, the vector would likely need to be sorted after each insertion or deletion. These requirements lead to the runtime cost of 0(N) which is the worst of the three data structures compared. Knowing the space complexity Over many courses, this sorting after each insertion or deletion would prove to be unnecessarily expensive in terms of runtime when compared to other structures. 

A hash table offers advantages when searches are used, and insertions and deletions are to be expected. Hash table search speed is very good with small data sets, but they do not perform as well as the data size grows. Should the data set grow, the possibility of data degradation could become an unavoidable issue.  According to the IONOS team, Hash tables “can degrade if they go through a large number of collisions” (2023). As growth and modification to the course list could be a possibility in the future for this application, I chose to program the application with a binary search tree data structure rather than a hash table structure.

A binary search tree is extremely efficient and yields faster search results than linear search method operations. It is for this reason that binary search trees are a strong choice for many applications that prioritize fast search results and efficiency. The binary search tree data type requires storage for the tree itself, which is a potential drawback to this structure that might be a consideration if it is known that the data is expected to be small and is not expected to grow. In the end, I chose a binary search tree as this structure generally would likely be a more appropriate data structure for this type of program in which growth and modification could be a reasonable expectation.  

#### References

Big-O Algorithm Complexity Cheat Sheet (Know Thy Complexities!) @ericdrowell. (n.d.). 
https://www.bigocheatsheet.com/

IONOS editorial team. (2023). Hash table | Fast database access to hash values. IONOS Digital Guide. 
https://www.ionos.com/digitalguide/server/security/hash-
table/#:~:text=The%20disadvantages%20of%20hash%20tables,next%20or%20previous%20data
%20set.

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

Overall, Java’s ArrayList is good for fast random access to elements by index, it has linear average run-time space complexity, and it preserves the order of elements. In terms of access, when sorting and insertion are not a primary need, the ArrayList structure performs very well. My enhancement increased the code maintainability and resource efficiency of the application by implementing an appropriate data structure. In the end, I solved the problem using algorithmic principles and software engineering best practices using good communication practices, algorithm analysis, and the Java language.

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
