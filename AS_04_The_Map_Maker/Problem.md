### Programming Assignment #4
# The Map Maker

## Problem Description
You are an apprentice in map planning. To reduce the workload of your master, you
decide to automate the planning process using your algorithm knowledge and coding
skills.

After organizing the maps, you find that the maps are from four different locations
and have different goals. The locations and goals are listed below:

β’ Maps of Los Santos
The maps consist of |π| buildings and |πΈ| transportation routes. Each route
πΈπ represents a method to travel from building ππ
to ππ
in exactly π‘π
minutes. Given a safe house π0, Trevor, a successful dealer, demands you to
calculate how fast one can travel to π0 starting from each building.

β’ Maps of Portal Chambers
The maps consist of |π| chambers and |πΈ| teleportation routes. One can
travel to other chambers by teleporting through portals. Each teleportation
route πΈπ travels from chamber ππ
to ππ with time difference π‘π. Some π‘π
may be negative numbers indicating traveling back in time due to the side
effect of the portal. However, there isnβt a sequence of teleportation routes that
allows one to keep going back in time. Chell, a young researcher, needs your
help to calculate the minimum amount of time to travel from any chamber ππ
back to that same chamber through multiple teleportations.

β’ Maps of Skyrim
The maps consist of |π| inns and |πΈ| transportation paths. Each path πΈπ
represents a way to travel from inn ππ
to ππ
that uses up ππ pounds of meat.
However, there are a variety of animals when traveling through the routes, we
can gain ππ pounds of meat by hunting animals when traveling through each
route πΈπ. π‘π is defined to be ππ β ππ for ease of calculation. Aela, a skillful
huntress, wants you to calculate whether the map contains a sequence of
routes that can keep accumulating meat by hunting animals, assuming that one
can always acquire the same amount of meat even when walking through a
same path the second time.

β’ Maps of Blight Town (Bonus)
The maps consist of |π| drylands and |πΈ| routes. Each route πΈπ represents
a way to travel from dryland ππ
to ππ
, while π‘π indicates whether the route
requires one to walk through the poisonous swamp. Since different warriors
have different poison resistance and each map has a different kind of poison,
the condition for the warrior to be poisoned varies. If there are π + 1 routes
in the π recent chosen routes that require walking through the poisonous
swamp, the warrior will be poisoned and requires special treatment. Solaire, a
kind warrior, asks you to calculate whether there exists a route for one to
travel from π0 to π|π|β1 without getting poisoned.

Hints:
β’ Being able to travel from ππ
to ππ doesnβt mean one can travel back (ππ
to
ππ
) using the same route. For example, there may be one-way busses in Los
Santos and border controls in Skyrim.
β’ The request of the first three maps (Los Santos, Portal Chambers, Skyrim) can
be solved through basic algorithms learned in class. The last map (Blight
Town) can be optimized through various techniques.

## I/O Format
Use standard I/O. (stdin, stdout)
### <b>Input</b>

The first line contains one integer π (1 β€ π β€ 10), representing the number of test
cases π. Then π test cases follow.

For the first line of each test case, there are 3 positive integers πΎ, π, πΈ. πΎ represents
the map kind, 1 for Los Santos, 2 for Portal Chambers, 3 for Skyrim, and 4 for
Blight Town. π and πΈ is the |π| and |πΈ| in the problem description.

If πΎ = 4, there are an additional line with 2 integers π, π.

Then there are πΈ lines, the π
π‘β
line have 3 integers π,π,π‘π, representing the route
ππ
to ππ with parameter π‘π. The meaning of π‘π depends on the problem description.

## <b>Output</b>
For each test case π, output the required result:

β’ For Maps of Los Santos (πΎ = 1)
Output the shortest path for ππ
to π0 for π = 0, 1, β¦ |V| β 1. (output INF if
there are no path from ππ
to π0)

β’ For Maps of Portal Chambers (πΎ = 2)
Output the shortest loop for ππ
to ππ
for π = 0, 1, β¦ |V| β 1. (output INF if
there are no loop from ππ
to ππ
)

β’ For Maps of Skyrim (πΎ = 3)
Output whether there is a special route sequence. (output TRUE or FALSE)

β’ For Maps of Blight Town (πΎ = 4)
Output whether there is a route from π0 to π|π|β1 without getting poisoned.
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

