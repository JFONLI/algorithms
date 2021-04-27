### Programming Assignment #4
# The Map Maker

## Problem Description
You are an apprentice in map planning. To reduce the workload of your master, you
decide to automate the planning process using your algorithm knowledge and coding
skills.

After organizing the maps, you find that the maps are from four different locations
and have different goals. The locations and goals are listed below:

• Maps of Los Santos
The maps consist of |𝑉| buildings and |𝐸| transportation routes. Each route
𝐸𝑘 represents a method to travel from building 𝑉𝑖
to 𝑉𝑗
in exactly 𝑡𝑘
minutes. Given a safe house 𝑉0, Trevor, a successful dealer, demands you to
calculate how fast one can travel to 𝑉0 starting from each building.

• Maps of Portal Chambers
The maps consist of |𝑉| chambers and |𝐸| teleportation routes. One can
travel to other chambers by teleporting through portals. Each teleportation
route 𝐸𝑘 travels from chamber 𝑉𝑖
to 𝑉𝑗 with time difference 𝑡𝑘. Some 𝑡𝑘
may be negative numbers indicating traveling back in time due to the side
effect of the portal. However, there isn’t a sequence of teleportation routes that
allows one to keep going back in time. Chell, a young researcher, needs your
help to calculate the minimum amount of time to travel from any chamber 𝑉𝑖
back to that same chamber through multiple teleportations.

• Maps of Skyrim
The maps consist of |𝑉| inns and |𝐸| transportation paths. Each path 𝐸𝑘
represents a way to travel from inn 𝑉𝑖
to 𝑉𝑗
that uses up 𝑓𝑘 pounds of meat.
However, there are a variety of animals when traveling through the routes, we
can gain 𝑔𝑘 pounds of meat by hunting animals when traveling through each
route 𝐸𝑘. 𝑡𝑘 is defined to be 𝑔𝑘 − 𝑓𝑘 for ease of calculation. Aela, a skillful
huntress, wants you to calculate whether the map contains a sequence of
routes that can keep accumulating meat by hunting animals, assuming that one
can always acquire the same amount of meat even when walking through a
same path the second time.

• Maps of Blight Town (Bonus)
The maps consist of |𝑉| drylands and |𝐸| routes. Each route 𝐸𝑘 represents
a way to travel from dryland 𝑉𝑖
to 𝑉𝑗
, while 𝑡𝑘 indicates whether the route
requires one to walk through the poisonous swamp. Since different warriors
have different poison resistance and each map has a different kind of poison,
the condition for the warrior to be poisoned varies. If there are 𝑚 + 1 routes
in the 𝑛 recent chosen routes that require walking through the poisonous
swamp, the warrior will be poisoned and requires special treatment. Solaire, a
kind warrior, asks you to calculate whether there exists a route for one to
travel from 𝑉0 to 𝑉|𝑉|−1 without getting poisoned.

Hints:
• Being able to travel from 𝑉𝑖
to 𝑉𝑗 doesn’t mean one can travel back (𝑉𝑗
to
𝑉𝑖
) using the same route. For example, there may be one-way busses in Los
Santos and border controls in Skyrim.
• The request of the first three maps (Los Santos, Portal Chambers, Skyrim) can
be solved through basic algorithms learned in class. The last map (Blight
Town) can be optimized through various techniques.

## I/O Format
Use standard I/O. (stdin, stdout)
### <b>Input</b>

The first line contains one integer 𝑇 (1 ≤ 𝑇 ≤ 10), representing the number of test
cases 𝑇. Then 𝑇 test cases follow.

For the first line of each test case, there are 3 positive integers 𝐾, 𝑉, 𝐸. 𝐾 represents
the map kind, 1 for Los Santos, 2 for Portal Chambers, 3 for Skyrim, and 4 for
Blight Town. 𝑉 and 𝐸 is the |𝑉| and |𝐸| in the problem description.

If 𝐾 = 4, there are an additional line with 2 integers 𝑛, 𝑚.

Then there are 𝐸 lines, the 𝑘
𝑡ℎ
line have 3 integers 𝑖,𝑗,𝑡𝑘, representing the route
𝑉𝑖
to 𝑉𝑗 with parameter 𝑡𝑘. The meaning of 𝑡𝑘 depends on the problem description.

## <b>Output</b>
For each test case 𝑇, output the required result:

• For Maps of Los Santos (𝐾 = 1)
Output the shortest path for 𝑉𝑖
to 𝑉0 for 𝑖 = 0, 1, … |V| − 1. (output INF if
there are no path from 𝑉𝑖
to 𝑉0)

• For Maps of Portal Chambers (𝐾 = 2)
Output the shortest loop for 𝑉𝑖
to 𝑉𝑖
for 𝑖 = 0, 1, … |V| − 1. (output INF if
there are no loop from 𝑉𝑖
to 𝑉𝑖
)

• For Maps of Skyrim (𝐾 = 3)
Output whether there is a special route sequence. (output TRUE or FALSE)

• For Maps of Blight Town (𝐾 = 4)
Output whether there is a route from 𝑉0 to 𝑉|𝑉|−1 without getting poisoned.
(output TRUE or FALSE)

#### <b>Examples</b>
Input 1<br>
1<br>
1 5 5<br>
0 2 10<br>
1 0 1<br>
3 0 3<br>
3 1 1<br>
4 0 2<br>

Output 1<br>
0<br>
1<br>
INF<br>
2<br>
2<br>

Input 2<br>
1<br>
2 3 6<br>
0 1 2<br>
0 2 5<br>
1 0 8<br>
1 2 10<br>
2 0 2<br>
2 1 -8<br>

Output 2<br>
5<br>
2<br>
2<br>

Input 3<br>
1<br>
3 3 3<br>
0 1 -4<br>
1 2 -2<br>
2 0 7<br>

Output 3<br>
TRUE<br>

Input 4<br>
1<br>
4 5 6<br>
3 2<br>
0 1 1<br>
1 2 0<br>
1 3 1<br>
2 1 0<br>
2 3 1<br>
3 4 1<br>

Output 4<br>
TRUE<br>

