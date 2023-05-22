Quicksort is a divide-and-conquer algorithm that uses recursion to sort an array. The base case for this recursion is when the array is of max length 1 - at which point it is already sorted. This base case is reached n times. Thus, it is common to fall back on a 'lesser' sorting algorithm such as insertion sort once the sub-array has a small length, typically between 5 and 15 elements, reducing the number of function calls required to sort the entire array. The optimal threshold at which quicksort switches to insertion sort can differ between systems since the two algorithms use instructions and memory access differently.

Below are the times to sort vectors of different lengths with a basic quicksort algorithm using a Lomuto partition and varying thresholds before switching to insertion sort. 

Testing methodology: Each threshold was timed sorting vectors of random integers, already-sorted integers, and all-zero integers. Each test was run in at least 10 sets (pressing "run") of 10 (to avoid Ed's time and output limits and since there were often significant discrepancies between sets), with the average of each set recorded. The best average that appeared multiple times was taken as the final measurement. All tests were run on the Ed VM.

(all times are in microseconds, - = not tested)

<table>
  <thead>
    <tr>
      <th colspan="6">Random</th>
    </tr>
    <tr>
      <th rowspan="2">Threshold</th>
      <th colspan="4">Vector Length</th>
    </tr>
    <tr>
      <th>100</th>
      <th>1,000</th>
      <th>10,000</th>
      <th>100,000</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>4</td>
      <td>0</td>
      <td>10</td>
      <td>316</td>
      <td>4,203</td>
    </tr>
    <tr>
      <td>8</td>
      <td>0</td>
      <td>10</td>
      <td>300</td>
      <td>4,166</td>
    </tr>
    <tr>
      <td>12</td>
      <td>0</td>
      <td>9</td>
      <td>289</td>
      <td>4,082</td>
    </tr>
    <tr>
      <td>16</td>
      <td>0</td>
      <td>9</td>
      <td>280</td>
      <td>3,925</td>
    </tr>
    <tr>
      <td>20</td>
      <td>0</td>
      <td>8</td>
      <td>280</td>
      <td>3,865</td>
    </tr>
    <tr>
      <td>48</td>
      <td>0</td>
      <td>43</td>
      <td>453</td>
      <td>5,338</td>
    </tr>
    <tr>
      <td>80</td>
      <td>0</td>
      <td>33</td>
      <td>468</td>
      <td>5,364</td>
    </tr>
    <tr>
      <td>128</td>
      <td>1</td>
      <td>51</td>
      <td>470</td>
      <td>5,629</td>
    </tr>
    <tr>
      <td>65,536</td>
      <td>-</td>
      <td>-</td>
      <td>-</td>
      <td>228,868</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th colspan="6">Sorted</th>
    </tr>
    <tr>
      <th rowspan="2">Threshold</th>
      <th colspan="4">Vector Length</th>
    </tr>
    <tr>
      <th>100</th>
      <th>1,000</th>
      <th>10,000</th>
      <th>100,000</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>4</td>
      <td>3</td>
      <td>262</td>
      <td>21,607</td>
      <td>2,173,234</td>
    </tr>
    <tr>
      <td>8</td>
      <td>2</td>
      <td>238</td>
      <td>21,598</td>
      <td>2,154,876</td>
    </tr>
    <tr>
      <td>12</td>
      <td>2</td>
      <td>224</td>
      <td>21,580</td>
      <td>2,158,901</td>
    </tr>
    <tr>
      <td>16</td>
      <td>2</td>
      <td>221</td>
      <td>21,602</td>
      <td>2,198,193</td>
    </tr>
    <tr>
      <td>20</td>
      <td>2</td>
      <td>235</td>
      <td>21,705</td>
      <td>2,174,355</td>
    </tr>
    <tr>
      <td>48</td>
      <td>2</td>
      <td>225</td>
      <td>21,608</td>
      <td>2,152,333</td>
    </tr>
    <tr>
      <td>80</td>
      <td>0</td>
      <td>248</td>
      <td>21,609</td>
      <td>2,157,425</td>
    </tr>
    <tr>
      <td>128</td>
      <td>0</td>
      <td>219</td>
      <td>21,578</td>
      <td>2,157,312</td>
    </tr>
    <tr>
      <td>65,536</td>
      <td>-</td>
      <td>-</td>
      <td>-</td>
      <td>1,230,065</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th colspan="6">All-Zero</th>
    </tr>
    <tr>
      <th rowspan="2">Threshold</th>
      <th colspan="4">Vector Length</th>
    </tr>
    <tr>
      <th>100</th>
      <th>1,000</th>
      <th>10,000</th>
      <th>100,000</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>4</td>
      <td>3</td>
      <td>220</td>
      <td>21,650</td>
      <td>2,167,821</td>
    </tr>
    <tr>
      <td>8</td>
      <td>2</td>
      <td>232</td>
      <td>21,588</td>
      <td>2,200,638</td>
    </tr>
    <tr>
      <td>12</td>
      <td>2</td>
      <td>220</td>
      <td>21,583</td>
      <td>2,192,690</td>
    </tr>
    <tr>
      <td>16</td>
      <td>2</td>
      <td>220</td>
      <td>21,598</td>
      <td>2,173,055</td>
    </tr>
    <tr>
      <td>20</td>
      <td>2</td>
      <td>227</td>
      <td>21,696</td>
      <td>2,180,191</td>
    </tr>
    <tr>
      <td>48</td>
      <td>2</td>
      <td>227</td>
      <td>21,610</td>
      <td>2,154,380</td>
    </tr>
    <tr>
      <td>80</td>
      <td>0</td>
      <td>235</td>
      <td>21,600</td>
      <td>2,156,948</td>
    </tr>
    <tr>
      <td>128</td>
      <td>0</td>
      <td>223</td>
      <td>21,574</td>
      <td>2,154,038</td>
    </tr>
    <tr>
      <td>65,536</td>
      <td>-</td>
      <td>-</td>
      <td>-</td>
      <td>1,233,824</td>
    </tr>
  </tbody>
</table>

As is evident from the results above, the threshold with the best performance on this particular system is between 8 and 20 elements. Setting the threshold too low defeats the purpose of falling back on insertion sort for small arrays and provides little to no advantage to plain quicksort. Insertion sort has an average time complexity of O(n^2). In contrast, quicksort has an average time complexity of O(nlogn). Each threshold increase provides fewer mitigated function calls than the last while increasing the number of elements sorted with the less efficient algorithm, thus diminishing performance past ~20.

However, the worst case for a Lomuto partition is an array already sorted or all the same value, which causes the time complexity to degrade to O(n^2). In contrast, this scenario is the best case for insertion sort, with time complexity O(n). Thus, as the tables above show, a high threshold improves performance in these situations.

Below are the times to sort a vector of different contents and lengths with several variations on the basic quicksort algorithm. The variations are:
- lomuto: Lomuto partitioning
- insertion-base: above + insertion sort fallback with threshold 10
- median-of-3: above + median-of-3 pivot selection
- hoare: above + replace lomuto partitioning with Hoare partitioning
std::sort results are also shown for reference.

The same testing methodology as above was used.

<table>
  <thead>
    <tr>
      <th colspan="6">Random</th>
    </tr>
    <tr>
      <th rowspan="2">Algorithm</th>
      <th colspan="5">Vector Length</th>
    </tr>
    <tr>
      <th>100</th>
      <th>1,000</th>
      <th>10,000</th>
      <th>100,000</th>
      <th>1,000,000</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>lomuto</td>
      <td>0</td>
      <td>11</td>
      <td>315</td>
      <td>4,134</td>
      <td>47,816</td>
    </tr>
    <tr>
      <td>insertion-base</td>
      <td>0</td>
      <td>10</td>
      <td>290</td>
      <td>4,035</td>
      <td>47,882</td>
    </tr>
    <tr>
      <td>median-of-3</td>
      <td>0</td>
      <td>9</td>
      <td>293</td>
      <td>3,911</td>
      <td>46,036</td>
    </tr>
    <tr>
      <td>hoare</td>
      <td>0</td>
      <td>8</td>
      <td>289</td>
      <td>3,766</td>
      <td>44,339</td>
    </tr>
    <tr>
      <td>std::sort</td>
      <td>0</td>
      <td>9</td>
      <td>296</td>
      <td>3,697</td>
      <td>44,889</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th colspan="6">Sorted</th>
    </tr>
    <tr>
      <th rowspan="2">Algorithm</th>
      <th colspan="5">Vector Length</th>
    </tr>
    <tr>
      <th>100</th>
      <th>1,000</th>
      <th>10,000</th>
      <th>100,000</th>
      <th>1,000,000</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>lomuto</td>
      <td>4</td>
      <td>227</td>
      <td>21,571</td>
      <td>3,856,222</td>
      <td>&gt; 1 min</td>
    </tr>
    <tr>
      <td>insertion-base</td>
      <td>2</td>
      <td>230</td>
      <td>21,704</td>
      <td>2,165,800</td>
      <td>&gt; 1 min</td>
    </tr>
    <tr>
      <td>median-of-3</td>
      <td>0</td>
      <td>4</td>
      <td>52</td>
      <td>1,317</td>
      <td>8,256</td>
    </tr>
    <tr>
      <td>hoare</td>
      <td>0</td>
      <td>2</td>
      <td>30</td>
      <td>425</td>
      <td>4,561</td>
    </tr>
    <tr>
      <td>std::sort</td>
      <td>0</td>
      <td>5</td>
      <td>53</td>
      <td>630</td>
      <td>8,838</td>
    </tr>
  </tbody>
</table>

<table>
  <thead>
    <tr>
      <th colspan="6">All-Zero</th>
    </tr>
    <tr>
      <th rowspan="2">Algorithm</th>
      <th colspan="5">Vector Length</th>
    </tr>
    <tr>
      <th>100</th>
      <th>1,000</th>
      <th>10,000</th>
      <th>100,000</th>
      <th>1,000,000</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>lomuto</td>
      <td>3</td>
      <td>221</td>
      <td>31,265</td>
      <td>3,212,414</td>
      <td>&gt; 1 min</td>
    </tr>
    <tr>
      <td>insertion-base</td>
      <td>3</td>
      <td>225</td>
      <td>21,620</td>
      <td>2,159,942</td>
      <td>&gt; 1 min</td>
    </tr>
    <tr>
      <td>median-of-3</td>
      <td>3</td>
      <td>230</td>
      <td>31,853</td>
      <td>3,153,584</td>
      <td>&gt; 1 min</td>
    </tr>
    <tr>
      <td>hoare</td>
      <td>1</td>
      <td>121</td>
      <td>10,940</td>
      <td>1,098,403</td>
      <td>&gt; 1 min</td>
    </tr>
    <tr>
      <td>std::sort</td>
      <td>0</td>
      <td>3</td>
      <td>43</td>
      <td>553</td>
      <td>7,964</td>
    </tr>
  </tbody>
</table>

As stated above, the performance of basic quicksort with Lomuto partitioning degrades when the array is already sorted. While this can be mitigated by increasing the threshold to switch to insertion sort, this reduces performance for arrays of random values. The most basic Lomuto partition selects the first element in the array to be the pivot element when the optimal pivot would be the median of all values in the array. The median-of-3 algorithm selects the median of the first, middle, and last elements as the pivot, which in a sorted array will be the median element of the entire array. This avoids the worst-case O(n^2) when the pivot is the minimum/maximum of the array, bringing it closer to the average running time of O(nlogn). In an array of all one value, however, every value is the median; thus, time is wasted during each recursion calculating the median of three equal values, reducing performance slightly. Performance for arrays of random values is improved to a lesser extent through the pivot being slightly more likely to be closer to optimal, given the first, middle, and last elements are not all equal to the minimum or maximum of the array.

The final variation used the Hoare partitioning algorithm instead of the Lomuto algorithm used in the other variations. Hoare's partitioning algorithm is one of the most well-known and commonly studied (although not generally used in practice; instead, a variation of a three-way partitioning algorithm is typically used). This partitioning scheme uses two iterators to swap each pair of out-of-place elements rather than moving each out-of-place element individually as it is found. As is evident from the data above, this results in a slight performance improvement when sorting arrays of random integers. 

However, Hoare partitioning mainly prevails over Lomuto with arrays of sorted integers or many duplicates. Looking at the implementation of a Hoare partition in quicksort.cpp, while iterator i is less than iterator j, the value at i is always less than the pivot, and the value at j is always greater than the pivot; thus, no swaps are made. In contrast, looking at the implementation of a Lomuto partition, a swap is made whenever the value at iterator j is less than or equal to the value at iterator begin (the pivot), which is true for every value in the second half of the array. Thus, a Lomuto partition algorithm still makes n/2 swaps on a sorted array, significantly reducing performance.

Furthermore, in the implementation of a Hoare partition, a swap is made whenever the value at iterator i is greater than the pivot, the value at iterator j is less than or equal to the pivot, and i is less than j. This predicate is never true for an array of all a single value, and i will reach j before finding a value greater than the pivot, making no swaps. On the contrary, with the Lomuto partition, the condition to swap, *j <= *begin, will be true for every element in the array, in addition to the returned pivot iterator being the end of the array, resulting in time complexity depreciating to O(n^2).
